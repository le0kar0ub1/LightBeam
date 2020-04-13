#include "target/x86/x86.h"

static void pic_outb(uchar port, uchar data)
{
    outb(port, data);
    io_delay();
}

/*
** Init then disable PIC
*/

void pic_init(void)
{
    /* Start init sequence in cascade mode */
    pic_outb(PORT_PIC_MASTER_CMD, 0x11);
    pic_outb(PORT_PIC_SLAVE_CMD, 0x11);

    /* Set the vector offset */
    pic_outb(PORT_PIC_MASTER_DATA, INT_IRQ0);
    pic_outb(PORT_PIC_SLAVE_DATA, INT_IRQ0 + 8);

    /* Disable PIC by masking all interrupts */
    pic_outb(PORT_PIC_MASTER_DATA, 0xFF);
    pic_outb(PORT_PIC_SLAVE_DATA, 0xFF);

    pic_outb(PORT_PIC_MASTER_DATA, 0b100);
    pic_outb(PORT_PIC_SLAVE_DATA,  0b010);

    /* 80x86 mode, automatic EOI, non buffered */
    pic_outb(PORT_PIC_MASTER_DATA, 0b11);
    pic_outb(PORT_PIC_SLAVE_DATA,  0b11);

    /* Mask the 8259A PIC's interrupts */
    pic_outb(PORT_PIC_MASTER_DATA, 0xFF);
    pic_outb(PORT_PIC_SLAVE_DATA,  0xFF);
}
