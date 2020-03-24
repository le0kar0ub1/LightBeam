#ifndef _FATAL_ASSERT_H
#define _FATAL_ASSERT_H

#include <stdio.h>
#include "def/keyword.h"

void PANIC(char const *, ...);

// #if ARE_ASSERT_FATAL
    #define assert(expr) if (__unexpected(!(expr))) { PANIC(    \
        "assert(%s) failed\n    file: %s\n    function: %s\n    line: %d\n", \
         #expr, __FILE__, __func__, __LINE__);}
// #else
    // #define assert(expr)
// #endif

/* PANIC IF ASSERT FAILED */
#define assert_eq(a, b)  assert((a) == (b))
#define assert_ne(a, b)  assert((a) != (b))
#define assert_lg(a, b)  assert((a) < (b))
#define assert_le(a, b)  assert((a) <= (b))
#define assert_gt(a, b)  assert((a) > (b))
#define assert_ge(a, b)  assert((a) > (b))

#endif
