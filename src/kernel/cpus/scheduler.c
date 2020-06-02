#include "kernel/cpus/cpus.h"

#ifdef KCONFIG_MAXCPUS
void cpu_scheduler(void)
{
    struct cpuroutine_t *routine;
    enum CPU_STATE state __unused;

    while (1)
    {
        cpu_set_state(arch_cpu_get_id(), CPU_IS_STOPPED);
        arch_cpu_halt();
        arch_cpu_acquire_trigger_cpu();
        if (cpu_get_state(arch_cpu_get_id()) != CPU_IS_TRANSITION)
            continue;
        cpu_set_state(arch_cpu_get_id(), CPU_IS_RUNNING);
        routine = cpu_get_routine(arch_cpu_get_id());
        if (!routine || !routine->routine)
            continue;
        cpu_log("routine start...");
        routine->routine(routine->argc, routine->argv);
        cpu_log("routine end...");
    }
}
#endif