#include "target/riscv/riscv64/drivers/serial.h"


enum {
    /* UART Registers */
    UART_REG_TXFIFO = 0,
    UART_REG_RXFIFO = 1,
    UART_REG_TXCTRL = 2,
    UART_REG_RXCTRL = 3,
    UART_REG_IE     = 4,
    UART_REG_IP     = 5,
    UART_REG_DIV    = 6,

    /* TXCTRL register */
    UART_TXEN       = 1,
    UART_TXSTOP     = 2,

    /* RXCTRL register */
    UART_RXEN       = 1,

    /* IP register */
    UART_IP_TXWM    = 1,
    UART_IP_RXWM    = 2
};


static volatile u32_t *uart = (volatile u32_t *) 0x92000000;

int serial_putchar(char c)
{
    while (uart[UART_REG_TXFIFO] < 0);
    return uart[UART_REG_TXFIFO] = c & 0xff;
}

void serial_init(void)
{
    uart = (u32_t *)0x10000000;
    uint32_t uart_freq = 1843200;
    uint32_t baud_rate = 115200;
    uint32_t divisor = uart_freq / baud_rate - 1;
    uart[UART_REG_DIV] = divisor;
    uart[UART_REG_TXCTRL] = UART_TXEN;
    uart[UART_REG_RXCTRL] = UART_RXEN;
    uart[UART_REG_IE] = 0;
    while (1)
        serial_putchar('A');
}
