#ifndef _PTR_OPERATOR_H_
#define _PTR_OPERATOR_H_

#include "./typedef.h"

static inline bool ARE_PTR_EQUAL(void *x, void *y)
{
    return ((uint64)x == (uint64)y);
}

static inline bool IS_PTR_LT(void *x, void *y)
{
    return ((uint64)x < (uint64)y);
}

static inline bool IS_PTR_LE(void *x, void *y)
{
    return ((uint64)x <= (uint64)y);
}

static inline void *ADD_PTR(void *x, void *y)
{
    return ((void *)(((uint64)x) + ((uint64)y)));
}

static inline void *SUB_PTR(void *x, void *y)
{
    return ((void *)(((uint64)x) - ((uint64)y)));
}

static inline void *ADD_TO_PTR(void *x, uint64 y)
{
    return ((void *)(((uint64)x) + y));
}

static inline void *SUB_TO_PTR(void *x, uint64 y)
{
    return ((void *)(((uint64)x) - y));
}

#endif