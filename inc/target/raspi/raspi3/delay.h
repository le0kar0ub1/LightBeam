#ifndef __DELAY_H_
#define __DELAY_H_

#include "def/typedef.h"

void wait_cycles(u32_t);
void wait_msec(u32_t);
unsigned long get_system_timer(void);
void wait_msec_st(u32_t);

#endif