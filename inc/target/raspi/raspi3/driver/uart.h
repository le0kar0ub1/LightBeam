#ifndef __UART_H_
#define __UART_H_

#include "def/typedef.h"
#include "arch/aarch64/archutils.h"

enum WLEN
{
    UARTPLO11_WLEN_5 = 0b00,
    UARTPLO11_WLEN_6 = 0b01,
    UARTPLO11_WLEN_7 = 0b10,
    UARTPLO11_WLEN_8 = 0b11
};

enum FIFO_IO
{
    FIFOTX_12perc = 0b000,
    FIFOTX_25perc = 0b001,
    FIFOTX_50perc = 0b010,
    FIFOTX_75perc = 0b011,
    FIFOTX_88perc = 0b100
};

void uart_kprint(char const *, ...);

void uart_init(void);
void uart_putc(char);
char uart_getc(void);
void uart_puts(char const *);

void bcm2837_uartpl011_init(void);
void *bcm2837_uartpl011_get_entrypoint(void);

/*
** Data register & sub Data register
*/ 
char bcm2837_uartpl011_get_data_nonfifo(void);
char bcm2837_uartpl011_safeget_data_nonfifo(void);
void bcm2837_uartpl011_send_data_nonfifo(char);
void bcm2837_uartpl011_send_data_fifo(char *, size_t);
char const *bcm2837_uartpl011_safesend_data_nonfifo(char);
char const *bcm2837_uartpl011_safesend_data_fifo(char *, size_t);
char const *bcm2837_uartpl011_error_checkup(void);

/*
** Control Register
*/
void bcm2837_uartpl011_disable(void);
void bcm2837_uartpl011_enable(void);
void bcm2837_uartpl011_setstate(bool);
void bcm2837_uartpl011_set_transmit_state(bool);
void bcm2837_uartpl011_set_receive_state(bool);
void bcm2837_uartpl011_set_loopback_state(bool);

/*
** Flag register
*/ 
bool bcm2837_uartpl011_isTransmiterEmpty(void);
bool bcm2837_uartpl011_isReceiverEmpty(void);
bool bcm2837_uartpl011_isTransmiterFull(void);
bool bcm2837_uartpl011_isReceiverFull(void);

/*
**  Clear interrupt register
*/
void bcm2837_uartpl011_clear_transmit_interrupt(void);
void bcm2837_uartpl011_clear_receive_interrupt(void);

/*
** Pin mapp/unmapp
*/
void bcm2837_uartpl011_mappin(u32_t pin);

/*
** baud rate divisor register
*/
u32_t bcm2837_uartpl011_get_baudrate_divisor(void);
void bcm2837_uartpl011_set_baudrate_divisor(u32_t);

/*
** fractionnal baud rate divisor register
*/
u32_t bcm2837_uartpl011_get_fractionnal_baudrate_divisor(void);
void bcm2837_uartpl011_set_fractionnal_baudrate_divisor(u32_t);

/*
** Line control register
*/
void bcm2837_uartpl011_send_break(void);
void bcm2837_uartpl011_set_parity(bool);
void bcm2837_uartpl011_set_fifo(bool);
void bcm2837_uartpl011_set_wlen(enum WLEN);

void uart_kprint(char const *, ...);

#endif