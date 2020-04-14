#include "target/x86/x86.h"
#include "target/x86/common/drivers/serial.h"

static int serial_received(void)
{
    return inb(COM1 + 5) & 1;
}

static char read_serial(void)
{
    while (serial_received() == 0);
    return inb(COM1);
}

static int is_transmit_empty(void)
{
    return inb(COM1 + 5) & 0x20;
}

static void write_serial(char a)
{
    while (is_transmit_empty() == 0);
    outb(COM1, a);
}

static smplock_t lock = SMPLOCK_INIT();

void serial_szputs(char const *s, size_t sz)
{
    semaphore_inc(&lock);
    for (u32_t i = 0x0; s[i] && i < sz; i++)
        write_serial(s[i]);
    semaphore_dec(&lock);
}

/*
** Must Not Be Used
*/

void serial_puts(char const *s)
{
    for (u32_t i = 0x0; s[i]; i++)
        write_serial(s[i]);
}
