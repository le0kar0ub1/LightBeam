#include "target/x86/x86.h"
#include "target/x86/common/drivers/serial.h"

static void serial_init(void)
{
    outb(COM1 + 0x1, 0x00);  // Disable all interrupts
    outb(COM1 + 0x3, 0x80);  // Enable DLAB (set baud rate divisor)
    outb(COM1 + 0x0, 0x03);  // Set divisor to 3 (lo byte) 38400 baud
    outb(COM1 + 0X1, 0x00);  //                  (hi byte)
    outb(COM1 + 0x3, 0x03);  // 8 bits, no parity, one stop bit
    outb(COM1 + 0x2, 0xC7);  // Enable FIFO, clear them, with 14-byte threshold
    outb(COM1 + 0X4, 0x0B);  // IRQs enabled, RTS/DSR set
}

boot_initcall(serial_init);