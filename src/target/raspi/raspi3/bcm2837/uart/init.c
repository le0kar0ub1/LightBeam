#include "lightbleam.h"
#include "target/raspi/raspi3/bcm2837/uart-pl011.h"

#pragma message "initcall me"

volatile struct uart_pl011_regs_t *uartpl011regs __aligned(4);

void uartpl011_bcm2837_init(void)
{
    uartpl011regs = (struct uart_pl011_regs_t *)UART_PL011_ENTRY;
}