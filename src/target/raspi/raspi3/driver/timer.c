#include "arch/aarch64/aarchutils.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/mbox.h"
#include "target/raspi/raspi3/driver/timer.h"

const uint interval = 200000;
uint curVal = 0;

// void timer_init(void)
// {
//     curVal = get32(TIMER_CLO);
//     curVal += interval;
//     put32(TIMER_C1, curVal);
// }

void handle_timer_irq(void) 
{
    uart_puts("Timer interrupt received\n");
    curVal += interval;
    put32(TIMER_C1, curVal);
    put32(TIMER_CS, TIMER_CS_M1);
}

void timer_init(void)
{
    // uint  divisor;
    // Make sure clock is stopped, illegal to change anything while running
    #define ARMTIMER_CONTROL ((volatile uint *)(ARCH_RASP_MMIOBASE + 0xB408))
    #define RPI_ARMTIMER_CTRL_ENABLE (1 << 7)
    #define MBOX_TAG_GET_CLOCK_RATE	0x00030002
    *ARMTIMER_CONTROL &= ~(RPI_ARMTIMER_CTRL_ENABLE); 
    // Get GPU clock (it varies between 200-450Mhz)
    mbox[0] = (5 + 3) * 4;                  // length of the message
    mbox[1] = MBOX_REQUEST;         // this is a request message
    
    mbox[2] = MBOX_TAG_GET_CLOCK_RATE;
    mbox[3] = 8;                    // buffer size
    mbox[4] = 8;
    mbox[5] = 4;                    // CLOCK ID: CORE
    mbox[6] = 0;                    // Clock Frequency

    mbox[7] = MBOX_TAG_LAST;

    // send the message to the GPU and receive answer
    if (mbox_call(MBOX_CH_PROP)) {
      uart_kprint("\nclock freq: %d Hz\n", mbox[6]);
      // The prescaler divider is set to 250 (based on GPU=250MHz to give 1Mhz clock)
      mbox[6] /= 250;
      // Divisor we would need at current clock speed
      // divisor = ((uint64)interval * mbox[6]) / 1000000;
    }
}