#ifndef _ATOMIC_H_
#define _ATOMIC_H_

#include "lightbeam.h"
#include "arch/x86/asminline.h"

typedef volatile uint32 atomic32_t;
typedef volatile uint64 atomic64_t;

typedef atomic32_t kref_t;

#define atomic_xadd(P, V)      __sync_fetch_and_add((P), (V))
#define cmpxchg(P, O, N)       __sync_val_compare_and_swap((P), (O), (N))
#define atomic_inc(P)          __sync_add_and_fetch((P), 1)
#define atomic_dec(P)          __sync_add_and_fetch((P), -1) 
#define atomic_add(P, V)       __sync_add_and_fetch((P), (V))
#define atomic_set_bit(P, V)   __sync_or_and_fetch((P), 1 << (V))
#define atomic_clear_bit(P, V) __sync_and_and_fetch((P), ~( 1<< (V)))

/* Compile read-write barrier */
#define barrier() asm volatile("": : :"memory")

/* Pause instruction to prevent excess processor bus usage */ 
#define cpu_relax() asm volatile("pause\n": : :"memory")

/* Atomic exchange (of various sizes) */
static inline void *xchg_64(void *ptr, void *x)
{
    asm volatile("xchgq %0,%1"
            :"=r" ((uintptr) x)
            :"m" (*(volatile uintptr *)ptr), "0" ((uintptr) x)
            :"memory");
    return x;
}

static inline unsigned xchg_32(void *ptr, unsigned x)
{
    asm volatile("xchgl %0,%1"
            :"=r" ((unsigned) x)
            :"m" (*(volatile unsigned *)ptr), "0" (x)
            :"memory");
    return x;
}

static inline unsigned short xchg_16(void *ptr, unsigned short x)
{
    asm volatile("xchgw %0,%1"
            :"=r" ((unsigned short) x)
            :"m" (*(volatile unsigned short *)ptr), "0" (x)
            :"memory");
    return x;
}

/* Test and set a bit */
static inline char atomic_bitsetandtest(void *ptr, int x)
{
    char out;
    asm volatile("lock; bts %2,%1\n"
            "sbb %0,%0\n"
            :"=r" (out), "=m" (*(volatile uintptr *)ptr)
            :"Ir" (x)
            :"memory");
    return out;
}

static inline uint atomic_exchange(volatile uint *ptr, uint value)
{
    return (xchg(ptr, value));
}

static inline uint32 atomic_read32(atomic32_t *var)
{
    return __atomic_load_n(var, __ATOMIC_SEQ_CST);
}

static inline uint32 atomic_inc_read32(atomic32_t *var)
{
    return __atomic_add_fetch(var, 1, __ATOMIC_SEQ_CST);
}

static inline uint32 atomic_dec_read32(atomic32_t *var)
{
    return __atomic_sub_fetch(var, 1, __ATOMIC_SEQ_CST);
}

static inline void atomic_write32(atomic32_t *var, uint32 val)
{
    __atomic_store_n(var, val, __ATOMIC_SEQ_CST);
}


static inline uint64 atomic_read64(atomic64_t *var)
{
    return __atomic_load_n(var, __ATOMIC_SEQ_CST);
}

static inline uint64 atomic_inc_read64(atomic64_t *var)
{
    return __atomic_add_fetch(var, 1, __ATOMIC_SEQ_CST);
}

static inline uint64 atomic_dec_read64(atomic64_t *var)
{
    return __atomic_sub_fetch(var, 1, __ATOMIC_SEQ_CST);
}

static inline void atomic_write64(atomic64_t *var, uint32 val)
{
    __atomic_store_n(var, val, __ATOMIC_SEQ_CST);
}

static inline void kref_inc(kref_t *k)
{
    atomic_inc_read32(k);
}

static inline void kref_dec(kref_t *k)
{
    atomic_dec_read32(k);
}

static inline uint32 kref_inc_read(kref_t *k)
{
    return atomic_inc_read32(k);
}

static inline uint32 kref_dec_read(kref_t *k)
{
    return atomic_dec_read32(k);
}

static inline uint32 kref_read(kref_t *k)
{
    return atomic_read32(k);
}


#endif