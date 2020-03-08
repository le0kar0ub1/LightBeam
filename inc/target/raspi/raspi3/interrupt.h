#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "def/typedef.h"

void int_handler(ulong, ulong, ulong, ulong, ulong);

#define INT_TYPE_SYNC 0
#define INT_TYPE_IRQ  1
#define INT_TYPE_FIQ  2
#define INT_TYPE_SERR 3

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