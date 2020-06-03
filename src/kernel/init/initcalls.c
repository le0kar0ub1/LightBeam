#include "kernel/init/initcalls.h"
#include "kernel/def/typedef.h"

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

/*
** Run all initcalls by level
*/
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

/*
** Run the given initcall level
*/
void run_initcall_level(u8_t lvl)
{
    initcall_t *hook;
    initcall_t *end;

    switch (lvl) {
        case 0:
            hook = &(*__get_calllevel(0, _start));
            end  = &(*__get_calllevel(0, _end));
            break;
        case 1:
            hook = &(*__get_calllevel(1, _start));
            end  = &(*__get_calllevel(1, _end));
            break;
        case 2:
            hook = &(*__get_calllevel(2, _start));
            end  = &(*__get_calllevel(2, _end));
            break;
        case 3:
            hook = &(*__get_calllevel(3, _start));
            end  = &(*__get_calllevel(3, _end));
            break;
        case 4:
            hook = &(*__get_calllevel(4, _start));
            end  = &(*__get_calllevel(4, _end));
            break;
        case 5:
            hook = &(*__get_calllevel(5, _start));
            end  = &(*__get_calllevel(5, _end));
            break;
        case 6:
            hook = &(*__get_calllevel(6, _start));
            end  = &(*__get_calllevel(6, _end));
            break;
        case 7:
            hook = &(*__get_calllevel(7, _start));
            end  = &(*__get_calllevel(7, _end));
            break;
        case 8:
            hook = &(*__get_calllevel(8, _start));
            end  = &(*__get_calllevel(8, _end));
            break;
        case 9:
            hook = &(*__get_calllevel(9, _start));
            end  = &(*__get_calllevel(9, _end));
            break;
        default:
            return;
    }
    while(hook < end && (*hook))
    {
        (*hook)();
        hook++;
    }
}
