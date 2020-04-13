#ifndef _PTR_OPERATOR_H_
#define _PTR_OPERATOR_H_

#include "typedef.h"

#define ARE_PTR_EQUAL(x, y) ((uintptr)x == (uintptr)y)

#define IS_PTR_LT(x, y) ((uintptr)x < (uintptr)y)

#define IS_PTR_LE(x, y) ((uintptr)x <= (uintptr)y)

#define ADD_PTR(x, y) ((void *)(((uintptr)x) + ((uintptr)y)))

#define SUB_PTR(x, y) ((void *)(((uintptr)x) - ((uintptr)y)))

#define ADD_TO_PTR(x, y) ((void *)(((uintptr)x) + y))

#define SUB_TO_PTR(x, y) ((void *)(((uintptr)x) - y))

#endif