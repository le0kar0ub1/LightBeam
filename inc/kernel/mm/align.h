#ifndef __ALIGN_H_
#define __ALIGN_H_

#include "kernel/def/typedef.h"

#define IS_ALIGNED(x, y) (!(((archv_t)x) & (y - 0x1)))

#define ALIGN(x, y)    (void *)((((archv_t)x) + (((archv_t)y) - 1)) & ~(((archv_t)y) - 1))

#endif