#include "kernel/init/inithooks.h"

extern inithook_t __inithook_start[];
extern inithook_t __inithook_end[];
extern exithook_t __exithook_start[];
extern exithook_t __exithook_end[];

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
