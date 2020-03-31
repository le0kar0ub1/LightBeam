#ifndef __INITCALLS_H__
#define __INITCALLS_H__

typedef void (*initcall_t)(void);
typedef void (*exithook_t)(void);

#define __init __attribute__ ((__section__ (".init.text")))

#define __define_initcall(level, fn, id) \
    static const initcall_t __initcall_##fn##id \
    __attribute__((__used__, __section__(".initcall_" level ".text"))) = fn

#define __get_hooklevel(type, level, point) __##type##level##point

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

void run_inicalls(void);

void run_inicalls_bylevel(void);

#endif
