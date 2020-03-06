#ifndef _GPIO_H_
#define _GPIO_H_

#include "def/typedef.h"

#define GPIO_MODE_00_09 0x0 /* Address of the mode bits for GPIOs 0-9 */
#define GPIO_MODE_10_19 0x4 /* Address of the mode bits for GPIOs 10-19 */
#define GPIO_MODE_20_29 0x8 /* Address of the mode bits for GPIOs 20-29 */

#define GPIO_SET_0_31 0x1C /* Bits to set GPIO pins 0-31 */
#define GPIO_CLR_0_31 0x28 /* Bits to clear GPIO pins 0-31 */
#define GPIO_VAL_0_31 0x34 /* Bits to read GPIO pins 0-31 */

/* See public BCM2835 peripheral document */
#define GPIO08_OUTPUT (1 << 24)
#define GPIO09_OUTPUT (1 << 27)
#define GPIO11_OUTPUT (1 << 3)
#define GPIO14_OUTPUT (1 << 12)
#define GPIO16_OUTPUT (1 << 18)
#define GPIO25_OUTPUT (1 << 15)

void gpio_init(void);
int gpio_read(void);
void gpio_write(int);

#define MAIL0_READ   0x00
#define MAIL0_PEAK   0x10
#define MAIL0_SENDER 0x14
#define MAIL0_STATUS 0x18
#define MAIL0_CONFIG 0x1C
#define MAIL0_WRITE  0x20

#define SYSIO_POWER_MGMT  0
#define SYSIO_FRAMEBUFFER 1
#define SYSIO_UART_VIRT   2
#define SYSIO_VCHIQ       3
#define SYSIO_LEDS        4
#define SYSIO_BUTTONS     5
#define SYSIO_SCREEN      6

struct MMIO_IO
{
    uint channel : 4;
    uint data    : 28; 
};

struct MMIO_STATUS
{
    uint _unused : 30;
    uint empty   : 1;
    uint full    : 1; 
};

#endif