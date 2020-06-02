#include "target/riscv/riscv64/sifive/sifive.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    enum CPU_STATE state;
    run_boot_initcalls();
    helloFromLightBeam();
    CPU_LOG("Im booting some friends...");
    CLINT_RAISE_SOFT_INT(1);
    while (cpuGetState(1) != CPU_IS_BOOTED);
    CLINT_RAISE_SOFT_INT(2);
    while (cpuGetState(2) != CPU_IS_BOOTED);
    CLINT_RAISE_SOFT_INT(3);
    while (cpuGetState(3) != CPU_IS_BOOTED);
    CLINT_RAISE_SOFT_INT(4);
    while (cpuGetState(4) != CPU_IS_BOOTED);
    CPU_LOG("All my friends acquired start!");
    while(1);
}