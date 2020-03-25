#include "arch/aarch64/aarchutils.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/mbox.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/datastructure.h"
#include "target/raspi/raspi3/system.h"

bool timer_init(uint32 period_in_us)                // Peripheral clock timer period in usec
{
    uint32 Buffer[5] = { 0 };
    bool resValue = false;
    ARMTIMER->Control.TimerEnable = 0;                // Make sure clock is stopped, illegal to change anything while running
    if (mailbox_tag_message(&Buffer[0], 5,              // Two uint32 responses being clock id and speed and 5 variadics passed
      MBOX_TAG_GET_CLOCK_RATE, 8, 8, 4, 0))          // Get GPU clock (it varies between 200-450Mhz)
    {
      volatile uint32 divisor = Buffer[4] / 250;        // The prescaler divider is set to 250 (based on GPU=250MHz to give 1Mhz clock)
      divisor /= 10000;                     // Divid by 10000 we are trying to hold some precision should be in low hundreds (160'ish)
      divisor *= period_in_us;                  // Multiply by the micro seconds result
      divisor /= 100;                       // This completes the division by 1000000 (done as /10000 and /100)
      if (divisor != 0) {                     // Invalid divisor of zero will return with fail
        ARMTIMER->Load = period_in_us;               // Set the load value to divisor
        ARMTIMER->Control.Counter32Bit = 1;           // Counter in 32 bit mode
        ARMTIMER->Control.Prescale = Clkdiv1;         // Clock divider = 1
        resValue = true;                    // Set success result
      }
      ARMTIMER->Control.TimerEnable = 1;              // Now start the clock
    }
    return (resValue);                        // Return result value
}

bool timerIrqSetup(uint32 period_in_us)              // Period between timer interrupts in usec
{
    if (timer_init(period_in_us))                 // Peripheral time set successful
    {
        IRQ->EnableBasicIRQs.Enable_Timer_IRQ = 1;          // Enable the timer interrupt IRQ
        ARMTIMER->Control.TimerIrqEnable = 1;           // Enable timer irq
        return (true);                        // Return success
    }
    return (false);                         // Return failure 
}