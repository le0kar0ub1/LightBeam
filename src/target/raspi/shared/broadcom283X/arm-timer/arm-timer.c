#include "lightbeam.h"
#include "target/raspi/shared/bcm283X/arm-timer.h"
#include "kernel/init/initcalls.h"

extern volatile struct bcm283x_armTimerRegs_t *armTimerRegs;

void bcm283x_armtimer_set_runtime_value(u32_t us)
{
    armTimerRegs->load = us;
}

void bcm283x_armtimer_set_prediv(u32_t us)
{
    armTimerRegs->prediv = us;
}

static void bcm283x_armtimer_set_state(bool val)
{
    armTimerRegs->control.timerEnable = val;
}

void bcm283x_armtimer_enable(void)
{
    bcm283x_armtimer_set_state(true);
}

void bcm283x_armtimer_disable(void)
{
    bcm283x_armtimer_set_state(false);
}

static void bcm283x_armtimer_set_interrupt_state(bool val)
{
    armTimerRegs->control.timerEnable = val;
}

void bcm283x_armtimer_enable_interrupt(void)
{
    bcm283x_armtimer_set_interrupt_state(true);
}

void bcm283x_armtimer_disable_interrupt(void)
{
    bcm283x_armtimer_set_interrupt_state(false);
}

static void bcm283x_armtimer_set_counter_mode(bool val)
{
    armTimerRegs->control.counter = val;
}

void bcm283x_armtimer_set_16bcounter_mode(void)
{
    bcm283x_armtimer_set_counter_mode(false);
}

void bcm283x_armtimer_set_23bcounter_mode(void)
{
    bcm283x_armtimer_set_counter_mode(true);
}

void bcm283x_armtimer_set_prescal(enum armTimerPrescale prescale)
{
    armTimerRegs->control.prescale = prescale;
}

bool bcm283x_armtimer_is_interrupt_pending(void)
{
    return (armTimerRegs->rawIRQ & 0b1);
}

void bcm283x_armtimer_clear_interrupt_pending(void)
{
    armTimerRegs->irqClr = 0x1;
}

bool bcm283x_armtimer_get_interrupt_state(void)
{
    return (armTimerRegs->maskedIRQ);
}