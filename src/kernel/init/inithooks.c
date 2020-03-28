#include "kernel/init/inithooks.h"
#include "def/typedef.h"

extern inithook_t __inithook_start[];
extern inithook_t __inithook_end[];
extern exithook_t __exithook_start[];
extern exithook_t __exithook_end[];

extern inithook_t __inithook0_start[];
extern inithook_t __inithook1_start[];
extern inithook_t __inithook2_start[];
extern inithook_t __inithook3_start[];
extern inithook_t __inithook4_start[];
extern inithook_t __inithook5_start[];
extern inithook_t __inithook6_start[];
extern inithook_t __inithook7_start[];
extern inithook_t __inithook8_start[];
extern inithook_t __inithook9_start[];

extern inithook_t __inithook0_end[];
extern inithook_t __inithook1_end[];
extern inithook_t __inithook2_end[];
extern inithook_t __inithook3_end[];
extern inithook_t __inithook4_end[];
extern inithook_t __inithook5_end[];
extern inithook_t __inithook6_end[];
extern inithook_t __inithook7_end[];
extern inithook_t __inithook8_end[];
extern inithook_t __inithook9_end[];

extern exithook_t __exithook0_start[];
extern exithook_t __exithook1_start[];
extern exithook_t __exithook2_start[];
extern exithook_t __exithook3_start[];
extern exithook_t __exithook4_start[];
extern exithook_t __exithook5_start[];
extern exithook_t __exithook6_start[];
extern exithook_t __exithook7_start[];
extern exithook_t __exithook8_start[];
extern exithook_t __exithook9_start[];

extern exithook_t __exithook0_end[];
extern exithook_t __exithook1_end[];
extern exithook_t __exithook2_end[];
extern exithook_t __exithook3_end[];
extern exithook_t __exithook4_end[];
extern exithook_t __exithook5_end[];
extern exithook_t __exithook6_end[];
extern exithook_t __exithook7_end[];
extern exithook_t __exithook8_end[];
extern exithook_t __exithook9_end[];

void run_inithooks(void)
{
    inithook_t *hook;

    hook = &(*__inithook_start);
    while(hook < &(*__inithook_end))
    {
        (*hook)();
        hook++;
    }
}

void run_exithooks(void)
{
    exithook_t *hook;

    hook = &(*__exithook_start);
    while(hook < &(*__exithook_end))
    {
        (*hook)();
        hook++;
    }
}

void run_inithooks_bylevel(void)
{
    inithook_t *hook;
    inithook_t *end;

#define INITHOOK_LEVEL(x)                                   \
    hook = &(*__get_hooklevel(inithook, x, _start));        \
    end  = &(*__get_hooklevel(inithook, x, _end));          \
    while(hook < end && (*hook)) { (*hook)(); hook++; }

    INITHOOK_LEVEL(0);
#if KCONFIG_INITLEVEL > 0
    INITHOOK_LEVEL(1)
#endif
#if KCONFIG_INITLEVEL > 1
    INITHOOK_LEVEL(2)
#endif
#if KCONFIG_INITLEVEL > 2
    INITHOOK_LEVEL(3)
#endif
#if KCONFIG_INITLEVEL > 3
    INITHOOK_LEVEL(4)
#endif
#if KCONFIG_INITLEVEL > 4
    INITHOOK_LEVEL(5)
#endif
#if KCONFIG_INITLEVEL > 5
    INITHOOK_LEVEL(6)
#endif
#if KCONFIG_INITLEVEL > 6
    INITHOOK_LEVEL(7)
#endif
#if KCONFIG_INITLEVEL > 7
    INITHOOK_LEVEL(8)
#endif
#if KCONFIG_INITLEVEL > 8
    INITHOOK_LEVEL(9)
#endif
}

void run_exithooks_bylevel(void)
{
    exithook_t *hook;
    exithook_t *end;

#define EXITHOOK_LEVEL(x)                                   \
    hook = &(*__get_hooklevel(exithook, x, _start));        \
    end  = &(*__get_hooklevel(exithook, x, _end));          \
    while(hook < end && (*hook)) { (*hook)(); hook++; }

    EXITHOOK_LEVEL(0);
#if KCONFIG_INITLEVEL > 0
    EXITHOOK_LEVEL(1)
#endif
#if KCONFIG_INITLEVEL > 1
    EXITHOOK_LEVEL(2)
#endif
#if KCONFIG_INITLEVEL > 2
    EXITHOOK_LEVEL(3)
#endif
#if KCONFIG_INITLEVEL > 3
    EXITHOOK_LEVEL(4)
#endif
#if KCONFIG_INITLEVEL > 4
    EXITHOOK_LEVEL(5)
#endif
#if KCONFIG_INITLEVEL > 5
    EXITHOOK_LEVEL(6)
#endif
#if KCONFIG_INITLEVEL > 6
    EXITHOOK_LEVEL(7)
#endif
#if KCONFIG_INITLEVEL > 7
    EXITHOOK_LEVEL(8)
#endif
#if KCONFIG_INITLEVEL > 8
    EXITHOOK_LEVEL(9)
#endif
}

