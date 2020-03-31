#include "target/raspi/raspi3/driver/uart.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/bcm2837/fb.h"
#include "arch/overworld/overworld.h"

volatile struct rpifb_properties properties;
volatile struct rpifb_handler attrib;

// rpifb_init(1024, 768, 32, 1, 0);
void rpifb_init(u32_t width, u32_t height, u32_t bpp, u32_t nrender, u32_t rgb)
{
    properties.width = width;
    properties.height = height;
    properties.lfb = bcm2837_rpifb_init(width, height, bpp, nrender, rgb);
    properties.pitch = bcm2837_mbox_fb_get_pitch();
    if (!properties.lfb || !properties.pitch)
        uart_szputs("[DRIVER] [FB]: Can't be setup\n", 30);
    memset((void *)&attrib, 0x0, sizeof(struct rpifb_handler));
    attrib.back = RGB_Black;
    attrib.front = RGB_White;
}