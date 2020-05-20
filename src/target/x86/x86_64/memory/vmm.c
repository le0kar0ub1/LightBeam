#include "target/x86/x86_64/memory/vmm.h"
#include "target/x86/common/memory/kalloc.h"

/*
** If there is no recursive mapping all these functions will fucked up.
** Assuming that's not the case.
** This functions are usable only in this file.
*/

static inline struct pml4_t *get_pml4(void)
{
    return (
        (struct pml4_t *)0xfffffffff000ul
    );
}

static inline struct pdp_t *get_pdp(uint pml4idx)
{
    return (
        (struct pdp_t *)(0xffffffE00000ul |
        ((pml4idx & 0x1FF) << 30)
    ));
}

static inline struct pd_t *get_pd(uint pml4idx, uint pdpidx)
{
    return (
        (struct pd_t *)(0xffffC0000000ul |
        ((pml4idx & 0x1FF) << 30)        |
        ((pdpidx & 0x1FF) << 21)
    ));
}

static inline struct pt_t *get_pt(uint pml4idx, uint pdpidx, uint pdidx)
{
    return (
        (struct pt_t *)(0xff8000000000ul |
        ((pml4idx & 0x1FF) << 30)        |
        ((pdpidx & 0x1FF) << 21)         |
        ((pdidx & 0x1FF) << 12)
    ));
}

/*
** Idx/addr pagination get
*/

static inline uint virt2pml4Idx(virtaddr_t va)
{
    return (((uintptr)(va) >> 39) & 0x1FF);
}

static inline uint virt2pdpIdx(virtaddr_t va)
{
    return (((uintptr)(va) >> 30) & 0x1FF);
}

static inline uint virt2pdIdx(virtaddr_t va)
{
    return (((uintptr)(va) >> 21) & 0x1FF);
}

static inline uint virt2ptIdx(virtaddr_t va)
{
    return (((uintptr)(va) >> 12) & 0x1FF);
}

static inline virtaddr_t idx2addr(uint pml4idx, uint pdpidx, uint pdidx, uint ptidx)
{
    return ((virtaddr_t)(
        ((uintptr)pml4idx << 39) |
        ((uintptr)pdpidx  << 30) |
        ((uintptr)pdidx   << 21) |
        ((uintptr)ptidx   << 12)
    ));
}

/*
** x86_64 particular vmm functions management
*/

bool arch_vmm_is_mapped(virtaddr_t virt)
{
    assert(IS_PAGE_ALIGNED(virt));
    if (
        !get_pml4()->entries[virt2pml4Idx(virt)].present ||
        !get_pdp(virt2pml4Idx(virt))->entries[virt2pdpIdx(virt)].present ||
        !get_pd(virt2pml4Idx(virt), virt2pdpIdx(virt))->entries[virt2pdIdx(virt)].present
    )
        return (false);
    return (
        get_pt(virt2pml4Idx(virt), virt2pdpIdx(virt), virt2pdIdx(virt))->entries[virt2ptIdx(virt)].present
    );
}

physaddr_t arch_vmm_get_mapped_frame(virtaddr_t virt)
{
    assert(IS_PAGE_ALIGNED(virt));
    if (
        !get_pml4()->entries[virt2pml4Idx(virt)].present ||
        !get_pdp(virt2pml4Idx(virt))->entries[virt2pdpIdx(virt)].present ||
        !get_pd(virt2pml4Idx(virt), virt2pdpIdx(virt))->entries[virt2pdIdx(virt)].present
    )
        return (0x0);
    return (
        get_pt(virt2pml4Idx(virt), virt2pdpIdx(virt), virt2pdIdx(virt))->entries[virt2ptIdx(virt)].frame << 0xC
    );
}

mmstatus_t arch_vmm_map_phys(virtaddr_t virt, physaddr_t phys, mmap_attrib_t attrib)
{
    struct pml4_entry_t *pml4e;
    struct pdp_entry_t *pdpe;
    struct pd_entry_t *pde;
    struct pt_entry_t *pte;
    struct pdp_t *pdp;
    struct pd_t *pd;
    struct pt_t *pt;

    assert(IS_PAGE_ALIGNED(virt));
    assert(IS_PAGE_ALIGNED(phys));

    pml4e = &(get_pml4()->entries[virt2pml4Idx(virt)]);
    pdp = get_pdp(virt2pml4Idx(virt));
    if (!pml4e->present) {
        pml4e->value = pmm_alloc_frame();
        pml4e->present = true;
        pml4e->user = true;
        pml4e->rw = true;
        pml4e->accessed = false;
        invlpg(pdp);
        memset(pdp, 0x0, KCONFIG_MMU_PAGESIZE);
    }

    pdpe = &(pdp->entries[virt2pdpIdx(virt)]);
    pd = get_pd(virt2pml4Idx(virt), virt2pdpIdx(virt));
    if (!pdpe->present) {
        pdpe->value = pmm_alloc_frame();
        pdpe->present = true;
        pdpe->user = true;
        pdpe->rw = true;
        pdpe->accessed = false;
        invlpg(pd);
        memset(pd, 0x0, KCONFIG_MMU_PAGESIZE);
    }

    pde = &(pd->entries[virt2pdIdx(virt)]);
    pt = get_pt(virt2pml4Idx(virt), virt2pdpIdx(virt), virt2ptIdx(virt));
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
            pmm_free_frame(pte->frame << 0xC);
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
    struct pml4_entry_t *pml4e;
    struct pdp_entry_t *pdpe;
    struct pd_entry_t *pde;
    struct pt_entry_t *pte;

    pml4e = &(get_pml4()->entries[virt2pml4Idx(virt)]);
    if (!pml4e->present) 
        return;
    pdpe = &(get_pdp(virt2pml4Idx(virt))->entries[virt2pdpIdx(virt)]);
    if (!pdpe->present)
        return;
    pde = &(get_pd(virt2pml4Idx(virt), virt2pdpIdx(virt))->entries[virt2pdIdx(virt)]);
    if (!pde->present)
        return;
    pte = &(get_pt(virt2pml4Idx(virt), virt2pdpIdx(virt), virt2pdIdx(virt))->entries[virt2ptIdx(virt)]);
    if (pte->present) {
        if (!MASK_MUNMAP_DONTFREE(attrib)) 
            pmm_free_frame(pte->frame << 0xC);
        invlpg(virt);
        pte->value = 0x0;
    }
}

void arch_vmm_init(void)
{
    /*
    ** For the kheap consistancy we must unmap all page behind the kernel
    */
    vmm_unmap(
        ADD_TO_PTR(&__KERNEL_VIRT_END, KCONFIG_MMU_PAGESIZE),
        (512 - virt2ptIdx(&__KERNEL_VIRT_END) - 1) * KCONFIG_MMU_PAGESIZE,
        MUNMAP_DONTFREE
    );
    /*
    ** Init the kernel allocator & the kernel VMM
    */
    vmm_init();

    /*
    ** Allocate all the kernel page directory entries 
    */
    // struct page_dir_t *pd = get_pagedir();
    // virtaddr_t allocated;
    // u32_t entry = virt2pdIdx(&__KERNEL_ADDR_TRNS);
    // while (entry < 0x400)
    // {
    //     if (!pd->entries[entry].present)
    //     {
    //         allocated = kalloc_aligned(KCONFIG_MMU_PAGESIZE, KCONFIG_MMU_PAGESIZE);
    //         assert(allocated);
    //         memset(allocated, 0x0, KCONFIG_MMU_PAGESIZE);
    //         pd->entries[entry].value = (uintptr)allocated;
    //         pd->entries[entry].present = true;
    //         pd->entries[entry].rw = true;
    //         invlpg(get_pagetable(entry));
    //     }
    //     entry++;
    // }
}

/*
** VMM can't be initcall()
** The PMM is handle by a boot_initcall() and is totaly shared
*/