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

/*
** VMM can't be initcall()
** The PMM is handle by a boot_initcall() and is totaly shared
*/