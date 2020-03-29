#include "def/typedef.h"
#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "arch/overworld/generic_printf.h"
#include <stdarg.h>

static smplock_t lock = SMPLOCK_INIT;

void uart_kprint(char const *fmt, ...)
{
    semaphore_inc(&lock);
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(uart_send, NULL, fmt, ap);
    __builtin_va_end(ap);
    semaphore_dec(&lock);
}