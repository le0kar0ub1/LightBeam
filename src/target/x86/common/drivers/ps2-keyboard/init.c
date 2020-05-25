#include "target/x86/x86.h"
#include "target/x86/common/drivers/ps2-keyboard.h"
#include "target/x86/common/interrupts/pic.h"

static void ps2keyboard_init(void)
{
    pic_unmask(IRQ1);
}

boot_initcall(ps2keyboard_init);
