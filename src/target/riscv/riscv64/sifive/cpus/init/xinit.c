#include "target/riscv/riscv64/sifive/drivers/uart.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"

/*
** Cores(1-4) entry point
** Triggered by the 0 in kmain()
*/
void xinit(void);
void xinit(void)
{
    cpu_log("booted");
    cpu_set_state(arch_cpu_get_id(), CPU_IS_BOOTED);
    arch_cpu_scheduler();
}