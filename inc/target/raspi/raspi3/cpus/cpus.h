#ifndef __CPUS_H_
#define __CPUS_H_

#include "def/typedef.h"
#include "target/raspi/raspi3/semaphore.h"

int cpu_getid(void);
void cpu_warbase(void);

void uart_cpu_log(char const *);
void uart_cpu_wrn(char const *);
void uart_cpu_err(char const *);

void lfb_cpu_log(char const *);
void lfb_cpu_wrn(char const *);
void lfb_cpu_err(char const *);

void __deadloop(void);
void __hang(void);
void __scratch(void);

void multicore_init(void);
void multicoresX_start(void);

#endif