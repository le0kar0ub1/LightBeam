#include "target/riscv/riscv64/sifive/drivers/uart.h"

extern char const *LightBeamNameArt;

void helloFromLightBeam(void)
{
    uart_kprint(LightBeamNameArt);
    uart_kprint("\nkernel init routine...\n\n");
}