#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/cpus/vmulticore.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "arch/overworld/generic_printf.h"
#include <stdarg.h>

// smplock_t lock = SMPLOCK_INIT();

void rpifb_kprint(char const *fmt, ...)
{
    // semaphore_inc(&lock);
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(rpifb_szputs, NULL, fmt, ap);
    __builtin_va_end(ap);
    // semaphore_dec(&lock);
}