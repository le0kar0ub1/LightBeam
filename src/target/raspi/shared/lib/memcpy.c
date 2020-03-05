#include "def/typedef.h"
#include "target/raspi/raspi1/proto.h"

void *memcpy(void *dest, const void *src, size_t count)
{
    for (size_t i = 0; i < count; i++){
        ((uchar *)dest)[i] = ((const uchar *)src)[i];
    }
    return (dest);
}
