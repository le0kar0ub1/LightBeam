#include "target/riscv/riscv64/sifive/drivers/uart.h"

/*
** Cores(1-4) entry point
** Triggered by the 0 in kmain()
*/
void xinit(void);
void xinit(void)
{
    uart_kprint("Core %d booted\n", cpuGetId());
    while(1);
}