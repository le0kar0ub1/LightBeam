#ifndef __INITCALLS_H__
#define __INITCALLS_H__

#include "def/typedef.h"

typedef void (*initcall_t)(void);
typedef void (*exithook_t)(void);

#define __init __attribute__ ((__section__ (".init.text")))

#define __define_initcall(level, fn, id) \
    static const initcall_t __initcall_##fn##id \
    __attribute__((__used__, __section__(".initcall_" level ".text"))) = fn

#define __get_calllevel(level, point) (__initcall##level##point)

#define boot_initcall(fn)       __define_initcall("0", fn, 0)
#define pure_initcall(fn)       __define_initcall("1", fn, 1)
#define core_initcall(fn)       __define_initcall("2", fn, 2)
#define postcore_initcall(fn)   __define_initcall("3", fn, 3)
#define driver_initcall(fn)     __define_initcall("4", fn, 4)
#define subsys_initcall(fn)     __define_initcall("5", fn, 5)
#define command_initcall(fn)    __define_initcall("6", fn, 6)
#define server_initcall(fn)     __define_initcall("7", fn, 7)
#define gui_initcall(fn)        __define_initcall("8", fn, 8)
#define last_initcall(fn)       __define_initcall("9", fn, 9)

void run_initcalls(void);
void run_initcall_level(u8_t);

#define run_boot_initcalls(fn)       run_initcall_level(0)
#define run_pure_initcalls(fn)       run_initcall_level(1)
#define run_core_initcalls(fn)       run_initcall_level(2)
#define run_postcore_initcalls(fn)   run_initcall_level(3)
#define run_driver_initcalls(fn)     run_initcall_level(4)
#define run_subsys_initcalls(fn)     run_initcall_level(5)
#define run_command_initcalls(fn)    run_initcall_level(6)
#define run_server_initcalls(fn)     run_initcall_level(7)
#define run_gui_initcalls(fn)        run_initcall_level(8)
#define run_last_initcalls(fn)       run_initcall_level(9)

#endif
