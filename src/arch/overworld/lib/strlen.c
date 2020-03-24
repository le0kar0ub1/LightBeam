#include "def/typedef.h"
#include "arch/overworld/overworld.h"

uint32 strlen(char const *s)
{
    if (!s)
        return (0x0);
    uint32 i = 0;
    while (s[i]) i++;
    return (i);
}