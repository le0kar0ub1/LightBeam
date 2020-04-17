#include "target/x86/common/memory/vmm.h"

/*
** Common VMM functions
*/

virtaddr_t vmm_mmap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib)
{
    virtaddr_t keep = virt;

    assert(IS_PAGE_ALIGNED(virt));
    assert(IS_PAGE_ALIGNED(sz));

    while ((uintptr)virt < (uintptr)ADD_TO_PTR(keep, sz))
    {
        if (!arch_vmm_map_virt(virt, attrib))
            return (NULL);
        virt = ADD_TO_PTR(virt, sz);
    }
    return (virt);
}

void vmm_ummap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib)
{
    virtaddr_t keep = virt;

    assert(IS_PAGE_ALIGNED(virt));
    assert(IS_PAGE_ALIGNED(sz));

    while ((uintptr)virt < (uintptr)ADD_TO_PTR(keep, sz))
    {
        arch_vmm_unmap(virt, attrib);
        virt = ADD_TO_PTR(virt, sz);
    }
}

bool vmm_is_mapped(virtaddr_t virt)
{
    return (arch_vmm_is_mapped(virt));
}

void vmm_init(void)
{

}