#ifndef __CPUS_H_
#define __CPUS_H_

#include "def/typedef.h"

int cpu_getid(void);
void cpu_wait(void);

void cpu_log(void *);
void cpu_wrn(void *);
void cpu_err(void *);

#endif