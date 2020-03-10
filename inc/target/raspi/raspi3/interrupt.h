#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "def/typedef.h"

void int_handler(ulong, ulong, ulong, ulong, ulong);
void irq_vector_init(void);
void enable_irq(void);
void disable_irq(void);
void enable_interrupt_controller(void);
void handle_except_msg(int, uint64, uint64);
void handle_irq(void);

#define INT_TYPE_SYNC 0
#define INT_TYPE_IRQ  1
#define INT_TYPE_FIQ  2
#define INT_TYPE_SERR 3

#define INT_FRAME_SIZE          256

#define SYNC_INVALID_EL1t       0
#define IRQ_INVALID_EL1t        1
#define FIQ_INVALID_EL1t        2
#define ERROR_INVALID_EL1t      3
#define SYNC_INVALID_EL1h       4
#define IRQ_INVALID_EL1h        5
#define FIQ_INVALID_EL1h        6
#define ERROR_INVALID_EL1h      7
#define SYNC_INVALID_EL0_64     8
#define IRQ_INVALID_EL0_64      9
#define FIQ_INVALID_EL0_64      10
#define ERROR_INVALID_EL0_64    11
#define SYNC_INVALID_EL0_32     12
#define IRQ_INVALID_EL0_32      13
#define FIQ_INVALID_EL0_32      14
#define ERROR_INVALID_EL0_32    15

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

#define SYSTEM_TIMER_IRQ_0  (1 << 0)
#define SYSTEM_TIMER_IRQ_1  (1 << 1)
#define SYSTEM_TIMER_IRQ_2  (1 << 2)
#define SYSTEM_TIMER_IRQ_3  (1 << 3)

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

#endif