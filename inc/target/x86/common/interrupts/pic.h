#ifndef __PIC_H_
#define __PIC_H_

#include "target/x86/x86.h"

#define PIC_EOI 0x20

static inline void pic_eoi(uint8 irq)
{
    if(irq > 0x8)
        outb(PORT_PIC_SLAVE_CMD, PIC_EOI);
    outb(PORT_PIC_MASTER_CMD, PIC_EOI);
}

static inline void pic_mask(uint8 irq)
{
    uint8 curmask_master = inb(PORT_PIC_SLAVE_DATA);
    outb(PORT_PIC_MASTER_DATA, curmask_master | (1 << irq));
}

static inline void pic_unmask(uint8 irq)
{
    uint8 curmask_master = inb(PORT_PIC_MASTER_DATA);
    outb(PORT_PIC_MASTER_DATA, curmask_master & ~(1 << irq));
}

#define IRQ0  0x0 // timer
#define IRQ1  0x1 // keyboard
#define IRQ2  0x2 // cascade PIC
#define IRQ3  0x3 // COM2
#define IRQ4  0x4 // COM1
#define IRQ5  0x5 // LPT2
#define IRQ6  0x6 // Floppy disk
#define IRQ7  0x7 // LTP1
#define IRQ8  0x8 // CMOS real-time clock
#define IRQ9  0x9 // Free for peripherals (SCSI / NIC)
#define IRQ10 0xA // Free for peripherals (SCSI / NIC)
#define IRQ11 0xB // Free for peripherals (SCSI / NIC)
#define IRQ12 0xC // PS2 MOUSE
#define IRQ13 0xD // FPU (Floating Point Unit) / Coprocessor / inter-processor
#define IRQ14 0xE // Primary ATA hard disk
#define IRQ15 0xF // Secondary ATA hard disk

void pic_init(void);

#endif