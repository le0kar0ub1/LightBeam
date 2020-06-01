#include "kernel/def/typedef.h"
#include "kernel/lib/printf.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include <stdarg.h>

void uart_kprint(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(uart_szputs, NULL, fmt, ap);
    __builtin_va_end(ap);
}