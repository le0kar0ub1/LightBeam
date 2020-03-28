#include "def/typedef.h"
#include "arch/overworld/overworld.h"

u32_t strlen(char const *s)
{
    if (!s)
        return (0x0);
    u32_t i = 0;
    while (s[i]) i++;
    return (i);
}