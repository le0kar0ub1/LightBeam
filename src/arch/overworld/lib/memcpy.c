#include "def/typedef.h"
#include "arch/overworld/overworld.h"

void *memcpy(void *dest, const void *src, size_t sz)
{
    if (dest && src)
        for (u32_t i = 0; i < sz; i++)
            ((uchar *)dest)[i] = ((const uchar *)src)[i];
    return (dest);
}
