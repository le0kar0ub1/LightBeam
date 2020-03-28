#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/system.h"
#include "target/raspi/raspi3/memory/mmu.h"
#include "def/assert.h"
#include "arch/overworld/overworld.h"
#include <limits.h>

void start_setup_log(char const *data)
{
    lfb_kprint("[%$AInitializing%$R]: %s...\n", RGB_Blue, data);
}

void end_setup_log(char const *data)
{
    lfb_kprint("   [%$ASuccessed%$R]: %s!\n\n", RGB_Lime, data);
}

void execme(void);
void execme(void) { lfb_kprint("[CPU %d] is exceuting a routine\n", cpuGetId()); }

void init_hook(void)
{
    uart_init();

    lfb_init();
    helloFromLightBleam();

    lfb_kprint("[%$AInitialized%$R]: CPU config\n", RGB_Lime);
    lfb_kprint("[%$AInitialized%$R]: Uart\n", RGB_Lime);
    lfb_kprint("[%$AInitialized%$R]: Framebuffer\n\n", RGB_Lime);

    start_setup_log("Cores");
    multicore_init();
    end_setup_log("All of them acquired start");

    start_setup_log("interruptions (vectors, irq, etc.)");
    if (timerIrqSetup(MS_TO_US(1000)) == false)
        lfb_kprint("TIMER SETUP FAILED\n");
    // setFiqFuncAddress(execme);
    // lfb_kprint("Enabling interrupt...\n");
    // enable_interrupts();
    // EL0_TimerIrqSetup();
    // enable_fiq();

    end_setup_log("interrupts are on");


    assert(cpuExecRoutine(1, execme) == true);
    system_charging(2000);

    start_setup_log("MMU");
    // mmu_init();
    end_setup_log("MMU is operationnal");

    lfb_kprint("[%$ADONE%$R]: init step ended\n", RGB_Yellow);
    while(1)
        uart_send(uart_getc());
}