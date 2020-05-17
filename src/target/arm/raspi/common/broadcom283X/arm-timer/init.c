#include "lightbeam.h"
#include "target/arm/raspi/common/bcm283X/arm-timer.h"
#include "kernel/init/initcalls.h"

volatile struct bcm283x_armTimerRegs_t *armTimerRegs = NULL;

static void bcm283x_armtimer_init(void)
{
    armTimerRegs = (struct bcm283x_armTimerRegs_t *)BCM283x_ARMTIMER_ENTRY;
}

boot_initcall(bcm283x_armtimer_init);