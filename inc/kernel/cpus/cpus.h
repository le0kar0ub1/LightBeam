#ifndef __KERNEL_CPUS_H
#define __KERNEL_CPUS_H

typedef int cpuid_t;

enum CPU_STATE
{
    CPU_IS_UNDEFINED  = 0,
    CPU_IS_BOOTED     = 1,
    CPU_IS_STOPPED    = 2,
    CPU_IS_RUNNING    = 3,
    CPU_IS_TRANSITION = 4,
};

cpuid_t cpuGetId(void);

#endif