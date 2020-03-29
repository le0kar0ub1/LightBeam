#ifndef __GENERIC_PRINTF_H_
#define __GENERIC_PRINTF_H_

#include "def/typedef.h"
#include <stdbool.h>
#include <stdarg.h>

struct printfhandlers_t
{
    char const *flg;
    void (*handler0)(void);
    void (*handler1)(u64_t);
};

/* Generic printf with assigned printer */
bool handle_caller_flg(char const **, __builtin_va_list *);
void generic_vprintf(void (*)(char), struct printfhandlers_t *, char const *, __builtin_va_list);
void generic_printf(void (*)(char), struct printfhandlers_t *, char const *, ...);
void __generic_printf(char const *, __builtin_va_list);
void generic_printf_switch_type(char const **, __builtin_va_list *);
void generic_base_longput(long, int);
void generic_base_intput(int, int);
void generic_puts(char const *);

#endif