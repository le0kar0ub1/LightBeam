#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/delay.h"
#include "target/raspi/raspi3/system.h"

static const char spincharge[4] = { '|', '/', '-', '\\' };

u64_t timer_getTickCount64(void)
{
    u32_t hiCount = SYSTEMTIMER->TimerHi;
    u32_t loCount = SYSTEMTIMER->TimerLo;
        
    while (hiCount != SYSTEMTIMER->TimerHi) {
        hiCount = SYSTEMTIMER->TimerHi;
        loCount = SYSTEMTIMER->TimerLo;
    }
    return (((u64_t)hiCount << 32) | loCount);
}

void timer_wait(u64_t usec) 
{
    usec += timer_getTickCount64();
    while (timer_getTickCount64() < usec);
}

void system_charging(u32_t time)
{
    u64_t endtime = timer_getTickCount64() + (time * 1000ul);
    u32_t i = 0;

    while (timer_getTickCount64() < endtime) {
        lfb_kprint("System charging... %c%\r", spincharge[i]);
        timer_wait(50000);
        i = (i + 1) % 4;
    }
    lfb_kprint("System charging... %$ADONE%$R\n", RGB_Lime);
}