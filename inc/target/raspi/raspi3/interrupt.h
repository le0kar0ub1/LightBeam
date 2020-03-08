#ifndef __INTERRUPT_H_
#define __INTERRUPT_H_

#include "def/typedef.h"

void int_handler(ulong, ulong, ulong, ulong, ulong);

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