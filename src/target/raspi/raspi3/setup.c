#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/driver/timer.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/system.h"

extern uchar __end;

void start_setup_log(char const *data)
{
    lfb_kprint("[%$AInitializing%$R]: %s...\n", RGB_Maroon, data);
}

void end_setup_log(char const *data)
{
    lfb_kprint("    [%$ASuccessed%$R]: %s!\n", RGB_Lime, data);
}

void init_hook(void)
{
    uart_init();

    lfb_init();
    helloFromLightBleam();

    start_setup_log("interruptions (vectors, irq, etc.)");
    irq_vector_init();
    timer_init();
    enable_interrupt_controller();
    enable_irq();
    end_setup_log("interrupts are on");

    start_setup_log("CPUS warbase");
    multicore_init();
    end_setup_log("All of them acquired start");

    while(1)
        uart_send(uart_getc());
}