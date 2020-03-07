#include "def/typedef.h"
#include "target/raspi/driver/gpio.h"
#include "target/raspi/raspi1/proto.h"

void init_hook(void)
{
    uart_init();
    uart_send_string("Hello, world!\r\n");

    while (1) {
        uart_send(uart_recv());
    }
}