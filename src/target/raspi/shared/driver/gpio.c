#include "target/raspi/driver/gpio.h"
#include "target/raspi/shared.h"
#include "target/raspi/raspi1/proto.h"

void gpio_init(void)
{
    mmioWrite(GPIO_BASE, GPIO_MODE_00_09, GPIO08_OUTPUT | GPIO09_OUTPUT);
    mmioWrite(GPIO_BASE, GPIO_MODE_10_19, GPIO11_OUTPUT | GPIO16_OUTPUT);
    mmioWrite(GPIO_BASE, GPIO_MODE_20_29, GPIO25_OUTPUT);
}

int gpio_read(void)
{
    return ((mmioRead(GPIO_BASE, GPIO_VAL_0_31) & (1 << 14)) ? 1 : 0);
}

void gpio_write(int val)
{
    /* Unset the existing LEDs */
    mmioWrite(GPIO_BASE, GPIO_CLR_0_31, (1 << 8) | (1 << 9) | (1 << 11) | (1 << 25) | (1 << 16));

    /* Determine which GPIO pins to set */
    uint32 set = 0;
    set |= (val & (1 << 0)) ? (1 << 8)  : 0;
    set |= (val & (1 << 1)) ? (1 << 9)  : 0;
    set |= (val & (1 << 2)) ? (1 << 11) : 0;
    set |= (val & (1 << 3)) ? (1 << 25) : 0;
    set |= (val & (1 << 4)) ? (1 << 16) : 0;

    mmioWrite(GPIO_BASE, GPIO_SET_0_31, set);
}