#ifndef _PTR_OPERATOR_H_
#define _PTR_OPERATOR_H_

#include "typedef.h"

#define IS_PTR_EQ(x, y)        ((uintptr)x == (uintptr)y)

#define IS_PTRINC_EQ(x , y , z) IS_PTR_EQ(x, ADD_PTR(y, z))

#define IS_PTR_LT(x, y) ((uintptr)x < (uintptr)y)

#define IS_PTR_LE(x, y) ((uintptr)x <= (uintptr)y)

#define IS_PTR_GT(x, y) ((uintptr)x > (uintptr)y)

#define IS_PTR_GE(x, y) ((uintptr)x >= (uintptr)y)

#define ADD_PTR(x, y) ((void *)(((uintptr)x) + ((uintptr)y)))

#define SUB_PTR(x, y) ((void *)(((uintptr)x) - ((uintptr)y)))

#define ADD_TO_PTR(x, y) ((void *)(((uintptr)x) + y))

#define SUB_TO_PTR(x, y) ((void *)(((uintptr)x) - y))

#endif