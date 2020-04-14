#include "kernel/def/typedef.h"
#include "kernel/lib/lib.h"

void *memset(void *x, int c, size_t sz)
{
    if (x)
        for (u32_t i = 0; i < sz; i++)
            ((uchar *)x)[i] = (uchar)c;
    return (x);
}

void *memsetw(void *x, int c, size_t sz)
{
    if (x)
        for (u32_t i = 0; i < sz; i++)
            ((uint16 *)x)[i] = (uint16)c;
    return (x);
}


void *memsetd(void *x, int c, size_t sz)
{
    if (x)
        for (u32_t i = 0; i < sz; i++)
            ((uint32 *)x)[i] = (uint32)c;
    return (x);
}


void *memsetq(void *x, int c, size_t sz)
{
    if (x)
        for (u32_t i = 0; i < sz; i++)
            ((uint64 *)x)[i] = (uint64)c;
    return (x);
}
