#include "target/aarch64/raspi/raspi3/cpus/cpus.h"
#include "target/aarch64/raspi/raspi3/drivers/fb.h"
#include "target/aarch64/raspi/raspi3/drivers/uart.h"
#include "target/aarch64/raspi/raspi3/system.h"
#include <stdarg.h>

void PANIC(char const *fmt __unused, ...)
{
    // enum CPUS_ID id = arch_cpu_get_id();
    // for (enum CPUS_ID shutoff = CPU0; shutoff <= CPU3; shutoff++)
    //     if (id != shutoff)
    //         cpu_exec_routine(shutoff, __deadloop);
    uart_kprint("[Kernel panic] %s", fmt);
    __deadloop();
}