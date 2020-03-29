#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/system.h"
#include <stdarg.h>

void PANIC(char const *fmt __unused, ...)
{
    lfb_puts("Kernel panic...");
    __deadloop();
}