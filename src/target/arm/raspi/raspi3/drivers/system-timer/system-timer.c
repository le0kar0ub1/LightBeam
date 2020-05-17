#include "target/arm/raspi/raspi3/drivers/system-timer.h"

u64_t systemtimer_get_ustime(void)
{
    return (bcm283x_systemtimer_get_total());
}

void systemtimer_wait_us(u64_t us)
{
    us += bcm283x_systemtimer_get_total();
    while (bcm283x_systemtimer_get_total() < us);
}