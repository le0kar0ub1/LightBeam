#include "target/x86/common/drivers/vga.h"

extern char const *LightBeamNameArt;

void helloFromLightBeam(void)
{
    vga_set_color(VGA_BLACK, VGA_YELLOW);
    vga_printf(LightBeamNameArt);
    vga_set_color(VGA_BLACK, VGA_WHITE);
    vga_printf("\nkernel init routine...\n\n");
}