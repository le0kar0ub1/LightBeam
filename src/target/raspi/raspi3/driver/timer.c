#include "arch/aarch64/archutils.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/mbox.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/datastructure.h"
#include "target/raspi/raspi3/system.h"
#include "target/raspi/raspi3/cpus/cpus.h"

bool timerIrqSetup(u32_t period_in_us)
{
    u32_t Buffer[5] = { 0 };
    bool resValue = false;
    ARMTIMER->Control.TimerEnable = 0;                // Make sure clock is stopped, illegal to change anything while running
    if (mailbox_tag_message(&Buffer[0], 5, MBOX_TAG_GET_CLOCK_RATE, 8, 8, 4, 0)) {
        Buffer[4] /= 250;                     // The prescaler divider is set to 250 (based on GPU=250MHz to give 1Mhz clock)
        Buffer[4] /= 10000;                     // Divid by 10000 we are trying to hold some precision should be in low hundreds (160'ish)
        Buffer[4] *= period_in_us;                  // Multiply by the micro seconds result
        Buffer[4] /= 100;                     // This completes the division by 1000000 (done as /10000 and /100)
        if (Buffer[4] != 0) {                   // Invalid divisor of zero will return with fail
            IRQ->EnableBasicIRQs.Enable_Timer_IRQ = 1;        // Enable the timer interrupt IRQ
            ARMTIMER->Load = Buffer[4];               // Set the load value to divisor
            ARMTIMER->Control.Counter32Bit = 1;           // Counter in 32 bit mode
            ARMTIMER->Control.Prescale = Clkdiv1;         // Clock divider = 1
            ARMTIMER->Control.TimerIrqEnable = 1;         // Enable timer irq
            resValue = true;                    // Set success result
        }
        ARMTIMER->Control.TimerEnable = 1;              // Now start the clock
    }
    return (resValue);                        // Return result value  
}

void LocalTimerSetup(u32_t period_in_us)
{
    volatile u32_t divisor = 384 * period_in_us;       // Transfer the period * 384
    divisor /= 10;                        // That is divisor required as clock is 38.4Mhz (2*19.2Mhz)
    QA7->TimerControlStatus.ReloadValue = divisor;        // Timer period set
    QA7->TimerControlStatus.TimerEnable = 1;          // Timer enabled
    QA7->TimerClearReload.Reload = 1;             // Reload now
}

void LocalTimerIrqSetup(u32_t period_in_us, enum CPUS_ID core)
{
    LocalTimerSetup(period_in_us);
    QA7->TimerRouting.Routing = LOCALTIMER_TO_CORE0_IRQ + core;// Route local timer IRQ to given Core
    QA7->TimerControlStatus.IntEnable = 1;            // Timer IRQ enabled
    QA7->TimerClearReload.IntClear = 1;             // Clear interrupt
    QA7->TimerClearReload.Reload = 1;             // Reload now
    QA7->CoreTimerIntControl[core].nCNTPNSIRQ_IRQ = 1;   // We are in NS EL1 so enable IRQ to core
    QA7->CoreTimerIntControl[core].nCNTPNSIRQ_FIQ = 0;   // Make sure FIQ is zero
}

uintptr_t TimerFiqSetup(u32_t period_in_us, void(*ARMaddress)(void))
{
    u32_t Buffer[5] = { 0 };
    uintptr_t oldHandler = 0;
    ARMTIMER->Control.TimerEnable = 0;                // Make sure clock is stopped, illegal to change anything while running
    if (mailbox_tag_message(&Buffer[0], 5, MBOX_TAG_GET_CLOCK_RATE, 8, 8, 4, 0))
    {
        Buffer[4] /= 250;                     // The prescaler divider is set to 250 (based on GPU=250MHz to give 1Mhz clock)
        Buffer[4] /= 10000;                     // Divid by 10000 we are trying to hold some precision should be in low hundreds (160'ish)
        Buffer[4] *= period_in_us;                  // Multiply by the micro seconds result
        Buffer[4] /= 100;                     // This completes the division by 1000000 (done as /10000 and /100)
        if (Buffer[4] != 0) {                   // Invalid divisor of zero will return with fail
            if (ARMaddress) 
                oldHandler = (uintptr_t)setFiqFuncAddress(ARMaddress);// Change the handler
            ARMTIMER->Load = Buffer[4];               // Set the load value to divisor
            ARMTIMER->Control.Counter32Bit = 1;           // Counter in 32 bit mode
            ARMTIMER->Control.Prescale = Clkdiv1;         // Clock divider = 1
            ARMTIMER->Control.TimerIrqEnable = 1;         // Enable timer irq
            IRQ->FIQControl.SelectFIQSource = 64;         // Select FIQ source as the ARM timer
            IRQ->FIQControl.EnableFIQ = 1;              // Enable the FIQ
        }
        ARMTIMER->Control.TimerEnable = 1;              // Now start the clock
    }
    return oldHandler;                        // Return old handler 
}
