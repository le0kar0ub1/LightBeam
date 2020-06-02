#include "target/riscv/riscv64/sifive/cpus/cpus.h"

static struct cpustate_t cpus[KCONFIG_MAXCPUS] = {0};

int cpuGetState(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (CPU_IS_UNDEFINED);
    return (cpus[cpuGetId()].state);
}

void cpuSetState(int core, enum CPU_STATE state)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[cpuGetId()].state = state;
}

void cpuSetRoutine(int core, void *routine, int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].routine.entry = routine;
    cpus[core].routine.argc = argc;
    cpus[core].routine.argv = argv;
}

struct cpuroutine_t *cpuGetRoutine(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (NULL);
    return (&(cpus[core].routine));
}