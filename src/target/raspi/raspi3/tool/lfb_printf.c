#include "def/typedef.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include <stdarg.h>

void lfb_base_intput(int n, int base)
{
    if (n < 0) {
        lfb_putchar('-');
        n = n * -1;
    }
    if (n >= base)
        lfb_base_intput(n / base, base);
    lfb_putchar((n % base) + 0x30);
}

void lfb_base_longput(long n, int base)
{
    if (n < 0) {
        lfb_putchar('-');
        n = n * -1;
    }
    if (n >= base)
        lfb_base_longput(n / base, base);
    lfb_putchar((n % base) + 0x30);
}

void lfb_kprint_switch_type(char const **fmt, __builtin_va_list *ap)
{
    /* FLAGS HANDLE BY THIS PRINTF */
    switch (**fmt) {
        case 's':
            lfb_puts(__builtin_va_arg(*ap, char *));
            break;
        case 'd':
            lfb_base_intput(__builtin_va_arg(*ap, int), 10);
            break;
        case 'x':
            lfb_base_intput(__builtin_va_arg(*ap, int), 16);
            break;
        case 'l':
            lfb_base_longput(__builtin_va_arg(*ap, long), 10);
            break;
        case 'X':
            lfb_base_longput(__builtin_va_arg(*ap, long), 16);
            break;
        case 'b':
            lfb_base_longput(__builtin_va_arg(*ap, long), 2);
            break;
        case 'c':
            lfb_putchar(__builtin_va_arg(*ap, int));
            break;
        case '%':
            lfb_putchar('%');
            break;
        default: // unknow flag => print this
            lfb_putchar('%');
            lfb_putchar(**fmt);
    }
}

void lfb_kprint(char const *fmt, ...)
{
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    while (*fmt) {
        if (*fmt != '%')
            lfb_putchar(*fmt);
        else {
            fmt++;
            lfb_kprint_switch_type(&fmt, &ap);
        }
        fmt++;
    }
    __builtin_va_end(ap);
}