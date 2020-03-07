#ifndef _RASPI_SHARED_
#define _RASPI_SHARED_

#include "def/typedef.h"

void kernel(void);
void uart_init(void);
void uart_putc(uchar);
uchar uart_getc(void);
void uart_puts(const char *);

void delay(uint);
int get32(int);
void put32(int, int);

#define GPFSEL1         (ARCH_RASP_MMIOBASE + 0x00200004)
#define GPSET0          (ARCH_RASP_MMIOBASE + 0x0020001C)
#define GPCLR0          (ARCH_RASP_MMIOBASE + 0x00200028)
#define GPPUD           (ARCH_RASP_MMIOBASE + 0x00200094)
#define GPPUDCLK0       (ARCH_RASP_MMIOBASE + 0x00200098)

#define AUX_ENABLES     (ARCH_RASP_MMIOBASE + 0x00215004)
#define AUX_MU_IO_REG   (ARCH_RASP_MMIOBASE + 0x00215040)
#define AUX_MU_IER_REG  (ARCH_RASP_MMIOBASE + 0x00215044)
#define AUX_MU_IIR_REG  (ARCH_RASP_MMIOBASE + 0x00215048)
#define AUX_MU_LCR_REG  (ARCH_RASP_MMIOBASE + 0x0021504C)
#define AUX_MU_MCR_REG  (ARCH_RASP_MMIOBASE + 0x00215050)
#define AUX_MU_LSR_REG  (ARCH_RASP_MMIOBASE + 0x00215054)
#define AUX_MU_MSR_REG  (ARCH_RASP_MMIOBASE + 0x00215058)
#define AUX_MU_SCRATCH  (ARCH_RASP_MMIOBASE + 0x0021505C)
#define AUX_MU_CNTL_REG (ARCH_RASP_MMIOBASE + 0x00215060)
#define AUX_MU_STAT_REG (ARCH_RASP_MMIOBASE + 0x00215064)
#define AUX_MU_BAUD_REG (ARCH_RASP_MMIOBASE + 0x00215068)

// enum
// {
//     /* define in compile time macro */
//     GPIO_BASE = 0x200000,
 
//     // Controls actuation of pull up/down to ALL GPIO pins.
//     GPPUD = (GPIO_BASE + 0x94),
 
//     // Controls actuation of pull up/down for specific GPIO pin.
//     GPPUDCLK0 = (GPIO_BASE + 0x98),
 
//     // The base address for UART.
//     UART0_BASE = (GPIO_BASE + 0x1000),
 
//     // The offsets for reach register for the UART.
//     UART0_DR     = (UART0_BASE + 0x00),
//     UART0_RSRECR = (UART0_BASE + 0x04),
//     UART0_FR     = (UART0_BASE + 0x18),
//     UART0_ILPR   = (UART0_BASE + 0x20),
//     UART0_IBRD   = (UART0_BASE + 0x24),
//     UART0_FBRD   = (UART0_BASE + 0x28),
//     UART0_LCRH   = (UART0_BASE + 0x2C),
//     UART0_CR     = (UART0_BASE + 0x30),
//     UART0_IFLS   = (UART0_BASE + 0x34),
//     UART0_IMSC   = (UART0_BASE + 0x38),
//     UART0_RIS    = (UART0_BASE + 0x3C),
//     UART0_MIS    = (UART0_BASE + 0x40),
//     UART0_ICR    = (UART0_BASE + 0x44),
//     UART0_DMACR  = (UART0_BASE + 0x48),
//     UART0_ITCR   = (UART0_BASE + 0x80),
//     UART0_ITIP   = (UART0_BASE + 0x84),
//     UART0_ITOP   = (UART0_BASE + 0x88),
//     UART0_TDR    = (UART0_BASE + 0x8C),
// };

#endif