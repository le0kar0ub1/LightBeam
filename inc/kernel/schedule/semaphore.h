#ifndef __SEMAPHORE_H_
#define __SEMAPHORE_H_

#include "kernel/def/typedef.h"
#include <stdbool.h>

#define SMPLOCK_INIT() 0

typedef volatile u32_t smplock_t;

void semaphore_inc(smplock_t *);
void semaphore_dec(smplock_t *);
bool unfatal_smp_lock(smplock_t *);

static inline void smp_inc(smplock_t *lck)
{
    while (*lck != 0x0);
    *lck += 0x1;
}

static inline void smp_dec(smplock_t *lck)
{
    *lck -= 0x1;
}

#endif