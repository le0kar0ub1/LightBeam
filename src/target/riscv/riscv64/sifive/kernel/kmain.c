#include "target/riscv/riscv64/sifive/sifive.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    run_boot_initcalls();
    uart_putc('Z');
    while(1);
}