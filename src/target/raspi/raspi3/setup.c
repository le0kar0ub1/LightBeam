#include "target/raspi/raspi3/driver/uart.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/driver/gpio.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/system.h"
#include "arch/overworld/overworld.h"
#include "lightbleam.h"
#include "def/keyword.h"
// #include "target/raspi/raspi3/interrupts/interrupt.h"
// #include "target/raspi/raspi3/memory/mmu.h"
// #include "def/assert.h"
// #include "kernel/init/inithooks.h"

static inline void start_setup_log(char const *data)
{
    rpifb_kprint("[%$AInitializing%$R]: %s...\n", RGB_Blue, data);
}

static inline void end_setup_log(char const *data)
{
    rpifb_kprint("   [%$ASuccessed%$R]: %s!\n\n", RGB_Lime, data);
}

// void execme(void);
// void execme(void) { rpifb_kprint("[CPU %d] is exceuting a routine\n", cpuGetId()); }

void setup_level(void);
void setup_level(void)
{
    bcm2837_gpio_init();
    bcm2837_uartpl011_init();
    uart_kprint("LALALALA\n");
    uart_init();
    rpifb_init(1024, 768, 32, 1, 0);
    helloFromLightBleam();

    rpifb_kprint("[%$AInitialized%$R]: CPU config\n", RGB_Lime);
    rpifb_kprint("[%$AInitialized%$R]: Uart\n", RGB_Lime);
    rpifb_kprint("[%$AInitialized%$R]: Framebuffer\n\n", RGB_Lime);

    start_setup_log("Cores");
    multicore_init();
    end_setup_log("All of them acquired start");

    start_setup_log("interruptions (vectors, irq, etc.)");

    // if (timerIrqSetup(MS_TO_US(1000)) == false)
        // rpifb_kprint("TIMER SETUP FAILED\n");
    // setFiqFuncAddress(execme);
    // enable_interrupts();

    end_setup_log("interrupts are on");


    start_setup_log("MMU");
    system_charging(2000);
    // // mmu_init();
    end_setup_log("MMU is operationnal");

    rpifb_kprint("[%$ADONE%$R]: init step ended\n", RGB_Yellow);
    __deadloop();
}