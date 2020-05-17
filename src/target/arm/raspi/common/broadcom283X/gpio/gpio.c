#include "lightbeam.h"
#include "target/arm/raspi/common/bcm283X/gpio.h"
#include "target/arm/raspi/common/bcm283X/mbox.h"
#include "kernel/lib/lib.h"

extern volatile struct gpio_regs_t *gpioregs __aligned(4);

bool bcm283x_gpio_set_mode(pin_t pin, enum GPIOMODE mode)
{
    if (pin > 54 || mode < 0 || mode > 7)
        return (false);
    struct gpio_fnctSlctReg_t *reg;
    switch (pin / 10) {
        case 0:
            reg = (struct gpio_fnctSlctReg_t *)&gpioregs->gpfsel0;
            break;
        case 1:
            reg = (struct gpio_fnctSlctReg_t *)&gpioregs->gpfsel1;
            break;
        case 2:
            reg = (struct gpio_fnctSlctReg_t *)&gpioregs->gpfsel2;
            break;
        case 3:
            reg = (struct gpio_fnctSlctReg_t *)&gpioregs->gpfsel3;
            break;
        case 4:
            reg = (struct gpio_fnctSlctReg_t *)&gpioregs->gpfsel4;
            break;
        case 5:
            reg = (struct gpio_fnctSlctReg_t *)&gpioregs->gpfsel5;
            break;
        default:
            return (false);
    }
    switch (pin % 10) {
        case 0:
            reg->fnctslct0 = mode;
            break;
        case 1:
            reg->fnctslct1 = mode;
            break;
        case 2:
            reg->fnctslct2 = mode;
            break;
        case 3:
            reg->fnctslct3 = mode;
            break;
        case 4:
            reg->fnctslct4 = mode;
            break;
        case 5:
            reg->fnctslct5 = mode;
            break;
        case 6:
            reg->fnctslct6 = mode;
            break;
        case 7:
            reg->fnctslct7 = mode;
            break;
        case 8:
            reg->fnctslct8 = mode;
            break;
        case 9:
            reg->fnctslct9 = mode;
            break;
    }
    return (true);
}

static bool _bcm283x_gpio_get_bitpin_value(pin_t pin, u32_t *ptr)
{
    if (pin > 54)
        return (false);
    if (pin > 31) {
        ptr += 0x4;
        pin -= 32;
    }
    struct gpio_StateReg0_t *state = (struct gpio_StateReg0_t *)ptr;
    switch (pin) {
        case 0:
            return (state->pin0);
        case 1:
            return (state->pin1);
        case 2:
            return (state->pin2);
        case 3:
            return (state->pin3);
        case 4:
            return (state->pin4);
        case 5:
            return (state->pin5);
        case 6:
            return (state->pin6);
        case 7:
            return (state->pin7);
        case 8:
            return (state->pin8);
        case 9:
            return (state->pin9);
        case 10:
            return (state->pin10);
        case 11:
            return (state->pin11);
        case 12:
            return (state->pin12);
        case 13:
            return (state->pin13);
        case 14:
            return (state->pin14);
        case 15:
            return (state->pin15);
        case 16:
            return (state->pin16);
        case 17:
            return (state->pin17);
        case 18:
            return (state->pin18);
        case 19:
            return (state->pin19);
        case 20:
            return (state->pin20);
        case 21:
            return (state->pin21);
        case 22:
            return (state->pin22);
        case 23:
            return (state->pin23);
        case 24:
            return (state->pin24);
        case 25:
            return (state->pin25);
        case 26:
            return (state->pin26);
        case 27:
            return (state->pin27);
        case 28:
            return (state->pin28);
        case 29:
            return (state->pin29);
        case 30:
            return (state->pin30);
        case 31:
            return (state->pin31);
        default:
        return (false);
            break;
    }
}

static void _bcm283x_gpio_set_bitpin_value(pin_t pin, u32_t *ptr, bool val)
{
    if (pin > 54)
        return;
    if (pin > 31) {
        ptr += 0x4;
        pin -= 32;
    }
    struct gpio_StateReg0_t *state = (struct gpio_StateReg0_t *)ptr;
    switch (pin) {
        case 0:
            state->pin0  = val;
            break;
        case 1:
            state->pin1  = val;
            break;
        case 2:
            state->pin2  = val;
            break;
        case 3:
            state->pin3  = val;
            break;
        case 4:
            state->pin4  = val;
            break;
        case 5:
            state->pin5  = val;
            break;
        case 6:
            state->pin6  = val;
            break;
        case 7:
            state->pin7  = val;
            break;
        case 8:
            state->pin8  = val;
            break;
        case 9:
            state->pin9  = val;
            break;
        case 10:
            state->pin10 = val;
            break;
        case 11:
            state->pin11 = val;
            break;
        case 12:
            state->pin12 = val;
            break;
        case 13:
            state->pin13 = val;
            break;
        case 14:
            state->pin14 = val;
            break;
        case 15:
            state->pin15 = val;
            break;
        case 16:
            state->pin16 = val;
            break;
        case 17:
            state->pin17 = val;
            break;
        case 18:
            state->pin18 = val;
            break;
        case 19:
            state->pin19 = val;
            break;
        case 20:
            state->pin20 = val;
            break;
        case 21:
            state->pin21 = val;
            break;
        case 22:
            state->pin22 = val;
            break;
        case 23:
            state->pin23 = val;
            break;
        case 24:
            state->pin24 = val;
            break;
        case 25:
            state->pin25 = val;
            break;
        case 26:
            state->pin26 = val;
            break;
        case 27:
            state->pin27 = val;
            break;
        case 28:
            state->pin28 = val;
            break;
        case 29:
            state->pin29 = val;
            break;
        case 30:
            state->pin30 = val;
            break;
        case 31:
            state->pin31 = val;
            break;
        default:
            break;
    }
}

enum GPIO_PIN_LVL bcm283x_gpio_get_pinlvl(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gplev0));
}


void bcm283x_gpio_set_output(pin_t pin)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpset0, 1);
}

void bcm283x_gpio_clear_output(pin_t pin)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpclr0, 1);
}


bool bcm283x_gpio_get_eventdetectStatus(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gpeds0));
}

void bcm283x_gpio_set_eventdetectStatus(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpeds0, val);
}


bool bcm283x_gpio_get_risingEdgeDetect(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gpren0));
}

void bcm283x_gpio_set_risingEdgeDetect(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpren0, val);
}


bool bcm283x_gpio_get_fallingEdgeDetect(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gpfen0));
}

void bcm283x_gpio_set_fallingEdgeDetect(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpfen0, val);
}


bool bcm283x_gpio_get_highDetect(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gphen0));
}

void bcm283x_gpio_set_highDetect(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gphen0, val);
}


bool bcm283x_gpio_get_lowDetect(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gplen0));
}

void bcm283x_gpio_set_lowDetect(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gplen0, val);
}


bool bcm283x_gpio_get_asyncRisingEdgeDetect(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gparen0));
}

void bcm283x_gpio_set_asyncRisingEdgeDetect(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gparen0, val);
}


bool bcm283x_gpio_get_asyncFallingEdgeDetect(pin_t pin)
{
    return (_bcm283x_gpio_get_bitpin_value(pin, (u32_t *)&gpioregs->gpafen0));
}

void bcm283x_gpio_set_asyncFallingEdgeDetect(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpafen0, val);
}


static void _bcm283x_gpio_set_pullMode(enum GPPUDMODE mode)
{
    _bcm283x_gpio_set_bitpin_value(0, (u32_t *)&gpioregs->gppud, mode & 0b01);
    _bcm283x_gpio_set_bitpin_value(1, (u32_t *)&gpioregs->gppud, mode & 0b10);
}

static void _bcm283x_gpio_set_pullClock(pin_t pin, bool val)
{
    _bcm283x_gpio_set_bitpin_value(pin, (u32_t *)&gpioregs->gpafen0, val);
}

extern void cycle_delay(uint);

void bcm283x_gpio_set_pullClock(pin_t pin, enum GPPUDMODE mode)
{
    _bcm283x_gpio_set_pullMode(mode);
    cycle_delay(150);
    _bcm283x_gpio_set_pullClock(pin, 1);
    cycle_delay(150);
    _bcm283x_gpio_set_pullMode(GGPPUD_OFF);
    _bcm283x_gpio_set_pullClock(pin, 0);
}