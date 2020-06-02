#ifndef _ASM_RISCV_ATOMIC_H
#define _ASM_RISCV_ATOMIC_H

#include "arch/riscv/barrier.h"

#define ATOMIC_INIT(i)    { (i) }

#define __atomic_acquire_fence()    \
    __asm__ __volatile__(RISCV_ACQUIRE_BARRIER "" ::: "memory")

#define __atomic_release_fence()    \
    __asm__ __volatile__(RISCV_RELEASE_BARRIER "" ::: "memory");

#define ATOMIC_OP(op, asm_op, I, asm_type, c_type, prefix)    \
static inline void atomic##prefix##_##op(c_type i, atomic_t *v)    \
{    \
    __asm__ __volatile__ (    \
    "    amo" #asm_op "." #asm_type " zero, %1, %0"    \
    : "+A" (v->counter)    \
    : "r" (I)    \
    : "memory");    \
}    \

#define ATOMIC_OPS(op, asm_op, I)                \
        ATOMIC_OP (op, asm_op, I, w,  int, 32)   \
        ATOMIC_OP (op, asm_op, I, d, long, 64)

ATOMIC_OPS(add, add,  i)
ATOMIC_OPS(sub, add, -i)
ATOMIC_OPS(and, and,  i)
ATOMIC_OPS( or,  or,  i)
ATOMIC_OPS(xor, xor,  i)

#undef ATOMIC_OP
#undef ATOMIC_OPS

#define ATOMIC_FETCH_OP(op, asm_op, I, asm_type, c_type, prefix)    \
static inline    \
c_type atomic##prefix##_fetch_##op##_relaxed(c_type i,    \
         atomic_t *v)    \
{    \
    register c_type ret;    \
    __asm__ __volatile__ (    \
    "    amo" #asm_op "." #asm_type " %1, %2, %0"    \
    : "+A" (v->counter), "=r" (ret)    \
    : "r" (I)    \
    : "memory");    \
    return ret;    \
}    \
static inline    \
c_type atomic##prefix##_fetch_##op(c_type i, atomic_t *v)    \
{    \
    register c_type ret;    \
    __asm__ __volatile__ (    \
    "    amo" #asm_op "." #asm_type ".aqrl  %1, %2, %0"    \
    : "+A" (v->counter), "=r" (ret)    \
    : "r" (I)    \
    : "memory");    \
    return ret;    \
}

#define ATOMIC_OP_RETURN(op, asm_op, c_op, I, asm_type, c_type, prefix)    \
static inline    \
c_type atomic##prefix##_##op##_return_relaxed(c_type i,    \
          atomic_t *v)    \
{    \
        return atomic##prefix##_fetch_##op##_relaxed(i, v) c_op I;    \
}    \
static inline    \
c_type atomic##prefix##_##op##_return(c_type i, atomic_t *v)    \
{    \
        return atomic##prefix##_fetch_##op(i, v) c_op I;    \
}

#define ATOMIC_OPS(op, asm_op, c_op, I)    \
        ATOMIC_FETCH_OP( op, asm_op,       I, w,  int,   )    \
        ATOMIC_OP_RETURN(op, asm_op, c_op, I, w,  int,   )    \
        ATOMIC_FETCH_OP( op, asm_op,       I, d, long, 64)    \
        ATOMIC_OP_RETURN(op, asm_op, c_op, I, d, long, 64)

ATOMIC_OPS(add, add, +,  i)
ATOMIC_OPS(sub, add, +, -i)

#define atomic_add_return_relaxed    atomic_add_return_relaxed
#define atomic_sub_return_relaxed    atomic_sub_return_relaxed
#define atomic_add_return    atomic_add_return
#define atomic_sub_return    atomic_sub_return

#define atomic_fetch_add_relaxed    atomic_fetch_add_relaxed
#define atomic_fetch_sub_relaxed    atomic_fetch_sub_relaxed
#define atomic_fetch_add    atomic_fetch_add
#define atomic_fetch_sub    atomic_fetch_sub

#ifndef CONFIG_GENERIC_ATOMIC64
#define atomic64_add_return_relaxed    atomic64_add_return_relaxed
#define atomic64_sub_return_relaxed    atomic64_sub_return_relaxed
#define atomic64_add_return    atomic64_add_return
#define atomic64_sub_return    atomic64_sub_return

#define atomic64_fetch_add_relaxed    atomic64_fetch_add_relaxed
#define atomic64_fetch_sub_relaxed    atomic64_fetch_sub_relaxed
#define atomic64_fetch_add    atomic64_fetch_add
#define atomic64_fetch_sub    atomic64_fetch_sub
#endif

#undef ATOMIC_OPS

#define ATOMIC_OPS(op, asm_op, I)    \
        ATOMIC_FETCH_OP(op, asm_op, I, w,  int,   )    \
        ATOMIC_FETCH_OP(op, asm_op, I, d, long, 64)

ATOMIC_OPS(and, and, i)
ATOMIC_OPS( or,  or, i)
ATOMIC_OPS(xor, xor, i)

#undef ATOMIC_OPS

static inline int atomic_load(atomic_t *v)
{
    int load;

    __asm__ __volatile__ (
    "    lr.d     %[p],  %[c]\n"
    "    fence    rw, rw\n"
    "\n"
    : [p]"=&r" (load), [c]"+A" (v->counter)
	:
    : "memory");
    return load;
}

static inline void atomic_store(atomic_t *v, int store)
{
    __asm__ __volatile__ (
    "    sc.d.rl  %[p], %[p], %[c]\n"
    "    fence    rw, rw\n"
    "\n"
    : [c]"+A" (v->counter), [p]"=&r" (store)
	:
    : "memory");
}

static inline int atomic_fetch_add_unless(atomic_t *v, int a, int u)
{
       int prev, rc;

    __asm__ __volatile__ (
    "0:    lr.w     %[p],  %[c]\n"
    "    beq      %[p],  %[u], 1f\n"
    "    add      %[rc], %[p], %[a]\n"
    "    sc.w.rl  %[rc], %[rc], %[c]\n"
    "    bnez     %[rc], 0b\n"
    "    fence    rw, rw\n"
    "1:\n"
    : [p]"=&r" (prev), [rc]"=&r" (rc), [c]"+A" (v->counter)
    : [a]"r" (a), [u]"r" (u)
    : "memory");
    return prev;
}

static inline long atomic64_fetch_add_unless(atomic_t *v, long a, long u)
{
       long prev, rc;

    __asm__ __volatile__ (
    "0:    lr.d     %[p],  %[c]\n"
    "    beq      %[p],  %[u], 1f\n"
    "    add      %[rc], %[p], %[a]\n"
    "    sc.d.rl  %[rc], %[rc], %[c]\n"
    "    bnez     %[rc], 0b\n"
    "    fence    rw, rw\n"
    "1:\n"
    : [p]"=&r" (prev), [rc]"=&r" (rc), [c]"+A" (v->counter)
    : [a]"r" (a), [u]"r" (u)
    : "memory");
    return prev;
}

#endif /* _ASM_RISCV_ATOMIC_H */
