#include "target/x86/i386/memory/vmm.h"
#include "target/x86/common/memory/kalloc.h"

/*
** If there is no recursive mapping all these functions will fucked up.
** Assuming that's not the case.
** This functions are usable only in this file.
*/

static inline struct page_dir *get_pagedir(void)
{
    return ((struct page_dir *)0xFFFFF000ul);
}

static inline struct page_table *get_pagetable(uint x)
{
    return ((struct page_table *)(0xFFC00000ul | (((x) & 0x3FF) << 12u)));
}

/*
** Idx/addr pagination get
*/

static inline uint virt2pdIdx(virtaddr_t va)
{
    return ((uintptr)va >> 22u);
}

static inline uint virt2ptIdx(virtaddr_t va)
{
    return (((uintptr)(va) >> 12u) & 0x3FF);
}

static inline virtaddr_t idx2addr(uint pdidx, uint ptidx)
{
    return ((virtaddr_t)((pdidx) << 22u | (ptidx) << 12u));
}

/*
** i386 particular vmm functions management
*/

bool arch_vmm_is_mapped(virtaddr_t virt)
{
    assert(IS_PAGE_ALIGNED(virt));
    if (!get_pagedir()->entries[virt2pdIdx(virt)].present)
        return (false);
    return (get_pagetable(virt2pdIdx(virt))->entries[virt2ptIdx(virt)].present);
}

physaddr_t arch_vmm_get_mapped_frame(virtaddr_t virt)
{
    assert(IS_PAGE_ALIGNED(virt));
    if (!get_pagedir()->entries[virt2pdIdx(virt)].present)
        return (0x0);
    return (get_pagetable(virt2pdIdx(virt))->entries[virt2ptIdx(virt)].frame << 0xC);
}

mmstatus_t arch_vmm_map_phys(virtaddr_t virt, physaddr_t phys, mmap_attrib_t attrib)
{
    struct pagedir_entry *pde;
    struct pagetable_entry *pte;
    struct page_table *pt;

    assert(IS_PAGE_ALIGNED(virt));
    assert(IS_PAGE_ALIGNED(phys));
    pde = &(get_pagedir()->entries[virt2pdIdx(virt)]);
    pt = get_pagetable(virt2pdIdx(virt));
    if (!pde->present) {
        pde->value = pmm_alloc_frame();
        pde->present = true;
        pde->user = true;
        pde->rw = true;
        pde->accessed = false;
        invlpg(pt);
        memset(pt, 0x0, KCONFIG_MMU_PAGESIZE);
    }
    pte = &(pt->entries[virt2ptIdx(virt)]);
    if (pte->present) {
        if (pte->frame && MASK_MMAP_REMAP(attrib))
            pmm_free_frame(pte->frame);
        else
            return (VMM_ALREADY_MAPPED);
    }
    pte->value = phys;
    pte->present = true;
    pte->rw = MASK_MMAP_WRITE(attrib);
    pte->user = MASK_MMAP_USER(attrib);
    pte->accessed = false;
    pte->dirty = 0x0;
    invlpg(virt);
    return (VMM_SUCCESS);
}

mmstatus_t arch_vmm_map_virt(virtaddr_t virt, mmap_attrib_t attrib)
{
    assert(IS_PAGE_ALIGNED(virt));
    physaddr_t phys = pmm_alloc_frame();
    mmstatus_t status;
    if (!phys)
        return (PMM_OUT_OF_MEM);
    status = arch_vmm_map_phys(virt, phys, attrib);
    if (status != VMM_SUCCESS)
        pmm_free_frame(phys);
    return (status);
}

void arch_vmm_unmap(virtaddr_t virt, munmap_attrib_t attrib)
{
    assert(IS_PAGE_ALIGNED(virt));
    struct pagedir_entry *pde;
    struct pagetable_entry *pte;

    pde = &(get_pagedir()->entries[virt2pdIdx(virt)]);
    if (pde->present) {
        pte = &(get_pagetable(virt2pdIdx(virt))->entries[virt2ptIdx(virt)]);
        if (pte->present) {
            if (!MASK_MUNMAP_DONTFREE(attrib))
                pmm_free_frame(pte->frame << 0xC);
            invlpg(virt);
            pte->value = 0x0;
        }
    }
}

static void arch_vmm_init(void)
{
    /*
    ** For the kheap consistancy we must unmap all page behind the kernel
    */
    vmm_unmap(
        ADD_TO_PTR(&__KERNEL_VIRT_END, KCONFIG_MMU_PAGESIZE),
        (1024 - virt2ptIdx(&__KERNEL_VIRT_END) - 1) * KCONFIG_MMU_PAGESIZE,
        MUNMAP_DONTFREE
    );

    /*
    ** Init the kernel allocator & the kernel VMM
    */
    vmm_init();

    /*
    ** Allocate all the kernel page directory entries 
    */
    struct page_dir *pd = get_pagedir();
    virtaddr_t allocated;
    u32_t entry = virt2pdIdx(&__KERNEL_ADDR_TRNS);
    while (entry < 0x400)
    {
        if (!pd->entries[entry].present)
        {
            allocated = kalloc_aligned(KCONFIG_MMU_PAGESIZE, KCONFIG_MMU_PAGESIZE);
            assert(allocated);
            memset(allocated, 0x0, KCONFIG_MMU_PAGESIZE);
            pd->entries[entry].value = (uintptr)allocated;
            pd->entries[entry].present = true;
            pd->entries[entry].rw = true;
            invlpg(get_pagetable(entry));
        }
        entry++;
    }
}

boot_initcall(arch_vmm_init);