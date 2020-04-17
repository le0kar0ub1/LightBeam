#ifndef _FATAL_ASSERT_H
#define _FATAL_ASSERT_H

#include "kernel/def/keyword.h"
#include <stddef.h>
#include <stdint.h>

void PANIC(char const *, ...);

#define assert(expr) if (__unexpected(!(expr))) { PANIC(    \
    "assert(%s) failed\n    file: %s\n    function: %s\n    line: %d\n", \
    #expr, __FILE__, __func__, __LINE__);}

#define assert_eq(a, b)  assert((a) == (b))
#define assert_ne(a, b)  assert((a) != (b))
#define assert_lg(a, b)  assert((a) < (b))
#define assert_le(a, b)  assert((a) <= (b))
#define assert_gt(a, b)  assert((a) > (b))
#define assert_ge(a, b)  assert((a) > (b))

#define static_assert(expr) extern char (*__static__(void))[sizeof(char[(!!(expr)) * 2 - 1])]

#endif
