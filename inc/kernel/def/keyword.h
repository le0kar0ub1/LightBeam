#ifndef _KEYWORDS_H
#define _KEYWORDS_H

/* C11 KEYWORD SHORTCUT */
#define restrict        __restrict
#define __pure          __attribute__((pure))
#define __const         __attribute__((const))
#define __cold          __attribute__((cold))
#define __hot           __attribute__((hot))
#define __used          __attribute__((used))
#define __unused        __attribute__((unused))
#define __packed        __attribute__((packed))
#define __weak          __attribute__((weak))
#define __aligned(x)    __attribute__((aligned (x)))
#define __section(s)    __attribute__((section (s)))
#define __noreturn      __attribute__((noreturn))
#define __expected(x)   __builtin_expect((x), 1)
#define __unexpected(x) __builtin_expect((x), 0)
#define __optimize(x)   __attribute__((optimize(x)))

#endif
