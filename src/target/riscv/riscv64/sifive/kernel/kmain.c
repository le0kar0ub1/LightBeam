#include "target/riscv/riscv64/sifive/sifive.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    //FIRE_ASM("wfi");
    run_initcalls();
    while(1);
}