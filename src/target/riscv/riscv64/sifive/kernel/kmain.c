#include "target/riscv/riscv64/sifive/sifive.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    run_boot_initcalls();
    uart_kprint("Core %d booting others\n", cpuGetId());
    clint_generate_interrupt(1);
    clint_generate_interrupt(2);
    clint_generate_interrupt(3);
    clint_generate_interrupt(4);
    while(1);
}