#include "lightbeam.h"
#include "target/arm/raspi/common/bcm283X/interrupts.h"

volatile struct bcm283x_irqControlRegisters_t *irqCtrlRegs = NULL;

static void bcm283x_interrupt_init(void)
{
    irqCtrlRegs = (struct bcm283x_irqControlRegisters_t *)BCM283X_INTERRUPT_ENTRY;
    /* disable all IRQs */
    memset((void *)&irqCtrlRegs->disableIRQs1, 0x0, 0x4);
    memset((void *)&irqCtrlRegs->disableIRQs2, 0x0, 0x4);
}

boot_initcall(bcm283x_interrupt_init);