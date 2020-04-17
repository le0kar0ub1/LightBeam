#include "target/x86/i386/memory/vmm.h"

/*
** If there is no recursive mapping all these functions will fucked up.
** All of them assumed that's not the case.
** This functions are usable only in this file.
*/

static inline struct page_dir * get_pagedir(void)
{
    return ((struct page_dir *)0xFFFFF000ul);
}

static inline struct page_table * get_pagetable(uint x)
{
    return ((struct page_table *)(0xFFC00000ul | (((x) & 0x3FF) << 12u)));
}

static inline uint get_pd_idx(virtaddr_t va)
{
    return ((uintptr)va >> 22u);
}

static inline uint get_pt_idx(virtaddr_t va)
{
    return (((uintptr)(va) >> 12u) & 0x3FF);
}

static inline virtaddr_t get_virtaddr(uint pdidx, uint ptidx)
{
    return ((virtaddr_t)((pdidx) << 22u | (ptidx) << 12u));
}

/*
** i386 particular vmm functions management
*/

bool arch_vmm_is_mapped(virtaddr_t virt)
{
    assert(IS_PAGE_ALIGNED(virt));
    if (!get_pagedir()->entries[get_pd_idx(virt)].present)
        return (false);
    return (get_pagetable(get_pd_idx(virt))->entries[get_pt_idx(virt)].present);
}

physaddr_t arch_vmm_get_mapped_frame(virtaddr_t virt)
{
    assert(IS_PAGE_ALIGNED(virt));
    if (!get_pagedir()->entries[get_pd_idx(virt)].present)
        return (0x0);
    return (get_pagetable(get_pd_idx(virt))->entries[get_pt_idx(virt)].frame << 0xC);
}

