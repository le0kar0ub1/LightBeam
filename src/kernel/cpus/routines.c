#ifdef KCONFIG_MAXCPUS

#include "kernel/cpus/cpus.h"

/*
** Exec the given routine on the given cpu
*/
void cpu_exec_routine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    if (cpu_get_state(core) != CPU_IS_STOPPED)
        return;
    cpu_set_state(core, CPU_IS_TRANSITION);
    cpu_set_routine(core, routine, argc, argv);
    arch_cpu_trigger_cpu(core);

}
#endif