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
        // if (!vmm_arch_mmap(virt, NULL, attrib))
        //     return (NULL);
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
        // if (!vmm_arch_unmmap(virt, attrib))
        //     return (NULL);
        virt = ADD_TO_PTR(virt, sz);
    }
}

physaddr_t vmm_get_mapped_frame(virtaddr_t virt)
{
    return (arch_vmm_get_mapped_frame(virt));
}