#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/cpus/vmulticore.h"
#include "target/aarch64/raspi/raspi3/drivers/fb.h"
#include "target/aarch64/raspi/raspi3/cpus/cpus.h"
#include "kernel/lib/printf.h"
#include <stdarg.h>

void rpifb_kprint(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(rpifb_szputs, NULL, fmt, ap);
    __builtin_va_end(ap);
}

void rpifb_kvprint(char const *fmt, __builtin_va_list ap)
{
    generic_vprintf(rpifb_szputs, NULL, fmt, ap);
}