#include "lightbeam.h"
#include "kernel/def/keyword.h"
#include "target/aarch64/raspi/raspi3/drivers/uart.h"
#include "target/aarch64/raspi/raspi3/drivers/fb.h"
#include "target/aarch64/raspi/raspi3/drivers/gpio.h"
#include "target/aarch64/raspi/common/bcm283X/mbox.h"
#include "target/aarch64/raspi/common/bcm283X/interrupts.h"
#include "target/aarch64/raspi/raspi3/cpus/cpus.h"
#include "target/aarch64/raspi/raspi3/system.h"
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