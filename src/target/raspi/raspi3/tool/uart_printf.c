#include "def/typedef.h"
#include "target/raspi/raspi3/uart.h"
#include <stdarg.h>

// void uart_kprint(char const *fmt, ...)
// {
//     __builtin_va_list ap;
//     __builtin_va_start(ap, fmt);
//     __builtin_va_end(ap);
// }