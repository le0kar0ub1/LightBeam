#include "target/riscv/riscv64/sifive/sifive.h"

void __noreturn kmain(void);
void __noreturn kmain(void)
{
    while(1);
    uart_init();
    uart_putc('Z');
}