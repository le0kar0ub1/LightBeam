#include "def/typedef.h"
#include "target/raspi/raspi3/uart.h"
#include "stdarg.h"

int64 uart_power(int64 max, int power)
{
    int64 ret = power;

    for (; max != 0x2; max--)
        ret *= power;
    return (ret);
}

void uart_putchar(char c)
{
    uart_send(c);
}

void uart_hexa_put(int64 n)
{
    int64 max = 0x0, ch = 0x0, save = n;

    uart_puts("0x");
    for (; n / 0x10 > 0; n /= 0x10, max++);
    for (; (int64)max >= 0; max--) {
        ch = n % 0x10;
        if (ch > 0x9)
            uart_putchar(0x41 + (ch - 0xA));
        else
            uart_putchar(ch + 0x30);
        if (max == 0x0 || max == 0x1)
            n = save;
        else
            n = save / uart_power(max, 0x10);
    }
}

void uart_bin_put(int64 n)
{
    int64 max = 0x0, ch = 0x0, save = n;

    if (n < 0) {
        uart_putchar('-');
        n *= -0x1;
    }
    uart_puts("0b");
    for (; n / 0x2 > 0; n /= 0x2, max++);
    for (; max >= 0; max--) {
        ch = n % 0x2;
        uart_putchar(ch + 0x30);
        if (max == 0x0 || max == 0x1)
            n = save;
        else
            n = save / uart_power(max, 0x2);
    }
}

void uart_int_put(int n)
{
    int mod = 0xA, sub = 0x0, cur = 0x0;

    if (n < 0x0) {
        uart_putchar('-');
        n *= -0x1;
    }
    for (; n % mod != n; mod *= 0XA);
    for (; mod != 0x1; mod /= 0xA) {
        sub = (n % (mod / 0xA));
        cur = ((n % mod) - sub) / (mod / 0XA);
        uart_putchar(cur + 0x30);
    }
}

void uart_long_put(int64 n)
{
    int64 mod = 0xA, sub = 0x0, cur = 0x0;

    if (n < 0x0) {
        uart_putchar('-');
        n *= -0x1;
    }
    for (; n % mod != n; mod *= 0XA);
    for (; mod != 0x1; mod /= 0xA) {
        sub = (n % (mod / 0xA));
        cur = ((n % mod) - sub) / (mod / 0XA);
        uart_putchar(cur + 0x30);
    }
}

void uart_float_put(double n, int prec)
{
    int zero = 0x0;
    int64 part = (int64)n;

    if (prec > 0x9 || prec < 0x0)
        return;
    if (n < 0x0) {
        n *= -0x1;
        uart_putchar('-');
        part = (int64)n;
    }
    prec = uart_power(prec + 1, 0xA);
    uart_long_put(part);
    n = n - part;
    uart_putchar(',');
    if ((int64)(n * 0xA) == 0x0) {
        for (double tmp = n; tmp != 0x0 && (int64)tmp == 0x0; zero++, tmp *= 0xA);
        for (; zero > 0x1; zero--)
            uart_putchar(0x30);
    }
    n *= prec;
    uart_long_put((int64)n);
}

void uart_switch_types(char const *format, va_list ap, int *i)
{
    /* FLAGS HANDLE BY THIS PRINTF */
    switch (format[*i]) {
        case 's':
            uart_puts(va_arg(ap, char *));
            break;
        case 'd':
            uart_int_put(va_arg(ap, int));
            break;
        case 'x':
            uart_hexa_put(va_arg(ap, int64));
            break;
        case 'l':
            uart_long_put(va_arg(ap, int64));
            break;
        case 'c':
            uart_putchar(va_arg(ap, int));
            break;
        case 'b':
            uart_bin_put(va_arg(ap, int64));
            break;
        case '%':
            uart_putchar('%');
            break;
        case 'f':
            uart_float_put(va_arg(ap, double), format[*i + 0x1] - 0x30);
            *i += 0x1;
            break;
        default: // unknow flag => print this
            uart_putchar('%');
            uart_putchar(format[*i]);
    }
}

void uart_kprint(char const *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0x0; format[i] ; i++) {
        if (format[i] != '%')
            uart_putchar(format[i]);
        else {
            i++;
            uart_switch_types(format, ap, &i);
        }
    }
    va_end(ap);
}