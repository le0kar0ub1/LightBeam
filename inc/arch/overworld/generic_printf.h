#ifndef __GENERIC_PRINTF_H_
#define __GENERIC_PRINTF_H_

#include "kernel/def/typedef.h"
#include <stdbool.h>
#include <stdarg.h>

struct printfhandlers_t
{
    char const *flg;
    void (*handler0)(void);
    void (*handler1)(u64_t);
};

/* Generic printf with assigned printer */
void generic_vprintf(void (*)(char), struct printfhandlers_t *, char const *, __builtin_va_list);
void generic_printf(void (*)(char), struct printfhandlers_t *, char const *, ...);
void __generic_printf(char const *, __builtin_va_list);

/* followed static declaration 
** void generic_printf_hdlflg(char const **, __builtin_va_list *);
** bool handle_caller_flg(char const **, __builtin_va_list *);
*/

void generic_puts(char const *);
void multibase_put64(long, u8_t);
void multibase_put32(int, u8_t);
void multibase_uput32(unsigned int, u8_t);
void multibase_uput64(unsigned long, u8_t);

#endif