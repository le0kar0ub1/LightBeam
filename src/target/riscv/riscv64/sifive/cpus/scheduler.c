#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"

/*
** CPU base infinite loop for slaves
*/
void cpuSheduler(void)
{
    struct cpuroutine_t *routine;
    enum CPU_STATE state __unused;

    while (1)
    {
        cpuSetState(cpuGetId(), CPU_IS_STOPPED);
        asm volatile("wfi");
        CLINT_ACQUIRE_SOFT_INT();
        if (cpuGetState(cpuGetId()) != CPU_IS_TRANSITION)
            continue;
        cpuSetState(cpuGetId(), CPU_IS_RUNNING);
        routine = cpuGetRoutine(cpuGetId());
        if (!routine || !routine->routine)
            continue;
        CPU_LOG("routine start...");
        routine->routine(routine->argc, routine->argv);
        CPU_LOG("routine end...");
    }
}