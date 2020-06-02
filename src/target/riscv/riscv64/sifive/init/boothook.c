#include "target/riscv/riscv64/sifive/sifive.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

static void boothook(void)
{
    run_boot_initcalls();
    helloFromLightBeam();
    cpu_log("Im booting some friends...");
    arch_cpu_trigger_cpu(1);
    while (cpu_get_state(1) == CPU_IS_UNDEFINED);
    arch_cpu_trigger_cpu(2);
    while (cpu_get_state(2) == CPU_IS_UNDEFINED);
    arch_cpu_trigger_cpu(3);
    while (cpu_get_state(3) == CPU_IS_UNDEFINED);
    arch_cpu_trigger_cpu(4);
    while (cpu_get_state(4) == CPU_IS_UNDEFINED);
    cpu_log("All my friends acquired start!");
}

boot_inithook(boothook);