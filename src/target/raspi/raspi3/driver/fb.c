#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/mbox.h"

static uint homer_width = 96;
static uint homer_height = 64;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
    pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
    pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
    pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
    data += 4; \
}

uint width, height, pitch, isrgb;   /* dimensions and channel order */
uchar *lfb;                         /* raw frame buffer address */

void lfb_init()
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
        width = mbox[5];          //get actual physical width
        height = mbox[6];         //get actual physical height
        pitch = mbox[33];         //get number of bytes per line
        isrgb = mbox[24];         //get the actual channel order
        lfb = (void*)((ulong)mbox[28]);
    } else {
        uart_puts("Unable to set screen resolution to 1024x768x32\n");
    }
}

void lfb_showpicture()
{
    uchar *ptr = lfb;
    // char *data = (char *)homer_data;
    // char pixel[4];

    // ptr += (height - homer_height) / 2 * pitch + (width - homer_width) * 2;
    // for(uint y = 0; y < homer_height; y++) {
    //     for(uint x = 0; x < homer_width; x++) {
    //         HEADER_PIXEL(data, pixel);
    //         // the image is in RGB. So if we have an RGB framebuffer, we can copy the pixels
    //         // directly, but for BGR we must swap R (pixel[0]) and B (pixel[2]) channels.
    //         *((uint*)ptr) = isrgb ? *((uint *)&pixel) : (uint)(pixel[0]<<16 | pixel[1]<<8 | pixel[2]);
    //         ptr+=4;
    //     }
    //     ptr+=pitch-homer_width*4;
    // }
}