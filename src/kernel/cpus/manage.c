#ifdef KCONFIG_MAXCPUS

#include "kernel/cpus/cpus.h"

static struct cpustate_t cpus[KCONFIG_MAXCPUS] = {0};

static spinlock_t lock[KCONFIG_MAXCPUS] = {SPINLOCK_INIT()};

/*
** Is the given cpu stopped
*/
bool cpu_is_stopped(cpuid_t core)
{
    enum CPU_STATE state;

    if (core > KCONFIG_MAXCPUS - 1)
        return (CPU_IS_UNDEFINED);
    arch_spin_lock(&(lock[core]));
    state = cpus[core].state;
    arch_spin_unlock(&(lock[core]));
    return (state == CPU_IS_STOPPED);
}

/*
** Get a stopped cpu 
*/
cpuid_t cpu_get_stopped_one(void)
{
    for (cpuid_t i = 1; i < KCONFIG_MAXCPUS; i++)
        if (cpus[i].state == CPU_IS_STOPPED)
            return (i);
    return (-1);
}

/*
** Get the given cpu state 
*/
enum CPU_STATE cpu_get_state(cpuid_t core)
{
    enum CPU_STATE state;

    if (core > KCONFIG_MAXCPUS - 1)
        return (CPU_IS_UNDEFINED);
    arch_spin_lock(&(lock[core]));
    state = cpus[core].state;
    arch_spin_unlock(&(lock[core]));
    return (state);
}

/*
** Set the given cpu state 
*/
void cpu_set_state(cpuid_t core, enum CPU_STATE state)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    arch_spin_lock(&(lock[core]));
    cpus[core].state = state;
    arch_spin_unlock(&(lock[core]));
}

void cpu_set_routine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    cpus[core].routine.routine = routine;
    cpus[core].routine.argc = argc;
    cpus[core].routine.argv = argv;
}

/*
** Get the given cpu routine 
*/
struct cpuroutine_t *cpu_get_routine(cpuid_t core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (NULL);
    return (&(cpus[core].routine));
}

#endif