#include "target/riscv/riscv64/sifive/sifive.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    run_boot_initcalls();
    helloFromLightBeam();
    uart_kprint("Core %d booting others...\n", cpuGetId());
    CLINT_RAISE_SOFT_INT(1);
    CLINT_RAISE_SOFT_INT(2);
    CLINT_RAISE_SOFT_INT(3);
    CLINT_RAISE_SOFT_INT(4);
    while(1);
}