#ifndef __ALIGN_H_
#define __ALIGN_H_

#include "kernel/def/typedef.h"

#define IS_ALIGNED(x, y)   (!(((uintptr)x) & (y - 0x1)))

#define IS_PAGE_ALIGNED(x) (IS_ALIGNED(x, KCONFIG_MMU_PAGESIZE))

#define ALIGN(x, y)        (void *)((((uintptr)x) + (((uintptr)y) - 1)) & ~(((uintptr)y) - 1))

#define ROUND_DOWN(x, y)   (((uintptr)x) & ~(((uintptr)y) - 1))

#endif