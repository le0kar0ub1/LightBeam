#ifndef _AARCH64_H_
#define _AARCH64_H_

#include "kernel/def/typedef.h"
#include "arm64.h"
#include "atomic.h"
#include "barrier.h"
#include "irqflags.h"
#include "types.h"

void cycle_delay(u32_t);

#define __AARCH64__ 1

#endif