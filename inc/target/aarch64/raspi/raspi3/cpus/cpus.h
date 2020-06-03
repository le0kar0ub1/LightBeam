#ifndef __RASPI3_CPUS_H_
#define __RASPI3_CPUS_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/cpus/cpus.h"

enum CPUS_ID
{
    CPU0 = 0,
    CPU1 = 1,
    CPU2 = 2,
    CPU3 = 3
};

bool cpuARMmaxSpeed(void);
void multicore_init(void);
void multicoresX_start(void);

#endif