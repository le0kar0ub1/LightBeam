#ifndef __UART_H_
#define __UART_H_

#include "def/typedef.h"
#include "arch/aarch64/aarchutils.h"
#include <stdarg.h>

#define UART0_DR        ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201000))
#define UART0_FR        ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201018))
#define UART0_IBRD      ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201024))
#define UART0_FBRD      ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201028))
#define UART0_LCRH      ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x0020102C))
#define UART0_CR        ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201030))
#define UART0_IMSC      ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201038))
#define UART0_ICR       ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00201044))

void uart_init(void);
void uart_send(uint);
char uart_getc(void);
void uart_puts(char const *s);
void uart_hex(uint d);
void uart_dump(void *ptr);

void uart_kprint_switch_type(char const **, __builtin_va_list *);
void uart_kprint(char const *, ...);
void __uart_kprint(char const *, __builtin_va_list);
void uart_base_intput(int, int);
void uart_base_longput(long, int);


#endif