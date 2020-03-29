#include "target/raspi/raspi3/delay.h"
#include "target/raspi/raspi3/driver/gpio.h"

#define SYSTMR_LO        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00003004))
#define SYSTMR_HI        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00003008))

/* ARM processor allow a nop instruction usefull */
void wait_cycles(u32_t n)
{
    if (n)
        while(n--)
            asm volatile("nop"); 
}

/**
 * Wait N microsec (ARM CPU only)
 */
void wait_msec(u32_t n)
{
    register ulong f, t, r;
    // get the current counter frequency
    asm volatile ("mrs %0, cntfrq_el0" : "=r"(f));
    // read the current counter
    asm volatile ("mrs %0, cntpct_el0" : "=r"(t));
    // calculate expire value for counter
    t += ((f / 1000) * n) / 1000;
    while(r < t)
        asm volatile ("mrs %0, cntpct_el0" : "=r"(r));
}

/**
 * Get System Timer's counter
 */
ulong get_system_timer()
{
    u32_t h = -1, l;
    // we must read MMIO area as two separate 32 bit reads
    h =* SYSTMR_HI;
    l =* SYSTMR_LO;
    // we have to repeat it if high word changed during read
    if(h != *SYSTMR_HI) {
        h = *SYSTMR_HI;
        l = *SYSTMR_LO;
    }
    // compose long int value
    return ((ulong) h << 32) | l;
}

/**
 * Wait N microsec (with BCM System Timer)
 */
void wait_msec_st(u32_t n)
{
    ulong t=get_system_timer();
    // we must check if it's non-zero, because qemu does not emulate
    // system timer, and returning constant zero would mean infinite loop
    if (t)
        while(get_system_timer() < t + n);
}