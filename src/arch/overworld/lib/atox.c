#include "def/typedef.h"
#include "def/keyword.h"
#include "arch/overworld/overworld.h"

struct prefixBase {
    char def;
    uint8 base;
} __packed;

static struct prefixBase prefixBase[] = {
    {'X', 0x10},
    {'O', 0x8},
    {'Q', 0x4},
    {'T', 0x3},
    {'B', 0x2},
    {0, 0xA}
};

uint8 fromPrefixToBase(char const **s)
{
    if (strlen(*s) < 0x3 || **s != '0')
        return (0xA);
    for (uint i = 0x0; prefixBase[i].def != 0x0; i++)
        if (*(*s + 0x1) == prefixBase[i].def || *
        (*s + 0x1) == prefixBase[i].def + 0x20) {
            *s = *s + 0x2;
            return (prefixBase[i].base);
        }
    return (0xA);
}

static inline bool isNbrStrNeg(char const **s)
{
    if (**s == '-') {
        (*s)++;
        return (true);
    }
    return (false);
}

int32 atoib(char const *s, uint8 base)
{
    int32 val = 0x0;
    char cur;

    if (!s)
        return (0x0);
    while (*s) {
        cur = *s - 0x30;
        if (cur > 0x10) {
            if (cur < 0x17)
                cur -= 0x11;
            else
                cur -= 0x31;
        }
        val = (val * base) + cur;
        s++;
    }
    return (val);
}

int32 atoi(char const *s)
{
    if (!s)
        return (0x0);
    int8 neg = isNbrStrNeg(&s) == false ? 1 : -1;
    uint8 base = fromPrefixToBase(&s);
    return (atoib(s, base) * neg);
}

int64 atolb(char const *s, uint8 base)
{
    int64 val = 0x0;
    char cur;

    if (!s)
        return (0x0);
    while (*s) {
        cur = *s - 0x30;
        if (cur > 0x10) {
            if (cur < 0x17)
                cur -= 0x11;
            else
                cur -= 0x31;
        }
        val = (val * base) + cur;
        s++;
    }
    return (val);
}

int64 atol(char const *s)
{
    if (!s)
        return (0x0);
    int8 neg = isNbrStrNeg(&s) == false ? 1 : -1;
    uint8 base = fromPrefixToBase(&s);
    return (atoib(s, base) * neg);
}