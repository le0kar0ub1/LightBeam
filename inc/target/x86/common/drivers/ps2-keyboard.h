#ifndef _PS2_KEYBOARD_DRIVER_H
#define _PS2_KEYBOARD_DRIVER_H

#include "target/x86/x86.h"
#include "target/x86/common/interrupts/interrupts.h"

static inline uchar read_scan_code(void)
{
    return (inb(PORT_PS2_KEYBOARD_CMD));
}

void printable_fired(struct intframe *frame, uchar getch);
void non_printable_fired(uchar getch);
void ps2keyboard_handler(struct intframe *frame);

#endif
