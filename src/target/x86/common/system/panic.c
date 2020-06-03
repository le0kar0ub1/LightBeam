#include "target/x86/x86.h"

/*
** kernel panic, no return
*/
void PANIC(char const *fmt, ...)
{
    serial_printf("Kernel Panic: ");
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    serial_vprintf(fmt, ap);
    __builtin_va_end(ap);
    while(1);
}