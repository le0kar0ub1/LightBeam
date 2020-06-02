#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"

/*
** CPU base infinite loop
*/
void cpuSheduler(void)
{
    struct cpuroutine_t *routine;
    enum CPU_STATE state;

    while (1)
    {
        CPU_LOG("LA");
        asm volatile("wfi");
        state = cpuGetState(cpuGetId());
        if (state != CPU_IS_STOPPED)
            continue;
        routine = cpuGetRoutine(cpuGetId());
        if (!routine || !routine->routine)
            continue;
        CPU_LOG("executing routine...");
        routine->routine(routine->argc, routine->argv);
        CPU_LOG("return status routine");
    }
}