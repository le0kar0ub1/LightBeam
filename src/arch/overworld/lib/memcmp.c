#include "kernel/def/typedef.h"
#include "arch/overworld/overworld.h"

bool memcmp(const void *x, const void *y, size_t sz)
{
    if (x && y)
        for (u32_t i = 0; i < sz; i++)
            if (((uchar *)x)[i] != ((const uchar *)y)[i])
                return (false);
    return (true);
}
