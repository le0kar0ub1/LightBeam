#ifndef __BCM283X_INTERRUPTS_H_
#define __BCM283X_INTERRUPTS_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

#define BCM283X_INTERRUPT_ENTRY ((void *)(ARCH_RASP_MMIOBASE + 0xB000))

struct __attribute__((__packed__, aligned(4))) irq_basic_pending_reg_t
{
        const u32_t timerIRQ : 1;                // @0 Timer Irq pending
        const u32_t mboxIRQ : 1;                 // @1 Mailbox Irq pending
        const u32_t doorbell0_IRQ : 1;           // @2 Arm Doorbell0 Irq pending
        const u32_t doorbell1_IRQ : 1;           // @3 Arm Doorbell0 Irq pending
        const u32_t GPU0haltIRQ : 1;             // @4 GPU0 halted IRQ pending
        const u32_t GPU1haltIRQ : 1;             // @5 GPU1 halted IRQ pending
        const u32_t illegalAccessType1 : 1;      // @6 illegal access type 1 IRQ pending
        const u32_t illegalAccessType0 : 1;      // @7 illegal access type 0 IRQ pending
        const u32_t bitsSetReg1 : 1;             // @8 One or more bits set in pending register 1
        const u32_t bitsSetReg2 : 1;             // @9 One or more bits set in pending register 2
        const u32_t GPU_IRQ7 : 1;                // @10 GPU irq 7 pending
        const u32_t GPU_IRQ9 : 1;                // @11 GPU irq 9 pending
        const u32_t GPU_IRQ10 : 1;               // @12 GPU irq 10 pending
        const u32_t GPU_IRQ18 : 1;               // @13 GPU irq 18 pending
        const u32_t GPU_IRQ19 : 1;               // @14 GPU irq 19 pending
        const u32_t GPU_IRQ53 : 1;               // @15 GPU irq 53 pending
        const u32_t GPU_IRQ54 : 1;               // @16 GPU irq 54 pending
        const u32_t GPU_IRQ55 : 1;               // @17 GPU irq 55 pending
        const u32_t GPU_IRQ56 : 1;               // @18 GPU irq 56 pending
        const u32_t GPU_IRQ57 : 1;               // @19 GPU irq 57 pending
        const u32_t GPU_IRQ62 : 1;               // @20 GPU irq 62 pending
        u32_t _reserved : 10;                    // @21-31 _reserved
};

struct __attribute__((__packed__, aligned(4))) fiq_control_reg_t
{
    u32_t selectFIQsrc : 7;     // @0-6 Select FIQ source
    u32_t enableFIQ : 1;        // @7 enable FIQ
    u32_t _reserved : 24;       // @8-31 _reserved
};

struct __attribute__((__packed__, aligned(4))) irq_enable_basic_reg_t
{
    u32_t timerIRQ : 1;            // @0 Timer Irq enable
    u32_t mboxIRQ : 1;             // @1 mbox Irq enable
    u32_t doorbell0IRQ : 1;        // @2 Arm Doorbell0 Irq enable
    u32_t doorbell1IRQ : 1;        // @3 Arm Doorbell0 Irq enable
    u32_t GPU0haltIRQ : 1;         // @4 GPU0 halted IRQ enable
    u32_t GPU1haltIRQ : 1;         // @5 GPU1 halted IRQ enable
    u32_t illegalAccessType1 : 1;  // @6 illegal access type 1 IRQ enable
    u32_t illegalAccessType0 : 1;  // @7 illegal access type 0 IRQ enable
    u32_t _reserved : 24;          // @8-31 _reserved
};

struct __attribute__((__packed__, aligned(4))) irq_disable_basic_reg_t
{
    u32_t timerIRQ : 1;             // @0 Timer Irq disable
    u32_t mboxIRQ : 1;              // @1 mbox Irq disable
    u32_t doorbell0IRQ : 1;         // @2 Arm Doorbell0 Irq disable
    u32_t doorbell1IRQ : 1;         // @3 Arm Doorbell0 Irq disable
    u32_t GPU0haltIRQ : 1;          // @4 GPU0 halted IRQ disable
    u32_t GPU1haltIRQ : 1;          // @5 GPU1 halted IRQ disable
    u32_t illegalAccessType1 : 1;   // @6 illegal access type 1 IRQ disable
    u32_t illegalAccessType0 : 1;   // @7 illegal access type 0 IRQ disable
    u32_t _reserved : 24;           // @8-31 _reserved
};

struct __attribute__((__packed__, aligned(4))) bcm283x_irqControlRegisters_t
{
    const struct irq_basic_pending_reg_t IRQBasicPending;      // 0x200
    u32_t pendingIRQ1;                                         // 0x204
    u32_t pendingIRQ2;                                         // 0x208
    struct fiq_control_reg_t FIQCtrl;                          // 0x20C
    u32_t enableIRQs1;                                         // 0x210
    u32_t enableIRQs2;                                         // 0x214
    struct irq_enable_basic_reg_t enableBasicIRQs;             // 0x218
    u32_t disableIRQs1;                                        // 0x21C
    u32_t disableIRQs2;                                        // 0x220
    struct irq_disable_basic_reg_t disableBasicIRQs;           // 0x224
};

void bcm283x_interrupt_disable_irq(u32_t irq);
void bcm283x_interrupt_enable_irq(u32_t irq);

u64_t bcm283x_interrupt_get_pending_allirq(void);
u32_t bcm283x_interrupt_get_pending_irq(u32_t irq);

void bcm283x_interrupt_enable_timerIRQ(void);
void bcm283x_interrupt_enable_mboxIRQ(void);
void bcm283x_interrupt_enable_doorbell0IRQ(void);
void bcm283x_interrupt_enable_doorbell1IRQ(void);
void bcm283x_interrupt_enable_GPU0haltIRQ(void);
void bcm283x_interrupt_enable_GPU1haltIRQ(void);
void bcm283x_interrupt_enable_illegalAccessType1(void);
void bcm283x_interrupt_enable_illegalAccessType0(void);

void bcm283x_interrupt_disable_timerIRQ(void);
void bcm283x_interrupt_disable_mboxIRQ(void);
void bcm283x_interrupt_disable_doorbell0IRQ(void);
void bcm283x_interrupt_disable_doorbell1IRQ(void);
void bcm283x_interrupt_disable_GPU0haltIRQ(void);
void bcm283x_interrupt_disable_GPU1haltIRQ(void);
void bcm283x_interrupt_disable_illegalAccessType1(void);
void bcm283x_interrupt_disable_illegalAccessType0(void);


#endif