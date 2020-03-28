#ifndef _PTR_OPERATOR_H_
#define _PTR_OPERATOR_H_

#include "typedef.h"

static inline bool ARE_PTR_EQUAL(void *x, void *y)
{
    return ((u64_t)x == (u64_t)y);
}

static inline bool IS_PTR_LT(void *x, void *y)
{
    return ((u64_t)x < (u64_t)y);
}

static inline bool IS_PTR_LE(void *x, void *y)
{
    return ((u64_t)x <= (u64_t)y);
}

static inline void *ADD_PTR(void *x, void *y)
{
    return ((void *)(((u64_t)x) + ((u64_t)y)));
}

static inline void *SUB_PTR(void *x, void *y)
{
    return ((void *)(((u64_t)x) - ((u64_t)y)));
}

static inline void *ADD_TO_PTR(void *x, u64_t y)
{
    return ((void *)(((u64_t)x) + y));
}

static inline void *SUB_TO_PTR(void *x, u64_t y)
{
    return ((void *)(((u64_t)x) - y));
}

#endif