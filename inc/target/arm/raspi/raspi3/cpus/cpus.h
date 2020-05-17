#ifndef __CPUS_H_
#define __CPUS_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/schedule/semaphore.h"
#include "kernel/cpus/vmulticore.h"

enum CPUS_ID
{
    CPU0 = 0,
    CPU1 = 1,
    CPU2 = 2,
    CPU3 = 3
};

enum CPUS_STATE
{
    CPU_IS_SLEEPING = 0x1,
    CPU_IS_WORKING  = 0x0
};

void cpuSheduler(void) __noreturn;
bool cpuExecRoutine(enum CPUS_ID, void (*)(void));

enum CPUS_STATE cpuGetState(enum CPUS_ID);
enum CPUS_ID cpuGetSleepingOne(void);

void uart_cpu_log(char const *);
void uart_cpu_wrn(char const *);
void uart_cpu_err(char const *);

void rpifb_cpu_log(char const *);
void rpifb_cpu_wrn(char const *);
void rpifb_cpu_err(char const *);

void __deadloop(void);
void __hang(void);
void __scratch(void);

bool cpuARMmaxSpeed(void);
void multicore_init(void);
void multicoresX_start(void);

#endif