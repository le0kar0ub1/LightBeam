#ifndef __DELAY_H_
#define __DELAY_H_

#include "def/typedef.h"

void wait_cycles(uint);
void wait_msec(uint);
unsigned long get_system_timer(void);
void wait_msec_st(uint);

#endif