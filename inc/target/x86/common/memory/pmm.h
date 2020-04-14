#ifndef __PMM_H_
#define __PMM_H_

#include "target/x86/x86.h"

#define PMM_TOTAL_FRAME (UINTPTR_MAX / KCONFIG_MMU_PAGESIZE)
#define PMM_BITMAP_SIZE (PMM_TOTAL_FRAME / 8)

#define BITMAP_ADDR2IDX(x)  ((x >> 12) / 8)
#define BITMAP_ADDR2MASK(x) (1 << (((x) >> 12) % 8))

#endif