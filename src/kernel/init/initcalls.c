#include "kernel/init/initcalls.h"
#include "def/typedef.h"

extern initcall_t __initcall_start[];
extern initcall_t __initcall_end[];

extern initcall_t __initcall0_start[];
extern initcall_t __initcall1_start[];
extern initcall_t __initcall2_start[];
extern initcall_t __initcall3_start[];
extern initcall_t __initcall4_start[];
extern initcall_t __initcall5_start[];
extern initcall_t __initcall6_start[];
extern initcall_t __initcall7_start[];
extern initcall_t __initcall8_start[];
extern initcall_t __initcall9_start[];

extern initcall_t __initcall0_end[];
extern initcall_t __initcall1_end[];
extern initcall_t __initcall2_end[];
extern initcall_t __initcall3_end[];
extern initcall_t __initcall4_end[];
extern initcall_t __initcall5_end[];
extern initcall_t __initcall6_end[];
extern initcall_t __initcall7_end[];
extern initcall_t __initcall8_end[];
extern initcall_t __initcall9_end[];

void run_initcalls(void)
{
    initcall_t *hook;

    hook = &(*__initcall_start);
    while(hook < &(*__initcall_end))
    {
        (*hook)();
        hook++;
    }
}

void run_initcalls_bylevel(void)
{
    initcall_t *hook;
    initcall_t *end;

#define INITCALL_LEVEL(x)                                   \
    hook = &(*__get_hooklevel(initcall, x, _start));        \
    end  = &(*__get_hooklevel(initcall, x, _end));          \
    while(hook < end && (*hook)) { (*hook)(); hook++; }

    INITCALL_LEVEL(0);
#if KCONFIG_INITLEVEL > 0
    INITCALL_LEVEL(1)
#endif
#if KCONFIG_INITLEVEL > 1
    INITCALL_LEVEL(2)
#endif
#if KCONFIG_INITLEVEL > 2
    INITCALL_LEVEL(3)
#endif
#if KCONFIG_INITLEVEL > 3
    INITCALL_LEVEL(4)
#endif
#if KCONFIG_INITLEVEL > 4
    INITCALL_LEVEL(5)
#endif
#if KCONFIG_INITLEVEL > 5
    INITCALL_LEVEL(6)
#endif
#if KCONFIG_INITLEVEL > 6
    INITCALL_LEVEL(7)
#endif
#if KCONFIG_INITLEVEL > 7
    INITCALL_LEVEL(8)
#endif
#if KCONFIG_INITLEVEL > 8
    INITCALL_LEVEL(9)
#endif
}
