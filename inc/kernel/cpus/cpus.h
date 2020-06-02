#ifndef __KERNEL_CPUS_H
#define __KERNEL_CPUS_H

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include <stdarg.h>

typedef int cpuid_t;

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

void cpu_log(char const *fmt, ...);
void cpu_wrn(char const *fmt, ...);
void cpu_err(char const *fmt, ...);

cpuid_t cpu_get_id(void);

void cpu_trigger_cpu(cpuid_t core);
void cpu_acquire_trigger_cpu(void);
void cpu_halt(void);

void cpu_set_state(cpuid_t core, enum CPU_STATE state);
enum CPU_STATE cpu_get_state(cpuid_t core);
void cpu_set_routine(int core, int (*routine)(int, char **), int argc, char **argv);
struct cpuroutine_t *cpu_get_routine(cpuid_t core);

void cpu_scheduler(void);
void cpu_exec_routine(int core, int (*routine)(int, char **), int argc, char **argv);

#endif