#include "target/riscv/riscv64/sifive/drivers/uart.h"

void xinit(void);
void xinit(void)
{
    uart_kprint("booting core %d\n", cpuGetId());
    while(1);
}