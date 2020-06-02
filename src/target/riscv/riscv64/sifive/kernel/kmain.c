#include "target/riscv/riscv64/sifive/sifive.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"
#include "target/riscv/riscv64/sifive/drivers/uart.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    run_inithooks();
    while(1);
}