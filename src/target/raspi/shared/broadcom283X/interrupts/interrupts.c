#include "lightbeam.h"
#include "target/raspi/shared/bcm283X/interrupts.h"

extern struct bcm283x_irqControlRegisters_t *irqCtrlRegs;

void bcm283x_interrupt_disable_irq(u32_t irq)
{
    if (irq < 32)
        irqCtrlRegs->disableIRQs1 = CLEAR_DOUBLE(irqCtrlRegs->disableIRQs1, irq);
    else if (irq < 64)
        irqCtrlRegs->disableIRQs2 = CLEAR_DOUBLE(irqCtrlRegs->disableIRQs2, irq - 32);
}

void bcm283x_interrupt_enable_irq(u32_t irq)
{
    if (irq < 32)
        irqCtrlRegs->disableIRQs1 = SET_DOUBLE(irqCtrlRegs->disableIRQs1, irq);
    else if (irq < 64)
        irqCtrlRegs->disableIRQs2 = SET_DOUBLE(irqCtrlRegs->disableIRQs2, irq - 32);
}

u64_t bcm283x_interrupt_get_pending_allirq(void)
{
    u64_t get = (u64_t)irqCtrlRegs->pendingIRQ2 << 32;
    get |= (u64_t)irqCtrlRegs->pendingIRQ1;
    return (get);
}

u32_t bcm283x_interrupt_get_pending_irq(u32_t irq)
{
    if (irq < 32)
        return ((u32_t)(irqCtrlRegs->pendingIRQ1 & (1 << irq)));
    else if (irq < 64)
        return ((u32_t)(irqCtrlRegs->pendingIRQ2 & (1 << (irq - 32))));
    return (0x0);
}


void bcm283x_interrupt_enable_timerIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.timerIRQ = true;
}

void bcm283x_interrupt_enable_mboxIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.mboxIRQ = true;
}

void bcm283x_interrupt_enable_doorbell0IRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.doorbell0IRQ = true;
}

void bcm283x_interrupt_enable_doorbell1IRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.doorbell1IRQ = true;
}

void bcm283x_interrupt_enable_GPU0haltIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.GPU0haltIRQ = true;
}

void bcm283x_interrupt_enable_GPU1haltIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.GPU1haltIRQ = true;
}

void bcm283x_interrupt_enable_illegalAccessType1(void)
{
    irqCtrlRegs->enableBasicIRQs.illegalAccessType1 = true;
}

void bcm283x_interrupt_enable_illegalAccessType0(void)
{
    irqCtrlRegs->enableBasicIRQs.illegalAccessType0 = true;
}

void bcm283x_interrupt_disable_timerIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.timerIRQ = false;
}

void bcm283x_interrupt_disable_mboxIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.mboxIRQ = false;
}

void bcm283x_interrupt_disable_doorbell0IRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.doorbell0IRQ = false;
}

void bcm283x_interrupt_disable_doorbell1IRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.doorbell1IRQ = false;
}

void bcm283x_interrupt_disable_GPU0haltIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.GPU0haltIRQ = false;
}

void bcm283x_interrupt_disable_GPU1haltIRQ(void)
{
    irqCtrlRegs->enableBasicIRQs.GPU1haltIRQ = false;
}

void bcm283x_interrupt_disable_illegalAccessType1(void)
{
    irqCtrlRegs->enableBasicIRQs.illegalAccessType1 = false;
}

void bcm283x_interrupt_disable_illegalAccessType0(void)
{
    irqCtrlRegs->enableBasicIRQs.illegalAccessType0 = false;
}
