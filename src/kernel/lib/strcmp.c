#include "kernel/lib/lib.h"
#include <stdbool.h>

bool strcmp(char const *x, char const *y)
{
    if (!x || !y)
        return (false);
    while (*x++ && *y++)
        if (*x != *y)
            return (false);
    return (true);
}

bool strncmp(char const *x, char const *y, size_t sz)
{
    if (!x || !y)
        return (false);
    size_t i = 0;
    for (; x[i] && y[i] && i < sz; i++)
        if (x[i] != y[i])
            return (false);
    if (i != sz)
        return (false);
    return (true);
}