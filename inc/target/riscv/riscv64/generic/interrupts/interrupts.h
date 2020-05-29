#ifndef __RISCV_INTERRPUTS_
#define __RISCV_INTERRPUTS_

#include "target/riscv/riscv.h"

struct intcontext_t
{
    u64_t pc;
    u64_t status;
    u64_t cause;
    u64_t x1;
    u64_t x3;
    u64_t x4;
    u64_t x5;
    u64_t x6;
    u64_t x7;
    u64_t x8;
    u64_t x9;
    u64_t x10;
    u64_t x11;
    u64_t x12;
    u64_t x13;
    u64_t x14;
    u64_t x15;
    u64_t x16;
    u64_t x17;
    u64_t x18;
    u64_t x19;
    u64_t x20;
    u64_t x21;
    u64_t x22;
    u64_t x23;
    u64_t x24;
    u64_t x25;
    u64_t x26;
    u64_t x27;
    u64_t x28;
    u64_t x29;
    u64_t x30;
    u64_t x31;
};

void interrupt_handler(struct intcontext_t *);

#endif