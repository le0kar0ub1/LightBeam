#include "target/aarch64/raspi/raspi3/cpus/cpus.h"

void multicoresX_start(void)
{
    cpu_set_state(arch_cpu_get_id(), CPU_IS_STOPPED);
    arch_cpu_scheduler();
}

void arch_cpu_scheduler(void)
{
    cpu_scheduler();
}

void arch_cpu_halt(void)
{
    asm volatile ("wfe");
}
