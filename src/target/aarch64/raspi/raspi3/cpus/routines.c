#include "target/riscv/riscv64/sifive/cpus/cpus.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"

void arch_cpu_trigger_cpu(cpuid_t core __unused)
{
    asm volatile ("sev");
}

void arch_cpu_acquire_trigger_cpu(void)
{
}