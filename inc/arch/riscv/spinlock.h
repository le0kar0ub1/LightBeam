#ifndef __ARCH_SPINLOCK_H_
#define __ARCH_SPINLOCK_H_

#include "kernel/def/typedef.h"
#include "arch/riscv/barrier.h"

typedef volatile int spinlock_t;

#define SPINLOCK_INIT() 0x0

static inline bool arch_spin_is_locked(spinlock_t *lock)
{
    return (!(*lock == 0));
}

static inline void arch_spin_unlock(spinlock_t *lock)
{
    __smp_store_release(lock, 0);
}

static inline int arch_spin_trylock(spinlock_t *lock)
{
    int tmp = 1, busy;

    __asm__ __volatile__ (
        "   amoswap.w %0, %2, %1\n"
        RISCV_ACQUIRE_BARRIER
        : "=r" (busy), "+A" (*lock)
        : "r" (tmp)
        : "memory");

    return !busy;
}

static inline void arch_spin_lock(spinlock_t *lock)
{
    while (1)
    {
        if (arch_spin_is_locked(lock))
            continue;
        if (arch_spin_trylock(lock))
            break;
    }
}

#endif