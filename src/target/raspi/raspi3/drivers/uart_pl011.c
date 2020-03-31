#include "target/raspi/raspi3/driver/gpio.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/bcm2837/uart_pl011.h"

void uart_init(void)
{
    uartpl011_bcm2837_disable();
    uartpl011_bcm2837_mappin(14);
    uartpl011_bcm2837_mappin(15);
    uartpl011_bcm2837_clear_transmit_interrupt();
    uartpl011_bcm2837_clear_receive_interrupt();
    uartpl011_bcm2837_set_baudrate_divisor(2);
    bcm2837_mbox_clock_set_rate(MBOX_CLOCK_ID_UART, 4000000);
    uartpl011_bcm2837_set_fractionnal_baudrate_divisor(0xB);
    uartpl011_bcm2837_set_wlen(UARTPLO11_WLEN_8);
    uartpl011_bcm2837_set_transmit_state(true);
    uartpl011_bcm2837_set_receive_state(true);
    uartpl011_bcm2837_enable();
    uartpl011_bcm2837_disable();
}

void uart_putc(char c)
{
    while(uartpl011_bcm2837_isTransmiterFull());
    uartpl011_bcm2837_send_data_nonfifo(c);
}

char uart_getc(void)
{
    while(uartpl011_bcm2837_isReceiverFull());
    return (uartpl011_bcm2837_get_data_nonfifo());
}

void uart_puts(char const *s)
{
    while (*s++)
        uart_putc(*s);
}

