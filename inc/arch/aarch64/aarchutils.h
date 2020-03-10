#ifndef _AARCH64_H_
#define _AARCH64_H_

#include "def/typedef.h"

#define __AARCH64__ 1

int  get32(int);
void put32(int, int);

void memzero(void *);
void delay(void);
int64 get_el(void);

#endif