#include "kernel/init/inithooks.h"
#include "kernel/def/typedef.h"
#include "kernel/def/assert.h"

extern inithook_t __inithook_start[];
extern inithook_t __inithook_end[];

extern inithook_t __inithook0[];
extern inithook_t __inithook1[];
extern inithook_t __inithook2[];
extern inithook_t __inithook3[];
extern inithook_t __inithook4[];
extern inithook_t __inithook5[];
extern inithook_t __inithook6[];
extern inithook_t __inithook7[];
extern inithook_t __inithook8[];
extern inithook_t __inithook9[];

#define INITHOOK_LEVEL(x)                      \
    hook = &(*__get_hooklevel(inithook, x));   \
    (*hook)();

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

void run_inithooks_bylevel(void)
{
    inithook_t *hook;

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