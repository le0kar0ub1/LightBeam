#include "def/typedef.h"
#include "target/raspi/driver/gpio.h"
#include "target/raspi/raspi1/proto.h"

void init_hook(void)
{
    gpio_init();
}