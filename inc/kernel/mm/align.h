#ifndef __ALIGN_H_
#define __ALIGN_H_

#include "kernel/def/typedef.h"

#define IS_ALIGN(x, y) (((u64_t)x & (u64_t)y) == 0)

#define ALIGN(x, y)    (void *)((((u64_t)x) + (((u64_t)y) - 1)) & ~(((u64_t)y) - 1))

#endif