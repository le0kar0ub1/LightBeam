#ifndef _SERIAL_DRIVER_H
#define _SERIAL_DRIVER_H

#include "target/x86/x86.h"

#define COM1 0x3f8

void serial_printf(char const *fmt, ...);
void serial_vprintf(char const *fmt, __builtin_va_list ap);

void serial_szputs(char const *s, size_t sz);
void serial_puts(char const *s);

#endif
