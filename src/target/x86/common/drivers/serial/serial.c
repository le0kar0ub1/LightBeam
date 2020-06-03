#include "target/x86/x86.h"
#include "target/x86/common/drivers/serial.h"

/*
** check if we can receive char from COM
*/
static int serial_received(void)
{
    return inb(COM1 + 5) & 1;
}

/*
** read a char on the COM port
*/
static char read_serial(void)
{
    while (serial_received() == 0);
    return inb(COM1);
}

/*
** chech if the COM is empty
*/
static int is_transmit_empty(void)
{
    return inb(COM1 + 5) & 0x20;
}

/*
** write the given char on the COM port
*/
static void write_serial(char a)
{
    while (is_transmit_empty() == 0);
    outb(COM1, a);
}

static spinlock_t lock = SPINLOCK_INIT();

/*
** the printf callable function 
*/
void serial_szputs(char const *s, size_t sz)
{
    spinlock_lock(&lock);
    for (u32_t i = 0x0; s[i] && i < sz; i++)
        write_serial(s[i]);
    spinlock_unlock(&lock);
}

/*
** Must Not Be Used
*/
void serial_puts(char const *s)
{
    for (u32_t i = 0x0; s[i]; i++)
        write_serial(s[i]);
}
