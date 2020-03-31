#include "lightbleam.h"
#include "target/raspi/raspi3/bcm2837/gpio.h"
#include "kernel/init/initcalls.h"

volatile struct gpio_regs_t *gpioregs __aligned(16);

void bcm2837_gpio_init(void)
{
    gpioregs = (struct gpio_regs_t *)GPIO_START_POINT;
}

boot_initcall(bcm2837_gpio_init);