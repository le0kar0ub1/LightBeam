#ifndef __UART_H_
#define __UART_H_

#include "def/typedef.h"
#include "arch/aarch64/archutils.h"
#include <stdarg.h>

#define UART0_DR        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201000))
#define UART0_FR        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201018))
#define UART0_IBRD      ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201024))
#define UART0_FBRD      ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201028))
#define UART0_LCRH      ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x0020102C))
#define UART0_CR        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201030))
#define UART0_IMSC      ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201038))
#define UART0_ICR       ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201044))

void uart_init(void);
void uart_send(u32_t);
char uart_getc(void);
void uart_puts(char const *);
void uart_hex(u32_t);
void uart_dump(void *);

void uart_kprint_switch_type(char const **, __builtin_va_list *);
void uart_kprint(char const *, ...);
void __uart_kprint(char const *, __builtin_va_list);
void uart_base_intput(int, int);
void uart_base_longput(long, int);


#endif