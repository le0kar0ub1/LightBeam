#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "def/typedef.h"

void int_handler(uint64, uint64, uint64, uint64, uint64);
void vectors_init(void);
void enable_interrupts(void);
void disable_irq(void);
void handle_except_msg(int, uint64, uint64);
void handle_irq(void);

#define IRQ_BASIC_PENDING   (ARCH_RASP_MMIOBASE + 0x0000B200)
#define IRQ_PENDING_1       (ARCH_RASP_MMIOBASE + 0x0000B204)
#define IRQ_PENDING_2       (ARCH_RASP_MMIOBASE + 0x0000B208)
#define FIQ_CONTROL         (ARCH_RASP_MMIOBASE + 0x0000B20C)
#define ENABLE_IRQS_1       (ARCH_RASP_MMIOBASE + 0x0000B210)
#define ENABLE_IRQS_2       (ARCH_RASP_MMIOBASE + 0x0000B214)
#define ENABLE_BASIC_IRQS   (ARCH_RASP_MMIOBASE + 0x0000B218)
#define DISABLE_IRQS_1      (ARCH_RASP_MMIOBASE + 0x0000B21C)
#define DISABLE_IRQS_2      (ARCH_RASP_MMIOBASE + 0x0000B220)
#define DISABLE_BASIC_IRQS  (ARCH_RASP_MMIOBASE + 0x0000B224)

#define INT_WHAT_UNKNOW          0b000000
#define INT_WHAT_TRAPPED         0b000001
#define INT_WHAT_ILLEGINSTR      0b001110
#define INT_WHAT_SYSCALL         0b010101
#define INT_WHAT_INSTR_ABORTLOW  0b100000
#define INT_WHAT_INSTR_ABORTSAME 0b100001
#define INT_WHAT_ALIGN           0b100010
#define INT_WHAT_DATA_ABORTLOW   0b100101
#define INT_WHAT_DATA_ABORTSAME  0b100100
#define INT_WHAT_STACKALOGN      0b100110
#define INT_WHAT_FPU             0b101100

void *setFiqFuncAddress(void *);

#endif