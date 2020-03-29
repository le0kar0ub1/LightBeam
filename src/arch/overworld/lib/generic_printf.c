#include "def/typedef.h"
#include "arch/overworld/overworld.h"
#include "arch/overworld/generic_printf.h"
#include "target/raspi/raspi3/semaphore.h"
#include <stdarg.h>

static void (*caller_putc)(char) = NULL;

static struct printfhandlers_t *callerhandlers = NULL;

void generic_base_intput(int n, int base)
{
    if (n < 0) {
        caller_putc('-');
        n = n * -1;
    }
    if (n >= base)
        generic_base_intput(n / base, base);
    caller_putc((n % base) + 0x30);
}

void generic_base_longput(long n, int base)
{
    if (n < 0) {
        caller_putc('-');
        n = n * -1;
    }
    if (n >= base)
        generic_base_longput(n / base, base);
    caller_putc((n % base) + 0x30);
}

void generic_puts(char const *s)
{
    for (int i = 0; s[i]; i++)
        caller_putc(s[i]);
}

bool handle_caller_flg(char const **fmt, __builtin_va_list *ap)
{
    for (u32_t i = 0; callerhandlers[i].flg; i++)
        if (strncmp(callerhandlers[i].flg, *fmt, strlen(callerhandlers[i].flg))) {
            if (callerhandlers[i].handler0)
                callerhandlers[i].handler0();
            else if (callerhandlers[i].handler1)
                callerhandlers[i].handler1(__builtin_va_arg(*ap, long));
            else
                return (false);
            *fmt += strlen(callerhandlers[i].flg) - 1;
            return (true);
        }
    return (false);
}

void generic_printf_switch_type(char const **fmt, __builtin_va_list *ap)
{
    /* Caller flag wich can override the next one */
    if (callerhandlers && handle_caller_flg(fmt, ap))
        return;
    /* handled by this generic printf */
    switch (**fmt) {
        case 's':
            generic_puts(__builtin_va_arg(*ap, char const *));
            break;
        case 'd':
            generic_base_intput(__builtin_va_arg(*ap, int), 10);
            break;
        case 'x':
            generic_base_intput(__builtin_va_arg(*ap, int), 16);
            break;
        case 'b':
            generic_base_intput(__builtin_va_arg(*ap, int), 2);
            break;
        case 'l':
            generic_base_longput(__builtin_va_arg(*ap, long), 10);
            break;
        case 'X':
            generic_base_longput(__builtin_va_arg(*ap, long), 16);
            break;
        case 'B':
            generic_base_longput(__builtin_va_arg(*ap, long), 2);
            break;
        case 'c':
            caller_putc(__builtin_va_arg(*ap, int));
            break;
        case '%':
            caller_putc('%');
            break;
        default: // unknow flag => print this
            caller_putc('%');
            caller_putc(**fmt);
    }
}

void __generic_printf(char const *fmt, __builtin_va_list ap)
{
    while (*fmt) {
        if (*fmt != '%')
                caller_putc(*fmt);
        else {
            fmt++;
            generic_printf_switch_type(&fmt, &ap);
        }
        fmt++;
    }
}

static smplock_t lock = SMPLOCK_INIT;

#define GENERIC_PRINTF_INIT()   \
    semaphore_inc(&lock);       \
    if (!putc) {                \
        semaphore_dec(&lock);   \
        return;                 \
    } else                      \
        caller_putc = putc;     \
    callerhandlers = handlers;

#define GENERIC_PRINTF_EXIT()    \
    semaphore_dec(&lock)

void generic_vprintf(void (*putc)(char), struct printfhandlers_t *handlers, 
char const *fmt, __builtin_va_list ap)
{
    GENERIC_PRINTF_INIT();
    __generic_printf(fmt, ap);
    GENERIC_PRINTF_EXIT();
}

void generic_printf(void (*putc)(char), struct printfhandlers_t *handlers, 
char const *fmt, ...)
{
    GENERIC_PRINTF_INIT();
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    __generic_printf(fmt, ap);
    __builtin_va_end(ap);
    GENERIC_PRINTF_EXIT();
}