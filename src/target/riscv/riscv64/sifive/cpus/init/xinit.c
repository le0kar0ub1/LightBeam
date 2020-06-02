#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"

/*
** Cores(1-4) entry point
** Triggered by the 0 in kmain()
*/
void xinit(void);
void xinit(void)
{
    cpuSetState(CPU_IS_BOOTED);
    uart_kprint("Core %d booted\n", cpuGetId());
    cpuSheduler();
}