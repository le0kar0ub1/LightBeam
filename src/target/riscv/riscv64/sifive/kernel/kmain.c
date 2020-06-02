#include "target/riscv/riscv64/sifive/sifive.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

static int test(int argc, char **argv)
{

}

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    run_boot_initcalls();
    helloFromLightBeam();
    uart_kprint("Core %d booting others...\n", cpuGetId());
    CLINT_RAISE_SOFT_INT(1);
    while (cpuGetState(1) != CPU_IS_BOOTED);
    CLINT_RAISE_SOFT_INT(2);
    while (cpuGetState(2) != CPU_IS_BOOTED);
    CLINT_RAISE_SOFT_INT(3);
    while (cpuGetState(3) != CPU_IS_BOOTED);
    CLINT_RAISE_SOFT_INT(4);
    while (cpuGetState(4) != CPU_IS_BOOTED);
    uart_kprint("All cores acquired start!\n");
    cpuExecRoutine(2, test, 0, NULL);
    while(1);
}