#ifndef _x86_APIC__
#define _x86_APIC__

#include "target/x86/x86.h"

#define APIC_REG_BASE_ADDR 0xFEE00000

/*
** Local APIC registers address
*/
enum apic_reg
{
    APIC_ID             = APIC_REG_BASE_ADDR + 0x020, /* ID */
    APIC_VERSION        = APIC_REG_BASE_ADDR + 0x030, /* Version */
    APIC_TPR            = APIC_REG_BASE_ADDR + 0x080, /* Task Priority Register */
    APIC_APR            = APIC_REG_BASE_ADDR + 0x090, /* Arbritation Priority Register */
    APIC_PPR            = APIC_REG_BASE_ADDR + 0x0A0, /* Processor Priority Register */
    APIC_EOI            = APIC_REG_BASE_ADDR + 0x0B0, /* End Of Interrupt */
    APIC_RRD            = APIC_REG_BASE_ADDR + 0x0C0, /* Remote Read Register */
    APIC_LDR            = APIC_REG_BASE_ADDR + 0x0D0, /* Logical Destination Register */
    APIC_DFR            = APIC_REG_BASE_ADDR + 0x0E0, /* Destination Format Register */
    APIC_SIV            = APIC_REG_BASE_ADDR + 0x0F0, /* Spurious Interrupt Vector */
    APIC_ESR            = APIC_REG_BASE_ADDR + 0x280, /* Error Status Register */
    APIC_ICR_LOW        = APIC_REG_BASE_ADDR + 0x300, /* Interrupt Command Register - bits 0-31 */
    APIC_ICR_HIGH       = APIC_REG_BASE_ADDR + 0x310, /* Interrupt Command Register - bits 32-61 */
    APIC_LVT_TIMER      = APIC_REG_BASE_ADDR + 0x320, /* LVT Timer Register */
    APIC_LVT_THERMAL    = APIC_REG_BASE_ADDR + 0x330, /* LVT Thermal Sensor Register */
    APIC_LVT_PERFCOUNT  = APIC_REG_BASE_ADDR + 0x340, /* LVT Performance Counter Register */
    APIC_LVT_LINT0      = APIC_REG_BASE_ADDR + 0x350, /* LVT LINT0 Register */
    APIC_LVT_LINT1      = APIC_REG_BASE_ADDR + 0x360, /* LVT LINT1 Register */
    APIC_LVT_ERROR      = APIC_REG_BASE_ADDR + 0x370, /* LVT Error Register */
    APIC_TIMER_ICR      = APIC_REG_BASE_ADDR + 0x380, /* Timer Initial Count Register */
    APIC_TIMER_CCR      = APIC_REG_BASE_ADDR + 0x390, /* Timer Current Count Register */
    APIC_TIMER_DCR      = APIC_REG_BASE_ADDR + 0x3E0, /* Timer Divide Configuration Register */
};

u32_t apic_get_id(void);
void apic_init(void);

#endif