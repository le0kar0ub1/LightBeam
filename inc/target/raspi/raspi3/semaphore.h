#ifndef __SEMAPHORE_H_
#define __SEMAPHORE_H_

#include "def/typedef.h"
#include <stdbool.h>

#define SMPLOCK_INIT 0

typedef uint smplock_t;

void semaphore_inc(void *);
void semaphore_dec(void *);
bool unfatal_smp_lock(void *);

#endif