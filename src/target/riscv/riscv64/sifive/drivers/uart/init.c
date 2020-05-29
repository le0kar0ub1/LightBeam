#include "target/riscv/riscv64/sifive/drivers/uart.h"

volatile struct sifive_uart_t *uart = NULL;

static void uart_init(void)
{
    uart = (struct sifive_uart_t *)SOC_MMAP_START_RWA_UART0;
    uart->txctrl.txen = true;
    uart->rxctrl.rxen = true;
    uart->div.div = 16000;
}

boot_initcall(uart_init);