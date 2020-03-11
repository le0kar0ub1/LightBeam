#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/mbox.h"
#include "target/raspi/raspi3/driver/lfb.h"

extern volatile uchar _binary_font_psf_start;

struct lfb_properties properties;

void lfb_init(void)
{
    mbox[0] = 35 * 4;
    mbox[1] = MBOX_REQUEST;

    mbox[2] = 0x48003;  //set phy wh
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = 1024;         //FrameBufferInfo.width
    mbox[6] = 768;          //FrameBufferInfo.height

    mbox[7] = 0x48004;  //set virt wh
    mbox[8] = 8;
    mbox[9] = 8;
    mbox[10] = 1024;        //FrameBufferInfo.virtual_width
    mbox[11] = 768;         //FrameBufferInfo.virtual_height

    mbox[12] = 0x48009; //set virt offset
    mbox[13] = 8;
    mbox[14] = 8;
    mbox[15] = 0;           //FrameBufferInfo.x_offset
    mbox[16] = 0;           //FrameBufferInfo.y.offset

    mbox[17] = 0x48005; //set depth
    mbox[18] = 4;
    mbox[19] = 4;
    mbox[20] = 32;          //FrameBufferInfo.depth

    mbox[21] = 0x48006; //set pixel order
    mbox[22] = 4;
    mbox[23] = 4;
    mbox[24] = 1;           //RGB

    mbox[25] = 0x40001; //get framebuffer, gets alignment on request
    mbox[26] = 8;
    mbox[27] = 8;
    mbox[28] = 4096;        //FrameBufferInfo.pointer
    mbox[29] = 0;           //FrameBufferInfo.size

    mbox[30] = 0x40008; //get pitch
    mbox[31] = 4;
    mbox[32] = 4;
    mbox[33] = 0;           //FrameBufferInfo.pitch

    mbox[34] = MBOX_TAG_LAST;

    if(mbox_call(MBOX_CH_PROP) && mbox[20] == 32 && mbox[28] != 0) {
        mbox[28] &= 0x3FFFFFFF;   //convert GPU address to ARM address
        properties.width = mbox[5];          //get actual physical width
        properties.height = mbox[6];         //get actual physical height
        properties.pitch = mbox[33];         //get number of bytes per line
        properties.lfb = (void*)((ulong)mbox[28]);
    } else {
        uart_puts("Unable to set screen resolution to 1024x768x32\n");
    }
}

void lfb_print(int x, int y, char const *s)
{
    psf_t *font = (psf_t *)&_binary_font_psf_start;
    for (; *s; s++) {
        // get the offset of the glyph. Need to adjust this to support unicode table
        uchar *glyph = (uchar*)&_binary_font_psf_start +
         font->headersize + (*((uchar *)s) < font->numglyph ? *s : 0) * font->bytesperglyph;
        // calculate the offset on screen
        int offs = (y * font->height * properties.pitch) + (x * (font->width + 1) * 4);
        // variables
        int i, j, line, mask, bytesperline = (font->width + 7) / 8;
        if(*s == '\r')
            x = 0;
        else
            if(*s == '\n') {
                x = 0;
                y++;
            } else {
                // display a character
                for(j = 0; j < (int)font->height; j++) {
                    // display one row
                    line= offs;
                    mask = 1 << (font->width - 1);
                    for(i = 0; i < (int)font->width; i++){
                        *((uint*)(properties.lfb + line)) = ((int)*glyph) & mask ? 0xFFFFFF : 0;
                        mask >>= 1;
                        line += 4;
                    }
                    glyph += bytesperline;
                    offs += properties.pitch;
                }
                x++;
            }
    }
}

void lfb_clear(void)
{
    mbox[0] = 7 * 4;
    mbox[1] = MBOX_REQUEST;
    mbox[2] = 0x00040002;
    mbox[3] = 4;
    mbox[4] = 4;
    mbox[5] = 0;
    mbox[6] = MBOX_TAG_LAST;
    mbox_call(MBOX_CH_PROP);
}

void lfb_clear_rect(void)
{
    uchar *ptr = properties.lfb;

    for (uint32 y = 0; y < properties.height; y++) {
        for (uint32 x = 0; x < properties.width; x++) {
            *((uint32*)ptr) = 0x0;
            ptr += 4;
        }
        ptr += properties.pitch - properties.width * 4;
    }
}