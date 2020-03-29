#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/driver/uart.h"
#include "target/raspi/raspi3/system.h"
#include <stdarg.h>

void PANIC(char const *fmt __unused, ...)
{
    enum CPUS_ID id = cpuGetId();
    for (enum CPUS_ID shutoff = CPU0; shutoff <= CPU3; shutoff++)
        if (id != shutoff)
            cpuExecRoutine(shutoff,__deadloop);
    uart_puts("[Kernel panic] ");
    uart_puts(fmt);
    __deadloop();
}