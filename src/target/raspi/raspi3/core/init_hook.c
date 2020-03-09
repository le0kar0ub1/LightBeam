#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"

extern uchar __end;

void init_hook(void)
{
    uart_init();
    irq_vector_init();
    // timer_init();
    enable_interrupt_controller();
    enable_irq();
    lfb_init();

    uart_kprint("%s, ESR: %x, address: %x\r\n", "yeeees", 0x10, 0x20);
    while(1);
    int *a = 0;
    *a = 0;
    uart_puts("HELLO WORLD!\n");


    for (int i = 0; i < 20; i++)
        lfb_print(10, 5 + i, "Hello, framebuffer world!\n");
    while(1)
        uart_send(uart_getc());
}