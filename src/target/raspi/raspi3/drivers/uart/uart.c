#include "target/raspi/raspi3/driver/gpio.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/driver/uart.h"

void uart_init(void)
{
    bcm2837_uartpl011_disable();
    bcm2837_uartpl011_mappin(14);
    bcm2837_uartpl011_mappin(15);
    bcm2837_uartpl011_clear_transmit_interrupt();
    bcm2837_uartpl011_clear_receive_interrupt();
    bcm2837_uartpl011_set_baudrate_divisor(2);
    bcm2837_uartpl011_set_fractionnal_baudrate_divisor(0xB);
    bcm2837_mbox_clock_set_rate(MBOX_CLOCK_ID_UART, 4000000);
    bcm2837_uartpl011_set_wlen(UARTPLO11_WLEN_8);
    bcm2837_uartpl011_set_transmit_state(true);
    bcm2837_uartpl011_set_receive_state(true);
    bcm2837_uartpl011_enable();
}

void uart_putc(char c)
{
    while(bcm2837_uartpl011_isTransmiterFull());
    bcm2837_uartpl011_send_data_nonfifo(c);
}

char uart_getc(void)
{
    while(bcm2837_uartpl011_isReceiverFull());
    return (bcm2837_uartpl011_get_data_nonfifo());
}

void uart_puts(char const *s)
{
    while (*s) {
        uart_putc(*s);
        s++;
    }
}

