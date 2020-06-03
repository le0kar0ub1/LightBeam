#include "target/aarch64/raspi/raspi3/cpus/cpus.h"
#include "target/aarch64/raspi/raspi3/drivers/fb.h"

void arch_cpu_log(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    rpifb_kvprint(fmt, ap);
    __builtin_va_end(ap);
}

void arch_cpu_wrn(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    rpifb_kvprint(fmt, ap);
    __builtin_va_end(ap);
}

void arch_cpu_err(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    rpifb_kvprint(fmt, ap);
    __builtin_va_end(ap);
}