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
static virtaddr_t kheap_end   = (virtaddr_t)KHEAP_START;

/*
** The first & last block ouf our list
*/
static block_t *fstblk = (block_t *)KHEAP_START;
static block_t *lstblk = (block_t *)KHEAP_START;

/*
** Dump the kheap
*/
void kalloc_dump(void)
{
    block_t *blk = fstblk;

    while (blk && blk <= lstblk)
    {
        serial_printf("Block at %#X:\n    size: %#X\n    %s\n",
                       (uintptr)blk,
                       BLK_GETSZ(blk),
                       BLK_ISUSED(blk) ? "used" : "unused");
        blk = BLK_NEXT(blk);
    }
}

/*
** Divide one Block into two
** The first block take the given size
** Assuming the spinlock locked
** Returning the new block
*/
static block_t *divide_block(block_t *blk, size_t fsz)
{
    block_t *new;

    assert(blk);
    if (BLK_GETSZ(blk) < sizeof(block_t) + fsz)
        return (NULL);
    new = (block_t *)(((uintptr)(blk + 1)) + fsz);
    new->attrib = BLK_GETSZ(blk) - fsz - sizeof(block_t) * 2;
    blk->attrib = fsz;
    if (blk == lstblk)
        lstblk = new;
    return (new);
}

/*
** Merge the next X free block into one
** Assuming the spinlock locked
*/
static void merge_next_blocks(block_t *blk)
{
    block_t *last = blk;

    while (!BLK_ISUSED(last))
    {
        last = BLK_NEXT(last);
    }
    blk->attrib = (uintptr)last - (uintptr)blk - sizeof(block_t);
    if (last == lstblk)
        lstblk = blk;
}

/*
** Is there a free block ?
*/
static block_t *get_free_block(size_t size)
{
    block_t *blk = fstblk;

    while (blk && blk <= lstblk)
    {
        if (BLK_GETSZ(blk) >= size && !BLK_ISUSED(blk))
            return (blk);
        blk = (block_t *)BLK_NEXT(blk);
    }
    return (NULL);
}

/*
** Extend the size of our heap by one block
*/
static block_t *extend_kheap(size_t size)
{
    lstblk = (block_t *)BLK_NEXT(lstblk);
    /*
    ** Case we are at the end of the mapped memory
    ** We ask a new page map and increase the kheap size
    */
    if ((uintptr)lstblk + size + sizeof(block_t) > (uintptr)kheap_end)
    {
        if (!vmm_mmap(kheap_end, ALIGN_PAGE(size), MMAP_WRITE))
            PANIC("Kalloc can't extend the heap");
        kheap_end = ADD_TO_PTR(kheap_end, ALIGN_PAGE(size));
    }
    lstblk->attrib = size;
    return (lstblk);
}

static virtaddr_t __kalloc(size_t size, kallocattrib_t flag)
{
    block_t *block = NULL;

    if (!size)
        return (NULL);
    // smp_inc(&lock);
    size = KHEAP_ALIGN(size);
    if (!(flag & KALLOC_FORCE_ALLOC))
        block = get_free_block(size);
    if (block)
        block->attrib *= 1;
    else
        block = extend_kheap(size);
    // smp_dec(&lock);
    if (block->attrib == (int)-1) {
        serial_printf("SIZE %x\n", block->attrib);
        kalloc_dump();
        block->attrib = size;
    }
    serial_printf("SIZE %x\n", block->attrib);
    serial_printf("SIZE %x\n", block->attrib);
    //serial_printf("SIZE %x\n", block->attrib);
    //serial_printf("SIZE %x\n", block->attrib);
    return (BLK2ADDR(block));
}

/*
** Our main kernel allocator function
** The returned pointer is obviously system aligned 
*/
virtaddr_t kalloc(size_t size)
{
    return (__kalloc(size, KALLOC_DEFAULT));
}

/*
** Force the allocation to be a heap extend
*/
virtaddr_t kalloc_force_alloc(size_t size)
{
    return (__kalloc(size, KALLOC_FORCE_ALLOC));
}

/*
** Ugly implementation so far
** Used mostly to produce PAGE ALIGNED allocation
*/
virtaddr_t kalloc_aligned(size_t size, u32_t align)
{
    virtaddr_t addr;
    virtaddr_t endAddr = ADD_TO_PTR(BLK_NEXT(lstblk), sizeof(block_t));
    block_t *div;

    /*
    ** Case of god is with us and the address is already aligned
    ** We force the allocation to ensure we don't take an unaligned free one
    */
    if (IS_ALIGNED(endAddr, align))
    {
        addr = kalloc_force_alloc(size);
        assert(addr == endAddr);
        assert(IS_ALIGNED(addr, align));
        return (addr);
    }
    /*
    ** Else we will do an illegal thing
    */
    addr = kalloc(size + align);
    serial_printf("ALLOC %X size AT %X\n", BLK_GETSZ(ADDR2BLK(addr)), addr);
    div = divide_block(
        ADDR2BLK(addr), 
        (uintptr)ALIGN(addr, align) - (uintptr)addr - sizeof(block_t)
    );
    assert(div);
    (ADDR2BLK(addr))->attrib *= -1;
    addr = BLK2ADDR(div);
    assert(IS_ALIGNED(addr, align));
    return (addr);
}

/*
** Our kernel heap free function
** We actually consider that the given pointer is at the start address
** If this is not the case:
**    either the block will not be free without error
**    or we will maybe fucked up another control block
*/
void kfree(virtaddr_t virt)
{
    block_t *blk = (block_t *)virt;

    assert(blk);
    smp_inc(&lock);
    blk->attrib *= -1;
    smp_dec(&lock);
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
    ** We mark a first block as free with a total of (0x1000 - (block_size * 2))
    ** The first allocation in init is page aligned, so we finaly lose no memory on alignement
    */
    fstblk->attrib = -(0x1000 - (sizeof(block_t) * 2));
}

/*
** Can't be a boot_initcall()
** we are using a function unavailable before the VMM initcall 
*/