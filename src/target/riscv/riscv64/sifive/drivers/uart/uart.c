#include "target/riscv/riscv64/sifive/drivers/uart.h"

extern struct sifive_uart_t *uart;

void uart_putc(char c)
{
    while (uart->txdata.status != 0);
    uart->txdata.data = c;
}