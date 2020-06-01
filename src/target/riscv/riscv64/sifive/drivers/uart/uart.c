#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "kernel/schedule/semaphore.h"

extern struct sifive_uart_t *uart;

void uart_putc(char c)
{
    while (uart->txdata.status != 0);
    uart->txdata.data = c;
}

char uart_getc(void)
{
    while (uart->rxdata.status != 0);
    return (uart->rxdata.data);
}

void uart_puts(char const *s)
{
    while (*s)
        uart_putc(*s++);
}

static smplock_t lock = SMPLOCK_INIT();

void uart_szputs(char const *s, size_t sz)
{
    smp_inc(&lock);
    for (size_t i = 0; i < sz; i++)
        uart_putc(s[i]);
    smp_dec(&lock);
}