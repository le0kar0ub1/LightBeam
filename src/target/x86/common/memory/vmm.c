#include "target/x86/common/memory/vmm.h"
#include "target/x86/common/memory/kalloc.h"

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
        if (arch_vmm_map_virt(virt, attrib) != VMM_SUCCESS)
            return (NULL);
        virt = ADD_TO_PTR(virt, KCONFIG_MMU_PAGESIZE);
    }
    return (virt);
}

void vmm_unmap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib)
{
    virtaddr_t keep = virt;

    assert(IS_PAGE_ALIGNED(virt));
    assert(IS_PAGE_ALIGNED(sz));

    while ((uintptr)virt < (uintptr)ADD_TO_PTR(keep, sz))
    {
        arch_vmm_unmap(virt, attrib);
        virt = ADD_TO_PTR(virt, KCONFIG_MMU_PAGESIZE);
    }
}

bool vmm_is_mapped(virtaddr_t virt)
{
    return (arch_vmm_is_mapped(virt));
}

void vmm_init(void)
{
    kalloc_init();
}

/*
** Can't be a boot_initcall()
** we are calling the kalloc_init() which need arch VMM initcall 
*/