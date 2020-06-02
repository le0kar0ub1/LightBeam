#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "arch/riscv/spinlock.h"

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

static spinlock_t lock = SPINLOCK_INIT();

void uart_szputs(char const *s, size_t sz)
{
    arch_spin_lock(&lock);
    for (size_t i = 0; i < sz; i++)
        uart_putc(s[i]);
    arch_spin_unlock(&lock);
}