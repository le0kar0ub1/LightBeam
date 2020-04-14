#include "lightbeam.h"
#include "target/raspi/common/bcm283X/gpio.h"
#include "kernel/init/initcalls.h"

volatile struct gpio_regs_t *gpioregs __aligned(16);

static void bcm283x_gpio_init(void)
{
    gpioregs = (struct gpio_regs_t *)BCM283x_GPIO_ENTRY;
}

boot_initcall(bcm283x_gpio_init);