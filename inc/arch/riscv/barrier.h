#ifndef _RISCV_BARRIER_H
#define _RISCV_BARRIER_H

#define nop()	__asm__ __volatile__ ("nop")

#define RISCV_ACQUIRE_BARRIER		"\tfence r , rw\n"
#define RISCV_RELEASE_BARRIER		"\tfence rw,  w\n"

#define RISCV_FENCE(p, s) \
	__asm__ __volatile__ ("fence " #p "," #s : : : "memory")

/* These barriers need to enforce ordering on both devices or memory. */
#define mb()		RISCV_FENCE(iorw,iorw)
#define rmb()		RISCV_FENCE(ir,ir)
#define wmb()		RISCV_FENCE(ow,ow)

/* These barriers do not need to enforce ordering on devices, just memory. */
#define __smp_mb()	RISCV_FENCE(rw,rw)
#define __smp_rmb()	RISCV_FENCE(r,r)
#define __smp_wmb()	RISCV_FENCE(w,w)

#define __smp_store_release(p, v)					\
do {									\
	RISCV_FENCE(rw,w);						\
	*p = v;						\
} while (0)

#define __smp_load_acquire(p)						\
({									\
	typeof(*p) ___p1 = *p;				\
	RISCV_FENCE(r,rw);						\
	___p1;								\
})

#define smp_mb__after_spinlock()	RISCV_FENCE(rw,rw)

#endif
