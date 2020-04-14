#include "target/x86/x86.h"
#include "target/x86/common/drivers/vga.h"

void vga_printf(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(vga_szputs, NULL, fmt, ap);
    __builtin_va_end(ap);
}