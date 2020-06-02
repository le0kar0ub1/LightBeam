#ifndef __SYSTEM_TIMER_H_
#define __SYSTEM_TIMER_H_

#include "target/aarch64/raspi/common/bcm283X/system-timer.h"

u64_t systemtimer_get_ustime(void);
void systemtimer_wait_us(u64_t us);

#endif