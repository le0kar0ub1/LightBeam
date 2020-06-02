#ifndef __RISCV_H_
#define __RISCV_H_

#include "lightbeam.h"

#include "target/riscv/common/atomic.h"
#include "target/riscv/common/barrier.h"
#include "target/riscv/common/cmpxchg.h"
#include "target/riscv/common/csr.h"
#include "target/riscv/common/spinlock.h"

void PANIC(char const *, ...) __noreturn;

#endif