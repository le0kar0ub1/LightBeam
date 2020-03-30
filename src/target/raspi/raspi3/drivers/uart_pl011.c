#include "target/raspi/raspi3/driver/gpio.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/bcm2837/uart_pl011.h"

void uart_init(void)
{
    uartpl011_bcm2837_disable();

    /* set up clock for consistent divisor values */
    bcm2837_mbox_clock_set_rate(MBOX_CLOCK_ID_UART, 4000000);

    uartpl011_bcm2837_mappin(14);
    uartpl011_bcm2837_mappin(15);
    // /* map UART0 to GPIO pins */
    // r =* GPFSEL1;
    // r &= ~((7 << 12) | (7 << 15)); // gpio14, gpio15
    // r |= (4 << 12) | (4 << 15);    // alt0
    // *GPFSEL1 = r;
    // *GPPUD0 = 0;            // enable pins 14 and 15
    // wait_cycles(150);
    // *GPPUDCLK0 = (1 << 14) | (1 << 15);
    // wait_cycles(150);
    // *GPPUDCLK0 = 0;        // flush GPIO setup

    uartpl011_bcm2837_clear_transmit_interrupt();
    uartpl011_bcm2837_clear_receive_interrupt();

    uartpl011_bcm2837_set_baudrate_divisor(2);
    uartpl011_bcm2837_set_fractionnal_baudrate_divisor(0xB);
    uartpl011_bcm2837_set_wlen(UARTPLO11_WLEN_8);
    uartpl011_bcm2837_set_transmit_state(true);
    uartpl011_bcm2837_set_receive_state(true);
    uartpl011_bcm2837_enable();
    // *UART0_ICR = 0x7FF;    // clear interrupts
    // *UART0_IBRD = 2;       // 115200 baud
    // *UART0_FBRD = 0xB;
    // *UART0_LCRH = 0b11 << 5; // 8n1
    // *UART0_CR = 0x301;     // enable Tx, Rx, FIFO
}

// /**
//  * Send a character
//  */
void uart_send(char c)
{
    while(uartpl011_bcm2837_isTransmiterFull());
    uartpl011_bcm2837_send_data_nonfifo(c);
}

// /**
//  * Receive a character
//  */
// char uart_getc(void)
// {
//     char r;
//     /* wait until something is in the buffer */
//     while(*UART0_FR & 0x10)
//         asm volatile("nop");
//     /* read it and return */
//     r = (char)(*UART0_DR);
//     /* convert carrige return to newline */
//     return (r == '\r' ? '\n': r);
// }

// /**
//  * Display a string
//  */
void uart_puts(char const *s)
{
    while(*s) {
        if(*s == '\n')
            uart_send('\r');
        uart_send(*s++);
    }
}

// /**
//  * Display a binary value in hexadecimal
//  */
// void uart_hex(u32_t d)
// {
//     u32_t n;

//     for(int c = 28 ; c >= 0;c -= 4) {
//         n = (d >> c) & 0xF;
//         n += n > 9 ? 0x37 : 0x30;
//         uart_send(n);
//     }
// }