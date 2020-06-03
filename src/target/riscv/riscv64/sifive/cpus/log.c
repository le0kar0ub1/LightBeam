#include "target/riscv/riscv64/sifive/cpus/cpus.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

/*
** cpu logging on uart
*/

void arch_cpu_log(char const *fmt, ...)
{
    __builtin_va_list ap;
    va_start(ap, fmt);
    uart_kvprint(fmt, ap);
    va_end(ap);
}

void arch_cpu_wrn(char const *fmt, ...)
{
    __builtin_va_list ap;
    va_start(ap, fmt);
    uart_kvprint(fmt, ap);
    va_end(ap);
}

void arch_cpu_err(char const *fmt, ...)
{
    __builtin_va_list ap;
    va_start(ap, fmt);
    uart_kvprint(fmt, ap);
    va_end(ap);
}