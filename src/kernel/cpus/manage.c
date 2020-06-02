#include "kernel/cpus/cpus.h"

#ifdef KCONFIG_MAXCPUS
static struct cpustate_t cpus[KCONFIG_MAXCPUS] = {0};

enum CPU_STATE cpu_get_state(cpuid_t core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (CPU_IS_UNDEFINED);
    return (cpus[core].state);
}

void cpu_set_state(cpuid_t core, enum CPU_STATE state)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].state = state;
}

void cpu_set_routine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].routine.routine = routine;
    cpus[core].routine.argc = argc;
    cpus[core].routine.argv = argv;
}

struct cpuroutine_t *cpu_get_routine(cpuid_t core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (NULL);
    return (&(cpus[core].routine));
}
#endif