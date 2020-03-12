#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/system.h"

extern uchar __end;

void init_hook(void)
{
    uart_init();

    lfb_init();
    helloFromLightBleam();

    lfb_puts("Initializing interrupts [vectors, irq, etc.]...\n");
    irq_vector_init();
    timer_init();
    enable_interrupt_controller();
    enable_irq();

    lfb_puts("Initializing all CPUS...\n");
    multicore_init();
    lfb_puts("    All CPUS acquired start!\n");

    while(1)
        uart_send(uart_getc());
}