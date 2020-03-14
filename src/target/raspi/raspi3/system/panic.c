#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/system.h"
#include <stdarg.h>

void PANIC(char const *fmt, ...)
{
    lfb_kprint("[CPU %d] [%$AERR%$R]: ", cpu_getid(), RGB_Magenta);
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    __lfb_kprint(fmt, ap);
    __builtin_va_end(ap);
    __deadloop();
}