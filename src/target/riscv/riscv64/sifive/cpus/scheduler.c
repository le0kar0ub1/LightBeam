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
        asm volatile("wfi");
        state = cpuGetState(cpuGetId());
        if (state != CPU_IS_STOPPED)
            continue;
        routine = cpuGetRoutine(cpuGetId());
        if (!routine)
            continue;
        routine->entry(routine->argc, routine->argv);
    }
}