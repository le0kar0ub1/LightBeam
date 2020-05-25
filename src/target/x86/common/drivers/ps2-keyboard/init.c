#include "target/x86/x86.h"
#include "target/x86/common/drivers/ps2-keyboard.h"
#include "target/x86/common/interrupts/pic.h"

static void ps2keyboard_init(void)
{
    interrupt_register_handler(INT_IRQ1, ps2keyboard_handler);
    pic_unmask(IRQ1);
}

boot_initcall(ps2keyboard_init);
