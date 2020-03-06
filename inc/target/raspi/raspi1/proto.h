#ifndef _RASPI1_PROTOS_H_
#define _RASPI1_PROTOS_H_

#include "def/typedef.h"

extern void membarrier(void);

uint32 mmioRead(uint32, uint32);
void mmioWrite(uint32, uint32, uint32);

void *memcpy(void *, const void *, size_t);

void init_hook(void);

#endif