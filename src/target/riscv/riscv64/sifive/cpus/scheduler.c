#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"

/*
** CPU base infinite loop
*/
void cpuSheduler(void)
{
    while (1)
    {
        asm volatile("wfi");
    }
}