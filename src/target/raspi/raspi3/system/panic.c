#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/drivers/fb.h"
#include "target/raspi/raspi3/drivers/uart.h"
#include "target/raspi/raspi3/system.h"
#include <stdarg.h>

void PANIC(char const *fmt __unused, ...)
{
    enum CPUS_ID id = cpuGetId();
    for (enum CPUS_ID shutoff = CPU0; shutoff <= CPU3; shutoff++)
        if (id != shutoff)
            cpuExecRoutine(shutoff,__deadloop);
    uart_kprint("[Kernel panic] %s", fmt);
    __deadloop();
}