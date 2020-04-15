#include "target/x86/x86.h"
#include "target/x86/common/drivers/serial.h"

void serial_printf(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(serial_szputs, NULL, fmt, ap);
    __builtin_va_end(ap);
}

void serial_vprintf(char const *fmt, __builtin_va_list ap)
{
    generic_vprintf(serial_szputs, NULL, fmt, ap);
}