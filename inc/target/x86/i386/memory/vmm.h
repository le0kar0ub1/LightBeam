#ifndef __i386VMM_H_
#define __i386VMM_H_

#include "target/x86/x86.h"
#include "target/x86/common/memory/vmm.h"

struct pagedir_entry
{
    union
    {
        struct
        {
            uint32 present : 1;     /* Present in memory */
            uint32 rw : 1;          /* 0 => Readonly / 1 => Readwrite */
            uint32 user : 1;        /* 0 => Kernel page / 1 => User */
            uint32 wtrough : 1;     /* 1 => write through caching */
            uint32 cache : 1;       /* 1 => Cache disable */
            uint32 accessed : 1;    /* set by cpu when accessed */
            uint32 _zero : 1;       /* Must be 0 */
            uint32 size : 1;        /* 0 => 4KiB page, 1 => 4MiB page */
            uint32 __unusued : 4;   /* unused & reserved bits */
            uint32 frame : 20;      /* Frame address */
        };
        uintptr value;
    };
};

struct pagetable_entry
{
    union
    {
        struct
        {
            uint32 present : 1;     /* Present in memory */
            uint32 rw : 1;          /* 0 => Readonly / 1 => Readwrite */
            uint32 user : 1;        /* 0 => Kernel page / 1 => User */
            uint32 wtrough : 1;     /* 1 => write through caching */
            uint32 cache : 1;       /* 1 => Cache disable */
            uint32 accessed : 1;    /* set by cpu when accessed */
            uint32 dirty : 1;       /* Set by cpu when writting */
            uint32 _zero : 1;       /* Must be zero */
            uint32 global : 1;      /* Prevent tlb update */
            uint32 __unusued : 3;   /* unused & reserved bits */
            uint32 frame : 20;      /* Frame address */
        };
        uintptr value;
    };
};

struct page_table
{
    struct pagetable_entry entries[KCONFIG_MMU_PAGESIZE / sizeof(struct pagetable_entry)];
};

struct page_dir
{
    struct pagedir_entry entries[KCONFIG_MMU_PAGESIZE / sizeof(struct pagedir_entry)];
};

static_assert(sizeof(struct page_table) == KCONFIG_MMU_PAGESIZE);
static_assert(sizeof(struct page_dir) == KCONFIG_MMU_PAGESIZE);

bool arch_vmm_is_mapped(virtaddr_t virt);
physaddr_t arch_vmm_get_mapped_frame(virtaddr_t virt);
mmstatus_t arch_vmm_map_phys(virtaddr_t virt, physaddr_t phys, mmap_attrib_t attrib);
mmstatus_t arch_vmm_map_virt(virtaddr_t virt, mmap_attrib_t attrib);
void arch_vmm_unmap(virtaddr_t virt, munmap_attrib_t attrib);
void arch_vmm_init(void);

#endif