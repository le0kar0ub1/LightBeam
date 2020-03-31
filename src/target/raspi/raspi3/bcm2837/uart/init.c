#include "lightbleam.h"
#include "target/raspi/raspi3/bcm2837/uart_pl011.h"
#include "kernel/init/initcalls.h"

#pragma message "initcall me"

volatile struct uart_pl011_regs_t *uartpl011regs __aligned(16);

void bcm2837_uartpl011_init(void)
{
    uartpl011regs = (struct uart_pl011_regs_t *)UART_PL011_ENTRY;
}

boot_initcall(bcm2837_uartpl011_init);