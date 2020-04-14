#include "kernel/def/typedef.h"
#include "kernel/lib/lib.h"

u32_t numberlen(u32_t n, u8_t base)
{
    u32_t len = 0x0;

    while (n >= base) {
        n /= base;
        len++;
    }
    return (len);
}