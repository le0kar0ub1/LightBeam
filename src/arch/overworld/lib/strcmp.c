#include "arch/overworld/overworld.h"
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
    while (*x++ && *y++ && sz-- > 1)
        if (*x != *y)
            return (false);
    return (true);
}