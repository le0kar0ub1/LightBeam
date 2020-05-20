#ifndef __x86_64VMM_H_
#define __x86_64VMM_H_

#include "target/x86/x86.h"
#include "target/x86/common/memory/vmm.h"

struct pml4_entry_t
{
    union
    {
        struct
        {
            uint64 present : 1;
            uint64 rw : 1;
            uint64 user : 1;
            uint64 wtrough : 1;
            uint64 cache : 1;
            uint64 accessed : 1;
            uint64 dirty : 1;
            uint64 size : 1;
            uint64 global: 1;
            uint64 __unused1 : 3;
            uint64 frame : 40;
            uint64 __unused2 : 11;
            uint64 execDisable : 1;
        };
        uintptr value;
    };
};

struct pdp_entry_t
{
    union
    {
        struct
        {
            uint64 present : 1;
            uint64 rw : 1;
            uint64 user : 1;
            uint64 wtrough : 1;
            uint64 cache : 1;
            uint64 accessed : 1;
            uint64 dirty : 1;
            uint64 size : 1;
            uint64 global: 1;
            uint64 __unused1 : 3;
            uint64 frame : 40;
            uint64 Ignored3 : 11;
            uint64 execDisable : 1;
        };
        uintptr value;
    };
};

struct pd_entry_t
{
    union
    {
        struct
        {
            uint64 present : 1;
            uint64 rw : 1;
            uint64 user : 1;
            uint64 wtrough : 1;
            uint64 cache : 1;
            uint64 accessed : 1;
            uint64 dirty : 1;
            uint64 size : 1;
            uint64 global: 1;
            uint64 __unused1 : 3;
            uint64 frame : 40;
            uint64 Ignored3 : 11;
            uint64 execDisable : 1;
        };
        uintptr value;
    };
};

struct pt_entry_t
{
    union
    {
        struct
        {
            uint64 present : 1;
            uint64 rw : 1;
            uint64 user : 1;
            uint64 wtrough : 1;
            uint64 cache : 1;
            uint64 accessed : 1;
            uint64 dirty : 1;
            uint64 size : 1;
            uint64 global: 1;
            uint64 __unused1 : 3;
            uint64 frame : 40;
            uint64 Ignored3 : 11;
            uint64 execDisable : 1;
        };
        uintptr value;
    };
};

struct pt_t
{
    struct pt_entry_t entries[KCONFIG_MMU_PAGESIZE / sizeof(struct pt_entry_t)];
};

struct pd_t
{
    struct pd_entry_t entries[KCONFIG_MMU_PAGESIZE / sizeof(struct pd_entry_t)];
};


struct pdp_t
{
    struct pdp_entry_t entries[KCONFIG_MMU_PAGESIZE / sizeof(struct pdp_entry_t)];
};

struct pml4_t
{
    struct pml4_entry_t entries[KCONFIG_MMU_PAGESIZE / sizeof(struct pml4_entry_t)];
};


static_assert(sizeof(struct pt_t) == KCONFIG_MMU_PAGESIZE);
static_assert(sizeof(struct pd_t) == KCONFIG_MMU_PAGESIZE);
static_assert(sizeof(struct pdp_t) == KCONFIG_MMU_PAGESIZE);
static_assert(sizeof(struct pml4_t) == KCONFIG_MMU_PAGESIZE);

bool arch_vmm_is_mapped(virtaddr_t virt);
physaddr_t arch_vmm_get_mapped_frame(virtaddr_t virt);
mmstatus_t arch_vmm_map_phys(virtaddr_t virt, physaddr_t phys, mmap_attrib_t attrib);
mmstatus_t arch_vmm_map_virt(virtaddr_t virt, mmap_attrib_t attrib);
void arch_vmm_unmap(virtaddr_t virt, munmap_attrib_t attrib);
void arch_vmm_init(void);

#endif