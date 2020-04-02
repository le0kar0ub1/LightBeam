#include "lightbeam.h"
#include "kernel/def/keyword.h"
#include "target/raspi/raspi3/drivers/uart.h"
#include "target/raspi/raspi3/drivers/fb.h"
#include "target/raspi/raspi3/drivers/gpio.h"
#include "target/raspi/shared/bcm283X/mbox.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/system.h"
#include "kernel/lib/lib.h"
#include "kernel/init/initcalls.h"

static inline void start_setup_log(char const *data)
{
    rpifb_kprint("[%sInitializing%s]: %s...\n", RGB256toESCFRT(Lime), RGB256toESCFRT(White), data);
}

static inline void end_setup_log(char const *data)
{
    rpifb_kprint("   [%sSuccessed%s]: %s!\n\n", RGB256toESCFRT(Lime), RGB256toESCFRT(White), data);
}

void timerIrqSetup(void)
{
    u32_t us = 2000;
    int rate = bcm283x_mbox_clock_get_rate(MBOX_CLOCK_ID_ARM) / 250;
    if (!rate)
        uart_kprint("FAILED RATE\n");
    rate = (rate * us) / 1000000;
    armtimer_init(rate);
}

void setup_level(void);
void setup_level(void)
{
    /* boot init calls running */
    run_boot_initcalls();

    /* Uartpl011 setup */
    uart_init();

    /* RPI framebuffer */
    rpifb_init(1024, 768, 32, 1, 0);

    helloFromLightBeam();

    rpifb_kprint("[%sInitialized%s]: CPU config\n", RGB256toESCFRT(Blue), RGB256toESCFRT(White));
    rpifb_kprint("[%sInitialized%s]: Uart\n", RGB256toESCFRT(Blue), RGB256toESCFRT(White));
    rpifb_kprint("[%sInitialized%s]: Framebuffer\n\n", RGB256toESCFRT(Blue), RGB256toESCFRT(White));

    start_setup_log("Cores");
    multicore_init();
    end_setup_log("All of them acquired start");

    start_setup_log("interruptions (vectors, irq, etc.)");
    timerIrqSetup();
    enable_interrupts();
    end_setup_log("interrupts are on");

    /* pure init calls running */
    run_pure_initcalls();

    start_setup_log("MMU");
    system_charging(2000);
    // mmu_init();
    end_setup_log("MMU is operationnal");

    rpifb_kprint("[%sDONE%s]: init step ended\n", RGB256toESCFRT(Yellow), RGB256toESCFRT(White));
    __deadloop();
}