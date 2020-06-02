#include "target/riscv/riscv64/sifive/cpus/cpus.h"

static struct cpustate_t cpus[KCONFIG_MAXCPUS] = {0};

int cpuGetState(cpuid_t core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (CPU_IS_UNDEFINED);
    return (cpus[core].state);
}

void cpuSetState(cpuid_t core, enum CPU_STATE state)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].state = state;
}

void cpuSetRoutine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].routine.routine = routine;
    cpus[core].routine.argc = argc;
    cpus[core].routine.argv = argv;
}

struct cpuroutine_t *cpuGetRoutine(cpuid_t core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (NULL);
    return (&(cpus[core].routine));
}