#include "lightbeam.h"
#include "target/raspi/common/bcm283X/system-timer.h"
#include "kernel/init/initcalls.h"

volatile struct bcm283x_systemTimerRegs_t *systemTimerRegs = NULL;

static void bcm283x_systemtimer_init(void)
{
    systemTimerRegs = (struct bcm283x_systemTimerRegs_t *)BCM283x_SYSTEMTIMER_ENTRY;
}

boot_initcall(bcm283x_systemtimer_init);