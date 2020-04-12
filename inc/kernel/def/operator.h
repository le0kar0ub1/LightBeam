#ifndef _PTR_OPERATOR_H_
#define _PTR_OPERATOR_H_

#include "typedef.h"

static inline bool ARE_PTR_EQUAL(void *x, void *y)
{
    return ((uintptr)x == (uintptr)y);
}

static inline bool IS_PTR_LT(void *x, void *y)
{
    return ((uintptr)x < (uintptr)y);
}

static inline bool IS_PTR_LE(void *x, void *y)
{
    return ((uintptr)x <= (uintptr)y);
}

static inline void *ADD_PTR(void *x, void *y)
{
    return ((void *)(((uintptr)x) + ((uintptr)y)));
}

static inline void *SUB_PTR(void *x, void *y)
{
    return ((void *)(((uintptr)x) - ((uintptr)y)));
}

static inline void *ADD_TO_PTR(void *x, uintptr y)
{
    return ((void *)(((uintptr)x) + y));
}

static inline void *SUB_TO_PTR(void *x, uintptr y)
{
    return ((void *)(((uintptr)x) - y));
}

#endif