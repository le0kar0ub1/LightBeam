#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"

extern uchar __end;

#define COUNTER_SECTOR 1

void init_hook(void)
{
    // use the last 4 bytes on the second sector as a boot counter
    // uint *counter = (uint*)(&__end + 508);
    uart_init();

    int *a = 0;
    *a = 0;
    uart_puts("HELLO WORLD!\n");

    lfb_init();

    for (int i = 0; i < 20; i++)
        lfb_print(10, 5 + i, "Hello, framebuffer world!\n");
    while(1)
        uart_send(uart_getc());
}