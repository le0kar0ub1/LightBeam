#ifndef __ARM64_TYPES_H__
#define __ARM64_TYPES_H__

#include "kernel/def/typedef.h"

typedef signed long             off_t;
typedef signed long long        loff_t;

typedef signed int              bool_t;
typedef unsigned long           irqflg_t;

typedef struct {
    volatile int counter;
} atomic_t;

#endif /* __ARM64_TYPES_H__ */
