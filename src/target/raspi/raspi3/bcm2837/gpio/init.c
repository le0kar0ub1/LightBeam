#include "lightbleam.h"
#include "target/raspi/raspi3/bcm2837/gpio.h"

#pragma message "initcall me"

volatile struct gpio_regs_t *gpioregs __aligned(4);

void gpio_bcm2837_init(void)
{
    gpioregs = (struct gpio_regs_t *)GPIO_START_POINT;
}