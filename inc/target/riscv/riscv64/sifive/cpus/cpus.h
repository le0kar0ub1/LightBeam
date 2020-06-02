#ifndef __CPUS_H_
#define __CPUS_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/schedule/semaphore.h"
#include "kernel/cpus/cpus.h"

#define CPU_LOG(x, ...) (uart_kprint("[CPU %d][LOG]: %s\n", cpuGetId(), x, ##__VA_ARGS__))
#define CPU_WRN(x, ...) (uart_kprint("[CPU %d][WRN]: %s\n", cpuGetId(), x, ##__VA_ARGS__))
#define CPU_ERR(x, ...) (uart_kprint("[CPU %d][ERR]: %s\n", cpuGetId(), x, ##__VA_ARGS__))

void cpuSheduler(void) __noreturn;
bool cpuExecRoutine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv);

void __deadloop(void);
void __hang(void);
void __scratch(void);

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

int cpuGetState(cpuid_t core);
void cpuSetState(cpuid_t core, enum CPU_STATE state);
void cpuSetRoutine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv);
struct cpuroutine_t *cpuGetRoutine(cpuid_t core);


#endif