#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "def/typedef.h"

struct rframe_t
{
    u64_t x30;
    u64_t x29;
    u64_t x28;
    u64_t x27;
    u64_t x26;
    u64_t x25;
    u64_t x24;
    u64_t x23;
    u64_t x22;
    u64_t x21;
    u64_t x20;
    u64_t x19;
    u64_t x18;
    u64_t x17;
    u64_t x16;
    u64_t x15;
    u64_t x14;
    u64_t x13;
    u64_t x12;
    u64_t x11;
    u64_t x10;
    u64_t x9;
    u64_t x8;
    u64_t x7;
    u64_t x6;
    u64_t x5;
    u64_t x4;
    u64_t x3;
    u64_t x2;
    u64_t x1;
    u64_t x0;

    u64_t sp;
    u64_t pc;
    u64_t pstate;
    u64_t origin;
    u64_t syscall;
};

void int_handler(u64_t, u64_t, u64_t, u64_t, u64_t);
void vectors_init(void);
void handle_except_msg(int, u64_t, u64_t);
void handle_irq(void);

void enable_interrupts(void);
void disable_interrupts(void);
void enable_fiq(void);
void disable_fiq(void);
u64_t getIntFlags(void);
void setIntFlags(u64_t);

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