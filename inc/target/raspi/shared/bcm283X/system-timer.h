#ifndef __BCM283X_SYSTEM_TIMER_H_
#define __BCM283X_SYSTEM_TIMER_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

#define BCM283x_SYSTEMTIMER_ENTRY ((void *)(ARCH_RASP_MMIOBASE + 0x3000))

struct bcm283x_systemTimer_ctrl_t
{
    u32_t m0 : 1;
    u32_t m1 : 1;
    u32_t m2 : 1;
    u32_t m3 : 1;
    const u32_t _reserved : 28;
} __packed;

struct bcm283x_systemTimerRegs_t
{
    struct bcm283x_systemTimer_ctrl_t ctrl;      // 0x00
    u32_t clo;       // 0x04
    u32_t chi;       // 0x08
    u32_t cmp0;      // 0x0C
    u32_t cmp1;      // 0x10
    u32_t cmp2;      // 0x14
    u32_t cmp3;      // 0x18
} __packed;

bool bcm283x_systemtimer_get_match(u8_t match);
void bcm283x_systemtimer_clear_match(u8_t match);

u32_t bcm283x_systemtimer_get_high(void);
u32_t bcm283x_systemtimer_get_low(void);
u64_t bcm283x_systemtimer_get_total(void);

u32_t bcm283x_systemtimer_get_comparator(u8_t comparator);
void bcm283x_systemtimer_set_comparator(u8_t comparator);

#endif