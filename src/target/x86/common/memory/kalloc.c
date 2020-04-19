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
static virtaddr_t kheap_end   = (virtaddr_t)KHEAP_START;;

/*
** The first & last block ouf our list
*/
static block_t *fstblk = NULL;
static block_t *lstblk = NULL;

/*
** Dump ou kheap
*/

void kalloc_dump(void)
{
    block_t *blk = fstblk;

    while (blk && blk <= lstblk)
    {
        serial_printf("Block at %#X:\n    size: %#x\n    %s\n",
                       (uintptr)blk,
                       BLK_GETSZ(blk),
                       BLK_GETSZ(blk) > 0 ? "used" : "unused");
        blk = BLK_NEXT(blk);
    }
}

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
    if ((uintptr)newblk + size + sizeof(block_t) > (uintptr)kheap_end)
    {
        if (!vmm_mmap(kheap_end, ALIGN_PAGE(size), MMAP_WRITE))
            PANIC("Kalloc can't extend the heap");
        kheap_end = ADD_TO_PTR(kheap_end, ALIGN_PAGE(size));
    }
    newblk->attrib = size;
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
    #pragma message "im not free-able"

    /*
    ** Case of god is with us and the address is already aligned
    */
    if (IS_ALIGNED(ADD_TO_PTR(BLK_NEXT(lstblk), sizeof(block_t)), align))
        return (kalloc(size));
    else
        addr = kalloc(size + align);
    if (!addr)
        return (NULL);
    return ((virtaddr_t)ALIGN(addr, align));
}

void kalloc_init(void)
{
    assert(IS_PAGE_ALIGNED(kheap_start));
    /*
    ** map the first page of the heap
    */
    assert(vmm_mmap(kheap_end, KCONFIG_MMU_PAGESIZE, MMAP_WRITE));
    kheap_end = ADD_TO_PTR(kheap_end, KCONFIG_MMU_PAGESIZE);
    /* 
    ** This is a Dirty initialization without any consequences
    ** We mark a first block free block with a total of (0x1000 - (block_size * 2))
    ** The first allocation in init is a page aligned on PAGE, so we finaly lose no memory on alignement
    */
    fstblk = (block_t *)kheap_start;
    lstblk = (block_t *)kheap_start;
    fstblk->attrib = -(0x1000 - (sizeof(block_t) * 2));
    kalloc_aligned(KCONFIG_MMU_PAGESIZE, KCONFIG_MMU_PAGESIZE);
}

/*
** Can't be a boot_initcall()
** we are using a function unavailable before the VMM initcall 
*/