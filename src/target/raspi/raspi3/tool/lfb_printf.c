#include "def/typedef.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/semaphore.h"
#include <stdarg.h>

static volatile bool iserasing;

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
        case 'b':
            lfb_base_intput(__builtin_va_arg(*ap, int), 2);
            break;
        case 'l':
            lfb_base_longput(__builtin_va_arg(*ap, long), 10);
            break;
        case 'X':
            lfb_base_longput(__builtin_va_arg(*ap, long), 16);
            break;
        case 'B':
            lfb_base_longput(__builtin_va_arg(*ap, long), 2);
            break;
        case 'c':
            lfb_putchar(__builtin_va_arg(*ap, int));
            break;
        case '%':
            lfb_putchar('%');
            break;
        /* special use-case */
        case '$':
            (*fmt)++;
            if (**fmt == 'A') {
                lfb_set_color(RGB_Black, __builtin_va_arg(*ap, uint));
            } else if (**fmt == 'R') {
                lfb_set_color(RGB_Black, RGB_White);
            }
            break;
        default: // unknow flag => print this
            lfb_putchar('%');
            lfb_putchar(**fmt);
    }
}

void __lfb_kprint(char const *fmt, __builtin_va_list ap)
{
    int posx = lfb_get_posx();
    int posy = lfb_get_posy();
    iserasing = true;

    while (*fmt) {
        if (*fmt != '%')
            if (*fmt == '\r')
                iserasing = false;
            else
                lfb_putchar(*fmt);
        else {
            fmt++;
            lfb_kprint_switch_type(&fmt, &ap);
        }
        fmt++;
    }
    if (!iserasing)
        lfb_set_pos(posx, posy);
}

static smplock_t lock = SMPLOCK_INIT;

void lfb_kprint(char const *fmt, ...)
{
    semaphore_inc(&lock);
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    __lfb_kprint(fmt, ap);
    __builtin_va_end(ap);
    semaphore_dec(&lock);
}