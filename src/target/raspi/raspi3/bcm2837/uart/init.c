#include "lightbleam.h"
#include "target/raspi/raspi3/bcm2837/uart-pl011.h"

#pragma message "initcall me"

volatile struct uart_pl011_regs_t *uartregs __aligned(4);

void gpio_init(void)
{
    uartregs = (struct uart_pl011_regs_t *)UART_PL011_ENTRY;
}