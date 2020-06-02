#ifndef __RISCV_H_
#define __RISCV_H_

#include "lightbeam.h"

#include "arch/riscv/atomic.h"
#include "arch/riscv/barrier.h"
#include "arch/riscv/cmpxchg.h"
#include "arch/riscv/csr.h"
#include "arch/riscv/spinlock.h"

void PANIC(char const *, ...) __noreturn;

#endif