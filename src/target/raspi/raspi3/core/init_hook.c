#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/interrupt.h"

extern uchar __end;

void init_hook(void)
{
    uart_init();
    uart_puts("Hello, serial world!\n");

    irq_vector_init();
    timer_init();
    enable_interrupt_controller();
    enable_irq();

    lfb_init();
    lfb_clear_rect();
    lfb_print(0, 0, "Hello, framebuffer world!\n");
    while(1)
        uart_send(uart_getc());
}