#ifndef __SPINLOCK_H_
#define __SPINLOCK_H_

#include "kernel/def/typedef.h"
#include "target/riscv/common/cmpxchg.h"

typedef atomic_t spinlock_t;

#define SPINLOCK_DEFAULT() 0x0
#define SPINLOCK_UNLOCK()  0x0
#define SPINLOCK_LOCK()    0x1

#define SPINLOCK_INIT(name) static spinlock_t name = { .counter = SPINLOCK_DEFAULT() }

static inline void spinlock_lock(spinlock_t *spinlock)
{
    cmpxchg_acquire((int *)spinlock, 0, 1);
}

static inline void spinlock_unlock(spinlock_t *spinlock)
{
    cmpxchg_release((int *)spinlock, 1, 0);
}

#endif