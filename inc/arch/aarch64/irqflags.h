#ifndef __ARM64_IRQFLAGS_H__
#define __ARM64_IRQFLAGS_H__

#include "types.h"

static inline void arch_local_irq_enable(void)
{
    __asm__ __volatile__("msr daifclr, #2" ::: "memory");
}

static inline void arch_local_irq_disable(void)
{
    __asm__ __volatile__("msr daifset, #2" ::: "memory");
}

static inline irqflg_t arch_local_irq_save(void)
{
    irqflg_t flags;

    __asm__ __volatile__(
        "mrs %0, daif\n"
        "msr daifset, #2"
        : "=r" (flags)
        :
        :"memory", "cc");
    return flags;
}

static inline void arch_local_irq_restore(irqflg_t flags)
{
    __asm__ __volatile__(
        "msr daif, %0"
        :
        :"r" (flags)
        :"memory", "cc");
}

#define local_irq_enable()          do { arch_local_irq_enable(); } while(0)
#define local_irq_disable()         do { arch_local_irq_disable(); } while(0)
#define local_irq_save(flags)       do { flags = arch_local_irq_save(); } while(0)
#define local_irq_restore(flags)    do { arch_local_irq_restore(flags); } while(0)

#endif /* __ARM64_IRQFLAGS_H__ */
