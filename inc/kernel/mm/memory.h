#ifndef __X86MEMORY_H_
#define __X86MEMORY_H_

#include "kernel/def/typedef.h"
#include "kernel/mm/align.h"

/*
** Physical memory static allocation
** The PMM initializer must handle this section
*/

struct pmm_reserved_area
{
    char const *name;
    physaddr_t start;
    physaddr_t end;
};

#define PMM_RESERVE_AREA(n, s, e)                                                             \
    static struct pmm_reserved_area const _pmm_reserved_area_##n                              \
    __attribute__((__used__, __aligned__(sizeof(void *)), __section__("pmm_reserved_area")))  \
    {                                                                                         \
        .name = #n,                                                                           \
        .start = (s),                                                                         \
        .end = (e),                                                                           \
    }

#define P2V(x) ((uintptr)x + (uintptr)&__KERNEL_ADDR_TRNS)
#define V2P(x) ((uintptr)x - (uintptr)&__KERNEL_ADDR_TRNS)

#endif