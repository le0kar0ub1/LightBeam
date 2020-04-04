#include "lightbeam.h"
#include "target/raspi/shared/bcm283X/interrupts.h"

extern struct bcm283x_irqControlRegisters_t *irqCtrlRegs;

void bcm283x_interrupt_disable_irq(u32_t irq)
{
    if (irq < 32)
        irqCtrlRegs->disableIRQs1 = 1 << (irq);
    else if (irq < 64)
        irqCtrlRegs->disableIRQs2 = 1 << (irq - 32);
    else
        irqCtrlRegs->disableBasicIRQs = 1 << (irq - 64);

}

void bcm283x_interrupt_enable_irq(u32_t irq)
{
    if (irq < 32)
        irqCtrlRegs->enableIRQs1 = 1 << (irq);
    else if (irq < 64)
        irqCtrlRegs->enableIRQs2 = 1 << (irq - 32);
    else
        irqCtrlRegs->enableBasicIRQs = 1 << (irq - 64);
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