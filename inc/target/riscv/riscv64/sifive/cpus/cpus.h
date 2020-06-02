#ifndef __CPUS_H_
#define __CPUS_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/schedule/semaphore.h"
#include "kernel/cpus/vmulticore.h"

enum CPU_STATE
{
    CPU_IS_UNDEFINED  = 0,
    CPU_IS_BOOTED     = 1,
    CPU_IS_RUNNING    = 2,
    CPU_IS_STOPPED    = 3
};

cpuid_t cpuGetId(void);

void cpuSheduler(void) __noreturn;
bool cpuExecRoutine(cpuid_t cpu, void (*)(void));

void __deadloop(void);
void __hang(void);
void __scratch(void);

int cpuGetState(void);
void cpuSetState(enum CPU_STATE state);
void cpuSetRoutine(int core, void *routine);
void *cpuGetRoutine(int core);


#endif