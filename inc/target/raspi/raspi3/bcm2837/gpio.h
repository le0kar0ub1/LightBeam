#ifndef __BCM2837_GPIO_H__
#define __BCM2837_GPIO_H__

#include "arch/aarch64/archutils.h"
#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

typedef u32_t pin_t;

#define BCM2837_GPIO_ENTRY ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00200000))

enum GPIO_PIN_LVL {
    LOW  = 0x0,
    HIGH = 0x1
};

enum GPIOMODE {
    GPIO_INPUT    = 0b000,   // 0
    GPIO_OUTPUT   = 0b001,   // 1
    GPIO_ALTFUNC5 = 0b010,   // 2
    GPIO_ALTFUNC4 = 0b011,   // 3
    GPIO_ALTFUNC0 = 0b100,   // 4
    GPIO_ALTFUNC1 = 0b101,   // 5
    GPIO_ALTFUNC2 = 0b110,   // 6
    GPIO_ALTFUNC3 = 0b111    // 7
};

enum GPPUDMODE {
    GGPPUD_OFF      = 0b00,
    GGPPUD_PULLDOWN = 0b01,
    GGPPUD_PULLUP   = 0b10
};

struct gpio_fnctSlctReg_t
{
    enum GPIOMODE fnctslct0 : 3;
    enum GPIOMODE fnctslct1 : 3;
    enum GPIOMODE fnctslct2 : 3;
    enum GPIOMODE fnctslct3 : 3;
    enum GPIOMODE fnctslct4 : 3;
    enum GPIOMODE fnctslct5 : 3;
    enum GPIOMODE fnctslct6 : 3;
    enum GPIOMODE fnctslct7 : 3;
    enum GPIOMODE fnctslct8 : 3;
    enum GPIOMODE fnctslct9 : 3;
    u8_t          _reserved : 2;
};

struct gpio_StateReg0_t
{
    bool pin0  : 1;
    bool pin1  : 1;
    bool pin2  : 1;
    bool pin3  : 1;
    bool pin4  : 1;
    bool pin5  : 1;
    bool pin6  : 1;
    bool pin7  : 1;
    bool pin8  : 1;
    bool pin9  : 1;
    bool pin10 : 1;
    bool pin11 : 1;
    bool pin12 : 1;
    bool pin13 : 1;
    bool pin14 : 1;
    bool pin15 : 1;
    bool pin16 : 1;
    bool pin17 : 1;
    bool pin18 : 1;
    bool pin19 : 1;
    bool pin20 : 1;
    bool pin21 : 1;
    bool pin22 : 1;
    bool pin23 : 1;
    bool pin24 : 1;
    bool pin25 : 1;
    bool pin26 : 1;
    bool pin27 : 1;
    bool pin28 : 1;
    bool pin29 : 1;
    bool pin30 : 1;
    bool pin31 : 1;
};

struct gpio_StateReg1_t
{
    bool      pin32 : 1;
    bool      pin33 : 1;
    bool      pin34 : 1;
    bool      pin35 : 1;
    bool      pin36 : 1;
    bool      pin37 : 1;
    bool      pin38 : 1;
    bool      pin39 : 1;
    bool      pin40 : 1;
    bool      pin41 : 1;
    bool      pin42 : 1;
    bool      pin43 : 1;
    bool      pin44 : 1;
    bool      pin45 : 1;
    bool      pin46 : 1;
    bool      pin47 : 1;
    bool      pin48 : 1;
    bool      pin49 : 1;
    bool      pin50 : 1;
    bool      pin51 : 1;
    bool      pin52 : 1;
    bool      pin53 : 1;
    u32_t _reserved : 10;
};

bool bcm2837_gpio_set_mode(pin_t pin, enum GPIOMODE);

bool bcm2837_gpio_get_eventdetectStatus(pin_t);
bool bcm2837_gpio_get_risingEdgeDetect(pin_t);
bool bcm2837_gpio_get_fallingEdgeDetect(pin_t);
bool bcm2837_gpio_get_highDetect(pin_t);
bool bcm2837_gpio_get_lowDetect(pin_t);
bool bcm2837_gpio_get_asyncRisingEdgeDetect(pin_t);
bool bcm2837_gpio_get_asyncFallingEdgeDetect(pin_t);

void bcm2837_gpio_set_output(pin_t);
void bcm2837_gpio_clear_output(pin_t);
void bcm2837_gpio_set_eventdetectStatus(pin_t, bool);
void bcm2837_gpio_set_risingEdgeDetect(pin_t, bool);
void bcm2837_gpio_set_fallingEdgeDetect(pin_t, bool);
void bcm2837_gpio_set_highDetect(pin_t, bool);
void bcm2837_gpio_set_lowDetect(pin_t, bool);
void bcm2837_gpio_set_asyncRisingEdgeDetect(pin_t, bool);
void bcm2837_gpio_set_asyncFallingEdgeDetect(pin_t, bool);
void bcm2837_gpio_set_pullClock(pin_t, enum GPPUDMODE);

enum GPIO_PIN_LVL bcm2837_gpio_get_pinlvl(pin_t);

struct gpioreg_r_t
{
    void *ptr;
    u32_t (*read)(void);
} __packed;

struct gpioreg_w_t
{
    void *ptr;
    u32_t (*write)(void);
} __packed;

struct gpioreg_rw_t
{
    void *ptr;
    u32_t (*read)(void);
    u32_t (*write)(void);
} __packed;

struct gpio_regs_t
{
    u32_t  gpfsel0;   // GPFSEL0 GPIO Function Select 0 32 R/W
    u32_t  gpfsel1;   // GPFSEL1 GPIO Function Select 1 32 R/W
    u32_t  gpfsel2;   // GPFSEL2 GPIO Function Select 2 32 R/W
    u32_t  gpfsel3;   // GPFSEL3 GPIO Function Select 3 32 R/W
    u32_t  gpfsel4;   // GPFSEL4 GPIO Function Select 4 32 R/W
    u32_t  gpfsel5;   // GPFSEL5 GPIO Function Select 5 32 R/W
    u32_t  _reserved0;
    u32_t  gpset0;    // GPSET0 GPIO Pin Output Set 0 32 W
    u32_t  gpset1;    // GPSET1 GPIO Pin Output Set 1 32 W
    u32_t  _reserved1;
    u32_t  gpclr0;    // GPCLR0 GPIO Pin Output Clear 0 32 W
    u32_t  gpclr1;    // GPCLR1 GPIO Pin Output Clear 1 32 W
    u32_t  _reserved2;
    u32_t  gplev0;    // GPLEV0 GPIO Pin Level 0 32 R
    u32_t  gplev1;    // GPLEV1 GPIO Pin Level 1 32 R
    u32_t  _reserved3;
    u32_t  gpeds0;    // GPEDS0 GPIO Pin Event Detect Status 0 32 R/W
    u32_t  gpeds1;    // GPEDS1 GPIO Pin Event Detect Status 1 32 R/W
    u32_t  _reserved4;
    u32_t  gpren0;    // GPREN0 GPIO Pin Rising Edge Detect Enable 0 32 R/W
    u32_t  gpren1;    // GPREN1 GPIO Pin Rising Edge Detect Enable 1 32 R/W
    u32_t  _reserved5;
    u32_t  gpfen0;    // GPFEN0 GPIO Pin Falling Edge Detect Enable 0 32 R/W
    u32_t  gpfen1;    // GPFEN1 GPIO Pin Falling Edge Detect Enable 1 32 R/W
    u32_t  _reserved6;
    u32_t  gphen0;    // GPIO Pin High Detect Enable 0 32 R/W
    u32_t  gphen1;    // GPIO Pin High Detect Enable 1 32 R/W
    u32_t  _reserved7;
    u32_t  gplen0;    // GPIO Pin Low Detect Enable 0 32 R/W
    u32_t  gplen1;    // GPIO Pin Low Detect Enable 1 32 R/W
    u32_t  _reserved8;
    u32_t  gparen0;   // GPIO Pin Async. Rising Edge Detect 0 32 R/W
    u32_t  gparen1;   // GPIO Pin Async. Rising Edge Detect 1 32 R/W
    u32_t  _reserved9;
    u32_t  gpafen0;   // GPIO Pin Async. Falling Edge Detect 0 32 R/W
    u32_t  gpafen1;   // GPIO Pin Async. Falling Edge Detect 1 32 R/W
    u32_t  _reserved10;
    u32_t  gppud;     // GPIO Pin Pull-up/down Enable 32 R/W
    u32_t  gppudclk0; // GPIO Pin Pull-up/down Enable Clock 0 32 R/W
    u32_t  gppudclk1; // GPIO Pin Pull-up/down Enable Clock 1 32 R/W
    u32_t  _reserved11;
    u32_t  _unused;
};

#define BCM2837_GPIO0       (0)
#define BCM2837_GPIO1       (1)
#define BCM2837_GPIO2       (2)
#define BCM2837_GPIO3       (3)
#define BCM2837_GPIO4       (4)
#define BCM2837_GPIO5       (5)
#define BCM2837_GPIO6       (6)
#define BCM2837_GPIO7       (7)
#define BCM2837_GPIO8       (8)
#define BCM2837_GPIO9       (9)
#define BCM2837_GPIO10      (10)
#define BCM2837_GPIO11      (11)
#define BCM2837_GPIO12      (12)
#define BCM2837_GPIO13      (13)
#define BCM2837_GPIO14      (14)
#define BCM2837_GPIO15      (15)
#define BCM2837_GPIO16      (16)
#define BCM2837_GPIO17      (17)
#define BCM2837_GPIO18      (18)
#define BCM2837_GPIO19      (19)
#define BCM2837_GPIO20      (20)
#define BCM2837_GPIO21      (21)
#define BCM2837_GPIO22      (22)
#define BCM2837_GPIO23      (23)
#define BCM2837_GPIO24      (24)
#define BCM2837_GPIO25      (25)
#define BCM2837_GPIO26      (26)
#define BCM2837_GPIO27      (27)

#define BCM2837_GPIO28      (28)
#define BCM2837_GPIO29      (29)
#define BCM2837_GPIO30      (30)
#define BCM2837_GPIO31      (31)
#define BCM2837_GPIO32      (32)
#define BCM2837_GPIO33      (33)
#define BCM2837_GPIO34      (34)
#define BCM2837_GPIO35      (35)
#define BCM2837_GPIO36      (36)
#define BCM2837_GPIO37      (37)
#define BCM2837_GPIO38      (38)
#define BCM2837_GPIO39      (39)
#define BCM2837_GPIO40      (40)
#define BCM2837_GPIO41      (41)
#define BCM2837_GPIO42      (42)
#define BCM2837_GPIO43      (43)
#define BCM2837_GPIO44      (44)
#define BCM2837_GPIO45      (45)

#define BCM2837_GPIO46      (46)
#define BCM2837_GPIO47      (47)
#define BCM2837_GPIO48      (48)
#define BCM2837_GPIO49      (49)
#define BCM2837_GPIO50      (50)
#define BCM2837_GPIO51      (51)
#define BCM2837_GPIO52      (52)
#define BCM2837_GPIO53      (53)

#define BCM2837_GPIOVIRT0   (64)
#define BCM2837_GPIOVIRT1   (65)

#endif /* __BCM2837_GPIO_H__ */
