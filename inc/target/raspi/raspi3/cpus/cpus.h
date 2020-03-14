#ifndef __CPUS_H_
#define __CPUS_H_

#include "def/typedef.h"

int cpu_getid(void);
void cpu_warbase(void);

void cpu_log(char const *);
void cpu_wrn(char const *);
void cpu_err(char const *);

void __deadloop(void);
void __hang(void);
void __scratch(void);

void multicore_init(void);
void multicoresX_start(void);

#endif