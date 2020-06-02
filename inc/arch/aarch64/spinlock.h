#ifndef __SPINLOCK_H_
#define __SPINLOCK_H_

#include "arch/aarch64/atomic.h"
#include "kernel/def/typedef.h"

/*
** AARCH64 architecture implementation
*/

typedef u32_t spinlock_t;

#define SPINLOCK_INIT() 0x0

static inline void spinlock_lock(spinlock_t *spinlock)
{
    while (atomic_cmp_exchange((atomic_t *)spinlock, 0, 1) != 0);
}

static inline void spinlock_unlock(spinlock_t *spinlock)
{
    atomic_cmp_exchange((atomic_t *)spinlock, 1, 0);
}

#endif