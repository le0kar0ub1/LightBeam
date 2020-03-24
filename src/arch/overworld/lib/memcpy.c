#include "def/typedef.h"
#include "arch/overworld/overworld.h"

void *memcpy(void *dest, const void *src, size_t sz)
{
    if (dest && src)
        while (--sz > 0)
            ((uchar *)dest)[sz] = ((const uchar *)src)[sz];
    return (dest);
}
