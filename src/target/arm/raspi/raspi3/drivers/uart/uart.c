#include "kernel/schedule/semaphore.h"
#include "target/arm/raspi/raspi3/drivers/gpio.h"
#include "target/arm/raspi/common/bcm283X/mbox.h"
#include "target/arm/raspi/raspi3/drivers/uart.h"

void uart_init(void)
{
    bcm283x_uartpl011_disable();
    bcm283x_uartpl011_mappin(14);
    bcm283x_uartpl011_mappin(15);
    bcm283x_uartpl011_clear_transmit_interrupt();
    bcm283x_uartpl011_clear_receive_interrupt();
    bcm283x_uartpl011_set_baudrate_divisor(2);
    bcm283x_uartpl011_set_fractionnal_baudrate_divisor(0xB);
    bcm283x_mbox_clock_set_rate(MBOX_CLOCK_ID_UART, 4000000);
    bcm283x_uartpl011_set_wlen(UARTPLO11_WLEN_8);
    bcm283x_uartpl011_set_transmit_state(true);
    bcm283x_uartpl011_set_receive_state(true);
    bcm283x_uartpl011_enable();
}

static void uart_putc(char c)
{
    while(bcm283x_uartpl011_isTransmiterFull());
    bcm283x_uartpl011_send_data_nonfifo(c);
}

char uart_getc(void)
{
    while(bcm283x_uartpl011_isReceiverFull());
    return (bcm283x_uartpl011_get_data_nonfifo());
}

static smplock_t lock = SMPLOCK_INIT();

void uart_szputs(char const *s, size_t sz)
{
    semaphore_inc(&lock);
    for (u32_t i = 0x0; s[i] && i < sz; i++)
        uart_putc(s[i]);
    semaphore_dec(&lock);
}
