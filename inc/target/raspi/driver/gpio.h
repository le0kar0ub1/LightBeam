#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO_BASE 0x200000 /* Base address of the GPIO */

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

#endif