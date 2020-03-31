#include "target/raspi/raspi3/bcm2837/fb.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "kernel/scheduler/semaphore.h"
#include "arch/overworld/overworld.h"

extern volatile uchar _binary_font_font_psf_start;

extern volatile struct rpifb_properties properties;

extern volatile struct rpifb_handler attrib;

#pragma message "make coloration as escape sequence to ensure buffered compatibitly"

void rpifb_set_pos(u32_t x, u32_t y)
{
    attrib.x = x;
    attrib.y = y;
}

u32_t rpifb_get_posx(void)
{
    return (attrib.x);
}

u32_t rpifb_get_posy(void)
{
    return (attrib.y);
}

void rpifb_set_color(u32_t back, u32_t front)
{
    attrib.back = back;
    attrib.front = front;
}

void rpifb_puts(char const *s)
{
    while (*s) { 
        rpifb_putc(*s); 
        s++;
    }
}

static struct rpifb_escape_sequence_color_t rpifb_escape_sequence_color[] =
{
    {"[0;31m", RGB_Red},
    {"[0;32m", RGB_Green},
    {"[0;33m", RGB_Yellow},
    {"[0;34m", RGB_Blue},
    {"[0;35m", RGB_Magenta},
    {"[0;36m", RGB_Cyan},
    {"[0m",    RGB_White},
};

static void rpifb_escape_sequence(char c)
{
    static char escape[0x10];
    static u8_t inc = 0x0;
    escape[inc] = c;
}

static bool isInEscapeSequence = false;

void rpifb_putc(char c)
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
    else if (c == '\e' || isInEscapeSequence)
        rpifb_escape_sequence(c);
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

void rpifb_clear(void)
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