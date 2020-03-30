#ifndef __DRIVER_GPIO_H__
#define __DRIVER_GPIO_H__

#include "def/typedef.h"
#include "def/keyword.h"

typedef u32_t pin_t;

enum GPIO_PIN_LVL
{
    LOW  = 0x0,
    HIGH = 0x1
};

enum GPIOMODE
{
    GPIO_INPUT    = 0b000,   // 0
    GPIO_OUTPUT   = 0b001,   // 1
    GPIO_ALTFUNC5 = 0b010,   // 2
    GPIO_ALTFUNC4 = 0b011,   // 3
    GPIO_ALTFUNC0 = 0b100,   // 4
    GPIO_ALTFUNC1 = 0b101,   // 5
    GPIO_ALTFUNC2 = 0b110,   // 6
    GPIO_ALTFUNC3 = 0b111    // 7
};

enum GPPUDMODE
{
    GGPPUD_OFF      = 0b00,
    GGPPUD_PULLDOWN = 0b01,
    GGPPUD_PULLUP   = 0b10
};

bool gpio_bcm2837_set_mode(pin_t pin, enum GPIOMODE);

bool gpio_bcm2837_get_eventdetectStatus(pin_t);
bool gpio_bcm2837_get_risingEdgeDetect(pin_t);
bool gpio_bcm2837_get_fallingEdgeDetect(pin_t);
bool gpio_bcm2837_get_highDetect(pin_t);
bool gpio_bcm2837_get_lowDetect(pin_t);
bool gpio_bcm2837_get_asyncRisingEdgeDetect(pin_t);
bool gpio_bcm2837_get_asyncFallingEdgeDetect(pin_t);

void gpio_bcm2837_set_output(pin_t);
void gpio_bcm2837_clear_output(pin_t);
void gpio_bcm2837_set_eventdetectStatus(pin_t, bool);
void gpio_bcm2837_set_risingEdgeDetect(pin_t, bool);
void gpio_bcm2837_set_fallingEdgeDetect(pin_t, bool);
void gpio_bcm2837_set_highDetect(pin_t, bool);
void gpio_bcm2837_set_lowDetect(pin_t, bool);
void gpio_bcm2837_set_asyncRisingEdgeDetect(pin_t, bool);
void gpio_bcm2837_set_asyncFallingEdgeDetect(pin_t, bool);
void gpio_bcm2837_set_pullClock(pin_t, enum GPPUDMODE);

enum GPIO_PIN_LVL gpio_bcm2837_get_pinlvl(pin_t);

#endif