#ifndef __UART_H_
#define __UART_H_

#include "def/typedef.h"
#include "arch/aarch64/archutils.h"
#include <stdarg.h>

// https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/BCM2835-ARM-Peripherals.pdf (P180)

#define UART_PL011_ENTRY  ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201000))

struct uart_pl011_dr_t
{
    u8_t data        : 8;
    u8_t err_framing : 1;
    u8_t err_parity  : 1;
    u8_t err_break   : 1;
    u8_t err_overrun : 1;
    u32_t _unused    : 20;
};

struct uart_pl011_rsrecr_t
{
    // Framing error. When set to 1, it indicates that the received character did not have a valid stop bit 
    u8_t err_framing : 1; 
    // Parity error. When set to 1, it indicates that the parity of the received data character does not match the parity that the EPS and SPS bits in the Line Control Register, UART_LCRH select
    u8_t err_parity  : 1;
    // Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity and stop bits). 
    u8_t err_break   : 1;
    // Overrun error. This bit is set to 1 if data is received and the receive FIFO is already full. 
    u8_t err_overrun : 1;
    u32_t _unused    : 28;
};

struct uart_pl011_fr_t
{
    u8_t  cts         : 1;
    u8_t  _unused_dsr : 1;
    u8_t  _unused_dcd : 1;
    u8_t  busy        : 1;
    u8_t  rxfe        : 1;
    u8_t  txff        : 1;
    u8_t  rxff        : 1;
    u8_t  txfe        : 1;
    u8_t  _unused_ri  : 1;
    u32_t _reserved   : 23;
};

struct uart_pl011_regs_t
{
    u32_t dr;          // Data Register
    u32_t rsrecr;      // Data Register
    u32_t _unused0;
    u32_t _unused1;
    u32_t _unused2;
    u32_t _unused3;
    u32_t fr;          // Flag Register
    u32_t _unused4;
    u32_t ILPR;        // not in use 32
    u32_t IBRD;        // Integer Baud rate divisor 32
    u32_t FBRD;        // Fractional Baud rate divisor 32
    u32_t LCRH;        // Line Control register 32
    u32_t CR;          // Control register 32
    u32_t IFLS;        // Interupt FIFO Level Select Register 32
    u32_t IMSC;        // Interupt Mask Set Clear Register 32
    u32_t RIS;         // Raw Interupt Status Register 32
    u32_t MIS;         // Masked Interupt Status Register 32
    u32_t ICR;         // Interupt Clear Register 32
    u32_t DMACR;       // DMA Control Register 32
    u32_t _unused5;
    u32_t _unused6;
    u32_t _unused7;
    u32_t _unused8;
    u32_t _unused9;
    u32_t _unused10;
    u32_t _unused11;
    u32_t _unused12;
    u32_t _unused13;
    u32_t _unused14;
    u32_t _unused15;
    u32_t _unused16;
    u32_t _unused17;
    u32_t ITCR;        // Test Control register 32
    u32_t ITIP;        // Integration test input reg 32
    u32_t ITOP;        // Integration test output reg 32
    u32_t TDR;         // Test Data reg 32 
};

void uart_init(void);
void uart_send(char);
char uart_getc(void);
void uart_puts(char const *);
void uart_hex(u32_t);
void uart_dump(void *);

void uart_kprint(char const *, ...);
void __uart_kprint(char const *, __builtin_va_list);

#endif