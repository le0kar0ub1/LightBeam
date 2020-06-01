#ifndef __SPINLOCK_H_
#define __SPINLOCK_H_

#include "target/x86/common/asminline.h"
#include "target/x86/common/atomic.h"
#include "kernel/def/typedef.h"

/*
** x86 architecture implementation
*/

typedef u32_t spinlock_t;

#define SPINLOCK_INIT() 0x0

static inline void spinlock_lock(spinlock_t *spinlock)
{
    while (atomic_exchange(spinlock, 1) != 0);
}

static inline void spinlock_unlock(spinlock_t *spinlock)
{
    atomic_exchange(spinlock, 0);
}

#endif