#include "target/raspi/raspi3/interrupts/interrupt.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/common/bcm283X/uart-pl011.h"
#include "arch/aarch64/archutils.h"

void dump_regs(struct rframe_t *regs)
{
    uart_kprint("    pc : %#X\n", regs->pc);
    uart_kprint("    lr : %#X\n", regs->x30);
    uart_kprint("    sp : %#X\n", regs->sp);
    uart_kprint("pstate : %#X\n\n", regs->pstate);

    uart_kprint("   x29 : %#X\n", regs->x29);
    uart_kprint("   x28 : %#X\n", regs->x28);
    uart_kprint("   x27 : %#X\n", regs->x27);
    uart_kprint("   x26 : %#X\n", regs->x26);
    uart_kprint("   x25 : %#X\n", regs->x25);
    uart_kprint("   x24 : %#X\n", regs->x24);
    uart_kprint("   x23 : %#X\n", regs->x23);
    uart_kprint("   x22 : %#X\n", regs->x22);
    uart_kprint("   x21 : %#X\n", regs->x21);
    uart_kprint("   x20 : %#X\n", regs->x20);
    uart_kprint("   x19 : %#X\n", regs->x19);
    uart_kprint("   x18 : %#X\n", regs->x18);
    uart_kprint("   x17 : %#X\n", regs->x17);
    uart_kprint("   x16 : %#X\n", regs->x16);
    uart_kprint("   x15 : %#X\n", regs->x15);
    uart_kprint("   x14 : %#X\n", regs->x14);
    uart_kprint("   x13 : %#X\n", regs->x13);
    uart_kprint("   x12 : %#X\n", regs->x12);
    uart_kprint("   x11 : %#X\n", regs->x11);
    uart_kprint("   x10 : %#X\n", regs->x10);
    uart_kprint("   x9  : %#X\n", regs->x9);
    uart_kprint("   x8  : %#X\n", regs->x8);
    uart_kprint("   x7  : %#X\n", regs->x7);
    uart_kprint("   x6  : %#X\n", regs->x6);
    uart_kprint("   x5  : %#X\n", regs->x5);
    uart_kprint("   x4  : %#X\n", regs->x4);
    uart_kprint("   x3  : %#X\n", regs->x3);
    uart_kprint("   x2  : %#X\n", regs->x2);
    uart_kprint("   x1  : %#X\n", regs->x1);
    uart_kprint("   x0  : %#X\n", regs->x0);
}