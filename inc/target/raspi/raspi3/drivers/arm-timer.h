#ifndef __ARM_TIMER_H_
#define __ARM_TIMER_H_

#include "target/raspi/common/bcm283X/arm-timer.h"

void armtimer_init(u32_t);
void armtimer_set_value(u32_t val);

#endif