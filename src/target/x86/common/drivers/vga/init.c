#include "target/x86/x86.h"
#include "target/x86/common/drivers/vga.h"

static void vga_init(void)
{
    vga_set_color(VGA_BLACK, VGA_WHITE);
    vga_clear();
}

boot_initcall(vga_init);