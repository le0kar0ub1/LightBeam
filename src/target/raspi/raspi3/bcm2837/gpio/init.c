#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/gpio.h"
#include "kernel/init/initcalls.h"

volatile struct gpio_regs_t *gpioregs __aligned(16);

static void bcm2837_gpio_init(void)
{
    gpioregs = (struct gpio_regs_t *)BCM2837_GPIO_ENTRY;
}

boot_initcall(bcm2837_gpio_init);