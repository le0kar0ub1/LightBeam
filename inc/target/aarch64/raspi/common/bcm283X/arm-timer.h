#ifndef __BCM283X_ARM_TIMER_H_
#define __BCM283X_ARM_TIMER_H_

#include "kernel/def/typedef.h"

#define BCM283x_ARMTIMER_BASE  ((void *)(ARCH_PERIPHERAL_BASE + 0xB000))
#define BCM283x_ARMTIMER_ENTRY ((void *)(ARCH_PERIPHERAL_BASE + 0xB400))

enum armTimerPrescale {
    Clkdiv1 = 0b00,                                     // 0
    Clkdiv16 = 0b01,                                    // 1
    Clkdiv256 = 0b10,                                   // 2
    Clkdiv_undefined = 0b11,                            // 3 
} ;

struct bcm283x_armTimer_CtrlReg_t
{
    u32_t _unused0 : 1;                          // @0 Unused bit
    u32_t counter  : 1;                      // @1 Counter23 bit (16bit if false)
    enum armTimerPrescale prescale : 2;               // @2-3 Prescale  
    u32_t _unused1 : 1;                          // @4 Unused bit
    u32_t irqEnable : 1;                    // @5 Timer irq enable
    u32_t _unused2 : 1;                          // @6 Unused bit
    u32_t timerEnable : 1;                       // @7 Timer enable
    u32_t _reserved   : 24;                         // @8-31 reserved
};

struct __attribute__((__packed__, aligned(4))) bcm283x_armTimerRegs_t
{
    u32_t load;                                 // 0x00
    const u32_t value;                          // 0x04
    struct bcm283x_armTimer_CtrlReg_t control;  // 0x08
    u32_t irqClr;                                // 0x0C
    const u32_t rawIRQ;                         // 0x10
    const u32_t maskedIRQ;                      // 0x14
    u32_t reload;                               // 0x18
    u32_t prediv;                                // 0x1C
    u32_t _freerun;                              // 0x20
};

void bcm283x_armtimer_set_runtime_value(u32_t);
void bcm283x_armtimer_set_prediv(u32_t);

void bcm283x_armtimer_enable(void);
void bcm283x_armtimer_disable(void);
void bcm283x_armtimer_enable_interrupt(void);
void bcm283x_armtimer_disable_interrupt(void);
void bcm283x_armtimer_set_16bcounter_mode(void);
void bcm283x_armtimer_set_23bcounter_mode(void);
void bcm283x_armtimer_set_prescal(enum armTimerPrescale);
bool bcm283x_armtimer_is_interrupt_pending(void);
void bcm283x_armtimer_clear_interrupt_pending(void);
bool bcm283x_armtimer_get_interrupt_state(void);

#endif