#include "target/riscv/riscv64/sifive/sifive.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    if (cpuGetId() == 0)
        run_boot_initcalls();
    uart_kprint("booting %d core\n", cpuGetId());
    while(1);
}