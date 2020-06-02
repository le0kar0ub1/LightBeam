#ifndef __KERNEL_CPUS_H
#define __KERNEL_CPUS_H

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include <stdarg.h>

typedef int cpuid_t;

#ifdef KCONFIG_MAXCPUS
enum CPU_STATE
{
    CPU_IS_UNDEFINED  = 0,
    CPU_IS_BOOTED     = 1,
    CPU_IS_STOPPED    = 2,
    CPU_IS_TRANSITION = 3,
    CPU_IS_RUNNING    = 4,
};

struct cpustate_t
{
    enum CPU_STATE state;
    struct cpuroutine_t
    {
        int (*routine)(int, char **);
        int argc;
        char **argv;
        int status;
    } routine;
};

void arch_cpu_log(char const *fmt, ...);
void arch_cpu_wrn(char const *fmt, ...);
void arch_cpu_err(char const *fmt, ...);
void arch_cpu_halt(void);
void arch_cpu_trigger_cpu(cpuid_t core);
void arch_cpu_acquire_trigger_cpu(void);
cpuid_t arch_cpu_get_id(void);

#define cpu_log(x, ...) (arch_cpu_log("[CPU %d][LOG]: %s\n", arch_cpu_get_id(), x, ##__VA_ARGS__))
#define cpu_wrn(x, ...) (arch_cpu_wrn("[CPU %d][WRN]: %s\n", arch_cpu_get_id(), x, ##__VA_ARGS__))
#define cpu_err(x, ...) (arch_cpu_err("[CPU %d][ERR]: %s\n", arch_cpu_get_id(), x, ##__VA_ARGS__))
#define cpu_halt()                arch_cpu_halt()
#define cpu_trigger_cpu(x)        arch_cpu_trigger_cpu(x)
#define cpu_acquire_trigger_cpu() arch_cpu_acquire_trigger_cpu()
#define cpu_get_id()              arch_cpu_get_id()

void arch_cpu_scheduler(void);
void cpu_scheduler(void);


void cpu_set_state(cpuid_t core, enum CPU_STATE state);
enum CPU_STATE cpu_get_state(cpuid_t core);
void cpu_set_routine(int core, int (*routine)(int, char **), int argc, char **argv);
struct cpuroutine_t *cpu_get_routine(cpuid_t core);

void cpu_exec_routine(int core, int (*routine)(int, char **), int argc, char **argv);
#endif

void __deadloop(void);
void __hang(void);
void __scratch(void);

#endif