#include "target/arm/raspi/raspi3/drivers/fb.h"
#include "target/arm/raspi/raspi3/drivers/system-timer.h"
#include "target/arm/raspi/raspi3/system.h"

static const char spincharge[4] = { '|', '/', '-', '\\' };

void system_charging(u32_t time)
{
    u64_t endtime = systemtimer_get_ustime() + (time * 1000ul);
    u32_t i = 0;

    while (systemtimer_get_ustime() < endtime) {
        rpifb_kprint("System charging... %c\r", spincharge[i]);
        systemtimer_wait_us(50000);
        i = (i + 1) % 4;
    }
    rpifb_kprint("System charging... %sDONE%s\n", RGB256toESCFRT(Lime), RGB256toESCFRT(White));
}