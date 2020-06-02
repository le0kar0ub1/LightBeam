#include "kernel/cpus/cpus.h"

#ifdef KCONFIG_MAXCPUS
void cpu_scheduler(void)
{
    struct cpuroutine_t *routine;
    enum CPU_STATE state __unused;

    while (1)
    {
        cpu_set_state(cpu_get_id(), CPU_IS_STOPPED);
        cpu_halt();
        cpu_acquire_trigger_cpu();
        if (cpu_get_state(cpu_get_id()) != CPU_IS_TRANSITION)
            continue;
        cpu_set_state(cpu_get_id(), CPU_IS_RUNNING);
        routine = cpu_get_routine(cpu_get_id());
        if (!routine || !routine->routine)
            continue;
        cpu_log("routine start...");
        routine->routine(routine->argc, routine->argv);
        cpu_log("routine end...");
    }
}
#endif