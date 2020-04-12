#include "target/x86/i386/interrupts/interrupts.h"

static char const *exception_message[] =
{
    [0x0 ... MAX_INT] = "Unknow interrupt",
    [0x0]  = "Division By Zero",
    [0x1]  = "Debug",
    [0x2]  = "Non Maskable Interrupt",
    [0x3]  = "Breakpoint",
    [0x4]  = "Into Detected Overflow",
    [0x5]  = "Out of Bounds",
    [0x6]  = "Invalid Opcode",
    [0x7]  = "No Coprocessor (not available)",
    [0x8]  = "Double Fault",
    [0x9]  = "Coprocessor Segment Overrun",
    [0xA]  = "Bad TSS",
    [0xB]  = "Segment Not Present",
    [0xC]  = "Stack Fault",
    [0xD]  = "General Protection Fault",
    [0xE]  = "Page Fault",
    [0xF]  = "Unknown Interrupt (reserved)",
    [0x10] = "Coprocessor (FPE) Fault",
    [0x11] = "Alignment Check",
    [0x12] = "Machine Check",
    [0x13] = "SIMD (FPE)",
    [0x14] = "Virtualization exception",
    [0x1E] = "Security exception",
};

void exceptions_handler(struct intframe *frame __unused)
{
    
}