#include "target/raspi/raspi3/driver/uart.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/cpus/semaphore.h"
#include "arch/overworld/overworld.h"

volatile struct lfb_properties properties;
volatile struct lfb_handler attrib;

void fb_init(void)
{
    properties.width = 1024;
    properties.height = 768;
    properties.lfb = bcm2837_mbox_fb_alloc(1024, 768, 32, 1);
    properties.pitch = bcm2837_mbox_fb_get_pitch();
    if (!properties.lfb || !properties.pitch || !bcm2837_mbox_fb_set_porder(0x0))
        uart_puts("[DRIVER] [FB]: Can't be set\n");
    memset((void *)&attrib, 0x0, sizeof(struct lfb_handler));
    attrib.back = RGB_Black;
    attrib.front = RGB_White;
}