#include "lightbeam.h"
#include "target/raspi/shared/bcm283X/system-timer.h"
#include "kernel/init/initcalls.h"

extern struct bcm283x_systemTimerRegs_t *systemTimerRegs;

void bcm283x_systemtimer_clear_match(u8_t match)
{
    switch (match)
    {
        case 0:
            systemTimerRegs->ctrl.m0 = 0x1;
            break;
        case 1:
            systemTimerRegs->ctrl.m1 = 0x1;
            break;
        case 2:
            systemTimerRegs->ctrl.m2 = 0x1;
            break;
        case 3:
            systemTimerRegs->ctrl.m3 = 0x1;
            break;
        default:
            break;
    }
}

bool bcm283x_systemtimer_get_match(u8_t match)
{
    switch (match)
    {
        case 0:
            return (systemTimerRegs->ctrl.m0);
        case 1:
            return (systemTimerRegs->ctrl.m1);
        case 2:
            return (systemTimerRegs->ctrl.m2);
        case 3:
            return (systemTimerRegs->ctrl.m3);
        default:
            return (false);
    }
}

void bcm283x_systemtimer_set_comparator(u8_t comparator, u32_t val)
{
    switch (comparator)
    {
        case 0:
            systemTimerRegs->cmp0 = val;
            break;
        case 1:
            systemTimerRegs->cmp1 = val;
            break;
        case 2:
            systemTimerRegs->cmp2 = val;
            break;
        case 3:
            systemTimerRegs->cmp3 = val;
            break;
        default:
            break;
    }
}

u32_t bcm283x_systemtimer_get_comparator(u8_t comparator)
{
    switch (comparator)
    {
        case 0:
            return (systemTimerRegs->cmp0);
        case 1:
            return (systemTimerRegs->cmp1);
        case 2:
            return (systemTimerRegs->cmp2);
        case 3:
            return (systemTimerRegs->cmp3);
        default:
            return (0x0);
    }
}

u32_t bcm283x_systemtimer_get_high(void)
{
    return (systemTimerRegs->chi);
}

u32_t bcm283x_systemtimer_get_low(void)
{
    return (systemTimerRegs->clo);
}

u64_t bcm283x_systemtimer_get_total(void)
{
    u64_t total = ((u64_t)bcm283x_systemtimer_get_high() << 32);
    total |= (u64_t)bcm283x_systemtimer_get_low();
    return (total);
}