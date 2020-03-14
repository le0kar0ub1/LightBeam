#include <stdbool.h>
#include "target/raspi/raspi3/cpus/cpus.h"

void cpu_warbase(void)
{
    lfb_cpu_log("started");
    while (1);
}