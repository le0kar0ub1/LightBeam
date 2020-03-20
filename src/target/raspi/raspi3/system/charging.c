#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/delay.h"
#include "target/raspi/raspi3/system.h"

static const char spincharge[4] = { '|', '/', '-', '\\' };

uint64 timer_getTickCount64(void)
{
    uint32 hiCount = SYSTEMTIMER->TimerHi;
    uint32 loCount = SYSTEMTIMER->TimerLo;
        
    while (hiCount != SYSTEMTIMER->TimerHi) {
        hiCount = SYSTEMTIMER->TimerHi;
        loCount = SYSTEMTIMER->TimerLo;
    }
    return (((uint64)hiCount << 32) | loCount);
}

void timer_wait(uint64 usec) 
{
    usec += timer_getTickCount64();
    while (timer_getTickCount64() < usec);
}

void system_charging(uint time)
{
    uint64 endtime = timer_getTickCount64() + (time * 1000ul);
    uint i = 0;

    while (timer_getTickCount64() < endtime) {
        lfb_kprint("System charging... %c\r", spincharge[i]);
        timer_wait(50000);
        i = i < 3 ? i + 1 : 0;
    }
    lfb_kprint("System charging... %$ADONE%$R\n", RGB_Lime);
}