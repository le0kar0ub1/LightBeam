#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/interrupt.h"

extern uchar __end;

void init_hook(void)
{
    uart_init();

    irq_vector_init();
    timer_init();
    enable_interrupt_controller();
    enable_irq();

    uart_puts("Hello, serial world!\n");

    lfb_init();
    lfb_kprint("Hello, framebuffer world!\n", RGB_Cyan);
    while(1)
        uart_send(uart_getc());
}