#ifndef __CPUS_H_
#define __CPUS_H_

#include "def/typedef.h"
#include "def/keyword.h"
#include "target/raspi/raspi3/cpus/semaphore.h"

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

int cpuGetId(void);
enum CPUS_STATE cpuGetState(enum CPUS_ID);
enum CPUS_ID cpuGetSleepingOne(void);

void uart_cpu_log(char const *);
void uart_cpu_wrn(char const *);
void uart_cpu_err(char const *);

void lfb_cpu_log(char const *);
void lfb_cpu_wrn(char const *);
void lfb_cpu_err(char const *);

void __deadloop(void);
void __hang(void);
void __scratch(void);

bool cpuARMmaxSpeed(void);
void multicore_init(void);
void multicoresX_start(void);

#endif