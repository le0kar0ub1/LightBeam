#include "lightbeam.h"
#include "target/arm/raspi/common/bcm283X/uart-pl011.h"
#include "kernel/init/initcalls.h"

volatile struct uart_pl011_regs_t *uartpl011regs __aligned(16);

static void bcm283x_uartpl011_init(void)
{
    uartpl011regs = (struct uart_pl011_regs_t *)BCM283x_UART_PL011_ENTRY;
}

boot_initcall(bcm283x_uartpl011_init);