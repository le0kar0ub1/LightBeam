#ifndef __RISCV_INTERRPUTS_
#define __RISCV_INTERRPUTS_

#include "target/riscv/riscv.h"

struct intcontext_t
{
    u64_t pc;
    u64_t status;
    u64_t cause;
    u64_t reg[32];
};

void interrupt_handler(struct intcontext_t *);

#endif