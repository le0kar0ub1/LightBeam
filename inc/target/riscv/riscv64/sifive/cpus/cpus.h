#ifndef __CPUS_H_
#define __CPUS_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/schedule/semaphore.h"
#include "kernel/cpus/vmulticore.h"

cpuid_t cpuGetId(void);

void cpuSheduler(void) __noreturn;
bool cpuExecRoutine(cpuid_t cpu, void (*)(void));

void __deadloop(void);
void __hang(void);
void __scratch(void);

#endif