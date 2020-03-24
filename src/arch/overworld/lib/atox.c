#include "def/typedef.h"
#include "arch/overworld/overworld.h"

uint8 fromPrefixToBase(char const **s)
{
    if (strlen(*s) < 0x3)
        return (0xA);
    if (**s == '0')
        switch (*(*s + 0x1)) {
            case 'x':
            case 'X':
                *s = *s + 0x2;
                return (0x10);
                break;
            case 'b':
            case 'B':
                *s = *s + 0x2;
                return (0x2);
                break;
            case 'o':
            case 'O':
                *s = *s + 0x2;
                return (0x8);
                break;
            default:
                break;
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