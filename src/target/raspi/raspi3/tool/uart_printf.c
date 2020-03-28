#include "def/typedef.h"
#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include <stdarg.h>

void uart_base_intput(int n, int base)
{
    if (n < 0) {
        uart_send('-');
        n = n * -1;
    }
    if (n >= base)
        uart_base_intput(n / base, base);
    uart_send((n % base) + 0x30);
}

void uart_base_longput(long n, int base)
{
    if (n < 0) {
        uart_send('-');
        n = n * -1;
    }
    if (n >= base)
        uart_base_longput(n / base, base);
    uart_send((n % base) + 0x30);
}

void uart_kprint_switch_type(char const **fmt, __builtin_va_list *ap)
{
    /* FLAGS HANDLE BY THIS PRINTF */
    switch (**fmt) {
        case 's':
            uart_puts(__builtin_va_arg(*ap, char *));
            break;
        case 'd':
            uart_base_intput(__builtin_va_arg(*ap, int), 10);
            break;
        case 'x':
            uart_base_intput(__builtin_va_arg(*ap, int), 16);
            break;
        case 'l':
            uart_base_longput(__builtin_va_arg(*ap, long), 10);
            break;
        case 'X':
            uart_base_longput(__builtin_va_arg(*ap, long), 16);
            break;
        case 'b':
            uart_base_longput(__builtin_va_arg(*ap, long), 2);
            break;
        case 'c':
            uart_send(__builtin_va_arg(*ap, int));
            break;
        case '%':
            uart_send('%');
            break;
        default: // unknow flag => print this
            uart_send('%');
            uart_send(**fmt);
    }
}

void __uart_kprint(char const *fmt, __builtin_va_list ap)
{
    while (*fmt) {
        if (*fmt != '%')
            uart_send(*fmt);
        else {
            fmt++;
            uart_kprint_switch_type(&fmt, &ap);
        }
        fmt++;
    }
}

static smplock_t lock = SMPLOCK_INIT;

void uart_kprint(char const *fmt, ...)
{
    semaphore_inc(&lock);
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    __uart_kprint(fmt, ap);
    __builtin_va_end(ap);
    semaphore_dec(&lock);
}