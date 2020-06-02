#include "target/riscv/riscv64/sifive/cpus/cpus.h"

struct cpustate_t
{
    enum CPU_STATE state;
    void *routine;
};

static struct cpustate_t cpus[KCONFIG_MAXCPUS] = {0};

int cpuGetState(void)
{
    return (cpus[cpuGetId()].state);
}

void cpuSetState(enum CPU_STATE state)
{
    cpus[cpuGetId()].state = state;
}

void cpuSetRoutine(int core, void *routine)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].routine = routine;
}

void *cpuGetRoutine(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (NULL);
    return (cpus[core].routine);
}