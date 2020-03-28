#include "def/typedef.h"
#include "arch/overworld/overworld.h"
#include "target/raspi/raspi3/semaphore.h"
#include <stdarg.h>

static void (*assigned_putc)(char) = NULL;

static smplock_t lock = SMPLOCK_INIT;

void generic_base_intput(int n, int base)
{
    if (n < 0) {
        assigned_putc('-');
        n = n * -1;
    }
    if (n >= base)
        generic_base_intput(n / base, base);
    assigned_putc((n % base) + 0x30);
}

void generic_base_longput(long n, int base)
{
    if (n < 0) {
        assigned_putc('-');
        n = n * -1;
    }
    if (n >= base)
        generic_base_longput(n / base, base);
    assigned_putc((n % base) + 0x30);
}

void generic_puts(char const *s)
{
    for (int i = 0; s[i]; i++)
        assigned_putc(s[i]);
}

void generic_printf_switch_type(char const **fmt, __builtin_va_list *ap)
{
    /* FLAGS HANDLE BY THIS PRINTF */
    switch (**fmt) {
        case 's':
            generic_puts(__builtin_va_arg(*ap, char *));
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
            assigned_putc(__builtin_va_arg(*ap, int));
            break;
        case '%':
            assigned_putc('%');
            break;
        default: // unknow flag => print this
            assigned_putc('%');
            assigned_putc(**fmt);
    }
}

void __generic_printf(char const *fmt, __builtin_va_list ap)
{
    while (*fmt) {
        if (*fmt != '%')
                assigned_putc(*fmt);
        else {
            fmt++;
            generic_printf_switch_type(&fmt, &ap);
        }
        fmt++;
    }
}

void generic_printf(void (*putc)(char), char const *fmt, ...)
{
    if (!putc)
        return;
    else
        assigned_putc = putc;
    semaphore_inc(&lock);
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    __generic_printf(fmt, ap);
    __builtin_va_end(ap);
    semaphore_dec(&lock);
}