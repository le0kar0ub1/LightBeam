#ifndef _AARCH64_H_
#define _AARCH64_H_

#include "def/typedef.h"
#include "arm64.h"
#include "atomic.h"
#include "barrier.h"
#include "irqflags.h"
#include "regs.h"
#include "types.h"

#define __AARCH64__ 1

int  get32(int);
void put32(int, int);

void memzero(void *, int);
void delay(void);
uint get_el(void);

#endif