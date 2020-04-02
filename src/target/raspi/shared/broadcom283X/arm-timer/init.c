#include "lightbeam.h"
#include "target/raspi/shared/bcm283X/arm-timer.h"
#include "kernel/init/initcalls.h"

volatile struct bcm283x_armTimerRegs_t *armTimerRegs = NULL;

static void bcm283x_armtimer_init(void)
{
    armTimerRegs = (struct bcm283x_armTimerRegs_t *)BCM283x_TIMER_ENTRY;
}

pure_initcall(bcm283x_armtimer_init);