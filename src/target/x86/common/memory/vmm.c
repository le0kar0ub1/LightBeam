#include "target/x86/common/memory/vmm.h"
#include "target/x86/common/memory/kalloc.h"

/*
** Call the arch-dependant mmap to map X page
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
    return (keep);
}

/*
** Call the arch-dependant mmap to unmap X page
*/
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

/*
** Call the arch-dependant to map a know virtual & physical address
*/
virtaddr_t vmm_mmap_dev(virtaddr_t virt, physaddr_t phys, size_t size, mmap_attrib_t attrib)
{
    virtaddr_t keep = virt;
    mmstatus_t status;

    assert(IS_PAGE_ALIGNED(virt));
    assert(IS_PAGE_ALIGNED(phys));
    assert(IS_PAGE_ALIGNED(size));

    if (!virt || !phys)
        return (NULL);
    while ((uintptr)virt < (uintptr)ADD_TO_PTR(keep, size))
    {
        status = arch_vmm_map_phys(virt, phys, attrib);
        if (status != VMM_SUCCESS)
        {
            if (status != VMM_ALREADY_MAPPED)
                arch_vmm_unmap(virt, MUNMAP_DEFAULT);
            return (NULL);
        }
        phys = (uintptr)ADD_TO_PTR(phys, KCONFIG_MMU_PAGESIZE);
        virt = (virtaddr_t)ADD_TO_PTR(virt, KCONFIG_MMU_PAGESIZE);
    }
    return (keep);
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
** Can't be a initcall()
** we are calling the kalloc_init() which need arch VMM initcall 
*/