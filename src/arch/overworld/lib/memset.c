#include "kernel/def/typedef.h"
#include "arch/overworld/overworld.h"

void *memset(void *x, int c, size_t sz)
{
    if (x)
        for (u32_t i = 0; i < sz; i++)
            ((uchar *)x)[i] = (uchar)c;
    return (x);
}
