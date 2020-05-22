#include "target/x86/common/interrupts/interrupts.h"
#include "target/x86/common/drivers/vga.h"

#define ERR_PF_PRES 0x1
#define ERR_PF_RW   0x2
#define ERR_PF_USER 0x4
#define ERR_PF_RES  0x8
#define ERR_PF_INST 0x10

void pageFault_handler(struct intframe *frame)
{
    /* Page faults in kernel space leads to death */
     uint64 fault_addr = get_cr2(); /* read cr2 to get faulting address */

     vga_set_color(VGA_BLACK, VGA_RED);
     vga_printf("Page Fault while accessing address : %#X\n", fault_addr);
     /* err_code num pushed by CPU give info on page fault */
     if (!(frame->err_code & ERR_PF_PRES))
         vga_printf("    * No present in memory\n");
     if ((frame->err_code & ERR_PF_RW))
         vga_printf("    * Page is read only\n");
     if ((frame->err_code & ERR_PF_USER))
         vga_printf("    * Kernel page access\n");
     if (frame->err_code & ERR_PF_RES)
         vga_printf("    * Overwritten CPU-reserved bits of page entry\n");
     if (frame->err_code & ERR_PF_INST)
         vga_printf("    * Instruction fetch\n");
    vga_printf("Accesser fault address: %#X\n", frame->eip);
    vga_set_color(VGA_BLACK, VGA_WHITE);
    hlt();
}