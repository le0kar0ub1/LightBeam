#ifndef _MACRO_H_
#define _MACRO_H_

#define decto(x) while (x --> 0)
#define incto(x, y) while (x ++< y)

#define APPLY_AND_LOWER_MASK(x, y) (x & ((1 << y) - 1))
#define APPLY_AND_UPPER_MASK(x, y) (x & ((u32_t_MAX) - ((1 << y) - 1)))

#define swap(x,y) (x ^= y ^= x ^= y)

#define arrsize(x) (sizeof(x) / sizeof(*x))

#define asmv __asm__ volatile /* fire asm instruction */

#define FIRE_ASM(x)         \
{                           \
    asm volatile(x);        \
};

#endif
