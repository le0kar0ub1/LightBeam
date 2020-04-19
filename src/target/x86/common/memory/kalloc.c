#include "target/x86/common/memory/kalloc.h"

/*
** A totaly overflow sensitive Kernel allocator, will improve this later
** Remember that if we overtake the allocated size, we will fucked up the allocator and the kernel btw
** Also assuming that the kheap is fully continuous (not dumb)
*/

static smplock_t lock = SMPLOCK_INIT();

/* 
** The beginning and the actual size of our kheap wich his behind the kernel
*/
static virtaddr_t kheap_start = (virtaddr_t)KHEAP_START;
static size_t     kheap_size  = 0x0;

/*
** The first & last block ouf our list
*/
static block_t *fstblk = NULL;
static block_t *lstblk = NULL;

/*
** Is there a free block ?
*/
static block_t *get_free_block(size_t size)
{
    block_t *blk = fstblk;

    while (blk && blk <= lstblk)
    {
        if (BLK_GETSZ(blk) >= (int)size)
            return (blk);
        blk = (block_t *)BLK_NEXT(blk);
    }
    return (NULL);
}

static block_t *extend_kheap(size_t size)
{
    block_t *newblk = (block_t *)BLK_NEXT(lstblk);
    /*
    ** Case we are at the end of the mapped memory
    ** We ask a new page map and increase the kheap size
    */
    serial_printf("size increased %x\n", ALIGN_PAGE(size));
    if ((uintptr)newblk + size + sizeof(block_t) > kheap_size)
    {
        if (!vmm_mmap(ADD_TO_PTR(kheap_start, kheap_size), ALIGN_PAGE(size), MMAP_WRITE))
            PANIC("Kalloc can't extend the heap");
        kheap_size += ALIGN_PAGE(size);
    }
    lstblk = newblk;
    return (newblk);
}

/*
** Our main kernel allocator function
** The returned pointer is obviously system aligned 
*/

virtaddr_t kalloc(size_t size)
{
    block_t *block;

    if (!size)
        return (NULL);
    smp_inc(&lock);
    size = KHEAP_ALIGN(size);
    block = get_free_block(size);
    if (block)
        block->attrib *= -1;
    else
        block = extend_kheap(size);
    smp_dec(&lock);
    return ((virtaddr_t)(block + 1));
}

/*
** Ugly implementation so far, we use really a lot of memory
*/

virtaddr_t kalloc_aligned(size_t size, u32_t align)
{
    virtaddr_t addr;

    addr = kalloc(size + align);
    if (!addr)
        return (NULL);
    if (IS_ALIGNED(addr, align))
        return (addr);
    addr = (virtaddr_t)ALIGN(addr, align);
    return (addr);
}

void kalloc_init(void)
{
    assert(IS_PAGE_ALIGNED(kheap_start));
    /*
    ** map the first page of the heap
    */
    assert(vmm_mmap(kheap_start, KCONFIG_MMU_PAGESIZE, MMAP_WRITE));
    kheap_size = KCONFIG_MMU_PAGESIZE;
    /* 
    ** This is a Dirty initialization
    ** We mark a first block free block with random shitty size
    */
    fstblk = (block_t *)kheap_start;
    lstblk = (block_t *)kheap_start;
    fstblk->attrib = -60;
}

/*
** Can't be a boot_initcall()
** we are using a function unavailable before the VMM initcall 
*/