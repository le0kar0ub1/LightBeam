#ifndef __UART_H_
#define __UART_H_

#include "def/typedef.h"
#include "arch/aarch64/archutils.h"
#include <stdarg.h>

#define UART_PL011_ENTRY  ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201000))

struct uart_pl011_regs_t {
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