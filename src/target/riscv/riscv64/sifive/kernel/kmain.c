#include "target/riscv/riscv64/sifive/sifive.h"

void __noreturn kmain(void)
{
    FIRE_ASM("wfi");
    while(1);
}