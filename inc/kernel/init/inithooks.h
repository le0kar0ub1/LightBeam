#ifndef __INITHOOKS_H__
#define __INITHOOKS_H__

typedef void (*inithook_t)(void);

#define __init __attribute__ ((__section__ (".init.text")))

#define __define_inithook(level, fn, id) \
    static const inithook_t __inithook_##fn##id \
    __attribute__((__used__, __section__(".inithook_" level ".text"))) = fn

#define __get_hooklevel(type, level) __##type##level

#define boot_inithook(fn)       __define_inithook("0", fn, 0)
#define pure_inithook(fn)       __define_inithook("1", fn, 1)
#define core_inithook(fn)       __define_inithook("2", fn, 2)
#define postcore_inithook(fn)   __define_inithook("3", fn, 3)
#define driver_inithook(fn)     __define_inithook("4", fn, 4)
#define subsys_inithook(fn)     __define_inithook("5", fn, 5)
#define command_inithook(fn)    __define_inithook("6", fn, 6)
#define server_inithook(fn)     __define_inithook("7", fn, 7)
#define gui_inithook(fn)        __define_inithook("8", fn, 8)
#define last_inithook(fn)       __define_inithook("9", fn, 9)

void run_inithooks(void);

void run_inithooks_bylevel(void);

#endif
