#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/driver/mbox.h"
#include "target/raspi/raspi3/delay.h"
#include "target/raspi/raspi3/uart.h"

void uart_init(void)
{
    register uint r;

    /* initialize UART */
    *UART0_CR = 0;         // turn off UART0

    /* set up clock for consistent divisor values */
    mbox[0] = 9 * 4;
    mbox[1] = MBOX_REQUEST;
    mbox[2] = MBOX_TAG_SETCLKRATE; // set clock rate
    mbox[3] = 12;
    mbox[4] = 8;
    mbox[5] = 2;           // UART clock
    mbox[6] = 4000000;     // 4Mhz
    mbox[7] = 0;           // clear turbo
    mbox[8] = MBOX_TAG_LAST;
    mbox_call(MBOX_CH_PROP);

    /* map UART0 to GPIO pins */
    r =* GPFSEL1;
    r &= ~((7 << 12) | (7 << 15)); // gpio14, gpio15
    r |= (4 << 12) | (4 << 15);    // alt0
    *GPFSEL1 = r;
    *GPPUD0 = 0;            // enable pins 14 and 15
    wait_cycles(150);
    *GPPUDCLK0 = (1 << 14) | (1 << 15);
    wait_cycles(150);
    *GPPUDCLK0 = 0;        // flush GPIO setup

    *UART0_ICR = 0x7FF;    // clear interrupts
    *UART0_IBRD = 2;       // 115200 baud
    *UART0_FBRD = 0xB;
    *UART0_LCRH = 0b11 << 5; // 8n1
    *UART0_CR = 0x301;     // enable Tx, Rx, FIFO
}

/**
 * Send a character
 */
void uart_send(uint c)
{
    /* wait until we can send */
    while(*UART0_FR & 0x20)
        asm volatile("nop");
    /* write the character to the buffer */
    *UART0_DR = c;
}

/**
 * Receive a character
 */
char uart_getc(void)
{
    char r;
    /* wait until something is in the buffer */
    while(*UART0_FR & 0x10)
        asm volatile("nop");
    /* read it and return */
    r = (char)(*UART0_DR);
    /* convert carrige return to newline */
    return (r == '\r' ? '\n': r);
}

/**
 * Display a string
 */
void uart_puts(char const *s)
{
    while(*s) {
        if(*s == '\n')
            uart_send('\r');
        uart_send(*s++);
    }
}

/**
 * Display a binary value in hexadecimal
 */
void uart_hex(uint d)
{
    uint n;

    for(int c = 28 ; c >= 0;c -= 4) {
        n = (d >> c) & 0xF;
        n += n > 9 ? 0x37 : 0x30;
        uart_send(n);
    }
}

/**
 * Dump memory
 */
void uart_dump(void *ptr)
{
    ulong a, b, d;
    uchar c;

    for (a = (ulong)ptr;a < (ulong) ptr + 512; a += 16) {
        uart_hex(a); uart_puts(": ");
        for (b = 0; b < 16; b++) {
            c = *((uchar*)(a + b));
            d = ((uint)c >> 4) & 0xF;
            d += d > 9 ? 0x37 : 0x30;
            uart_send(d);
            d = (uint)c;
            d &= 0xF; d += d > 9 ? 0x37 : 0x30;
            uart_send(d);
            uart_send(' ');
            if(b % 4 == 3)
                uart_send(' ');
        }
        for (b = 0; b < 16; b++) {
            c = *((uchar*)(a + b));
            uart_send(c < 32 || c >= 127 ? '.' : c);
        }
        uart_send('\r');
        uart_send('\n');
    }
}