#ifndef __MMU_H_
#define __MMU_H_

#include "def/typedef.h"

typedef uintptr mmuval_t;
typedef uintptr physaddr_t;
typedef void * virtaddr_t;

#define PAGESIZE    0x1000

// granularity
#define PT_PAGE     0b11        // 4k granularity
#define PT_BLOCK    0b01        // 2M granularity
// accessibility
#define PT_KERNEL   (0 << 6)      // privileged, supervisor EL1 access only
#define PT_USER     (1 << 6)      // unprivileged, EL0 access allowed
#define PT_RW       (0 << 7)      // read-write
#define PT_RO       (1 << 7)      // read-only
#define PT_AF       (1 << 10)     // accessed flag
#define PT_NX       (1UL << 54)   // no execute
// shareability
#define PT_OSH      (2 << 8)      // outter shareable
#define PT_ISH      (3 << 8)      // inner shareable
// defined in MAIR register
#define PT_MEM      (0 << 2)      // normal memory
#define PT_DEV      (1 << 2)      // device MMIO
#define PT_NC       (2 << 2)      // non-cachable

#define TTBR_CNP    1

#define MMU_DEVICE_NGNRNE  0
#define MMU_DEVICE_NGNRE   1
#define MMU_DEVICE_GRE     2
#define MMU_NORMAL_NC      3
#define MMU_NORMAL         4

void mmu_init(void);

mmuval_t ARMToGPU(mmuval_t);
mmuval_t GPUToARM(mmuval_t);

#endif