#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"

void arch_cpu_scheduler(void)
{
    cpu_scheduler();
}

void arch_cpu_halt(void)
{
    asm volatile ("wfi");
}