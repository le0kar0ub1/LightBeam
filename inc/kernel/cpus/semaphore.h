#ifndef __SEMAPHORE_H_
#define __SEMAPHORE_H_

#include "kernel/def/typedef.h"
#include <stdbool.h>

#define SMPLOCK_INIT() 0

typedef volatile u32_t smplock_t;

void semaphore_inc(smplock_t *);
void semaphore_dec(smplock_t *);
bool unfatal_smp_lock(smplock_t *);

#define smp_inc(x)          \
        while (*x != 0x0);  \
        *x += 0x1

#define smp_dec(x) (*x = 0x0)

#endif