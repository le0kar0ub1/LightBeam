#include "target/raspi/raspi3/driver/uart.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/semaphore.h"
#include "arch/overworld/overworld.h"

extern volatile uchar _binary_font_font_psf_start;

static struct lfb_properties properties;

static struct lfb_handler attrib;

#pragma message "make coloration as char escape to ensure buffered compatibitly"

void lfb_set_pos(u32_t x, u32_t y)
{
    attrib.x = x;
    attrib.y = y;
}

u32_t lfb_get_posx(void)
{
    return (attrib.x);
}

u32_t lfb_get_posy(void)
{
    return (attrib.y);
}

void lfb_set_color(u32_t back, u32_t front)
{
    attrib.back = back;
    attrib.front = front;
}

void lfb_init(void)
{
    properties.width = 1024;
    properties.height = 768;
    properties.lfb = bcm2837_mbox_fb_alloc(1024, 768, 32, 1);
    properties.pitch = bcm2837_mbox_fb_get_pitch();
    if (!properties.lfb || !properties.pitch || !bcm2837_mbox_fb_set_porder(0x0))
        uart_puts("[DRIVER] [FB]: Can't be set\n");
    memset(&attrib, 0x0, sizeof(struct lfb_handler));
    attrib.back = RGB_Black;
    attrib.front = RGB_White;
}

void lfb_puts(char const *s)
{
    while (*s) {
        lfb_putchar(*s);
        s++;
    }
}

void lfb_putchar(char c)
{
    psf_t *font = (psf_t *)&_binary_font_font_psf_start;
    // get the offset of the glyph. Need to adjust this to support unicode table
    uchar *glyph = (uchar*)&_binary_font_font_psf_start +
     font->headersize + ((uchar)c < font->numglyph ? c : 0) * font->bytesperglyph;
    // calculate the offset on screen
    int offs = (attrib.y * font->height * properties.pitch) + (attrib.x * (font->width + 1) * 4);
    // variables
    int i, j, line, mask, bytesperline = (font->width + 7) / 8;
    if (c == '\r')
        attrib.x = 0;
    else
        if (c == '\n') {
            attrib.x = 0;
            attrib.y++;
        } else {
            // display a character
            for (j = 0; j < (int)font->height; j++) {
                // display one row
                line= offs;
                mask = 1 << (font->width - 1);
                for (i = 0; i < (int)font->width; i++) {
                    *((u32_t*)(properties.lfb + line)) = ((int)*glyph) & mask ? attrib.front : attrib.back;
                    mask >>= 1;
                    line += 4;
                }
                glyph += bytesperline;
                offs += properties.pitch;
            }
            attrib.x++;
        }
}

void lfb_clear(void)
{
    uchar *ptr = properties.lfb;

    for (u32_t y = 0; y < properties.height; y++) {
        for (u32_t x = 0; x < properties.width; x++) {
            *((u32_t*)ptr) = 0x0;
            ptr += 4;
        }
        ptr += properties.pitch - properties.width * 4;
    }
}