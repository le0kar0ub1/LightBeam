// #include "target/raspi/raspi3/driver/uart.h"
// #include "target/raspi/raspi3/bcm2837/mbox.h"
// #include "target/raspi/raspi3/driver/fb.h"
// #include "target/raspi/raspi3/semaphore.h"
// #include "arch/overworld/overworld.h"

// extern volatile uchar _binary_font_font_psf_start;

// static struct lfb_properties properties;

// static struct lfb_handler attrib;

// #pragma message "make coloration as char escape to ensure buffered compatibitly"

// void lfb_set_pos(u32_t x, u32_t y)
// {
//     attrib.x = x;
//     attrib.y = y;
// }

// u32_t lfb_get_posx(void)
// {
//     return (attrib.x);
// }

// u32_t lfb_get_posy(void)
// {
//     return (attrib.y);
// }

// void lfb_set_color(u32_t back, u32_t front)
// {
//     attrib.back = back;
//     attrib.front = front;
// }

// void lfb_init(void)
// {
//     mbox[0] = 35 * 4;
//     mbox[1] = MBOX_REQUEST;

//     mbox[2] = 0x48003;  //set phy wh
//     mbox[3] = 8;
//     mbox[4] = 8;
//     mbox[5] = 1024;         //FrameBufferInfo.width
//     mbox[6] = 768;          //FrameBufferInfo.height

//     mbox[7] = 0x48004;  //set virt wh
//     mbox[8] = 8;
//     mbox[9] = 8;
//     mbox[10] = 1024;        //FrameBufferInfo.virtual_width
//     mbox[11] = 768;         //FrameBufferInfo.virtual_height

//     mbox[12] = 0x48009; //set virt offset
//     mbox[13] = 8;
//     mbox[14] = 8;
//     mbox[15] = 0;           //FrameBufferInfo.x_offset
//     mbox[16] = 0;           //FrameBufferInfo.y.offset

//     mbox[17] = 0x48005; //set depth
//     mbox[18] = 4;
//     mbox[19] = 4;
//     mbox[20] = 32;          //FrameBufferInfo.depth

//     mbox[21] = 0x48006; //set pixel order
//     mbox[22] = 4;
//     mbox[23] = 4;
//     mbox[24] = 0;           //RGB

//     mbox[25] = 0x40001; //get framebuffer, gets alignment on request
//     mbox[26] = 8;
//     mbox[27] = 8;
//     mbox[28] = 4096;        //FrameBufferInfo.pointer
//     mbox[29] = 0;           //FrameBufferInfo.size

//     mbox[30] = 0x40008; //get pitch
//     mbox[31] = 4;
//     mbox[32] = 4;
//     mbox[33] = 0;           //FrameBufferInfo.pitch

//     mbox[34] = MBOX_TAG_LAST;

//     if(mbox_call(MBOX_CH_PROP) && mbox[20] == 32 && mbox[28] != 0) {
//         mbox[28] &= 0x3FFFFFFF;   //convert GPU address to ARM address
//         properties.width = mbox[5];          //get actual physical width
//         properties.height = mbox[6];         //get actual physical height
//         properties.pitch = mbox[33];         //get number of bytes per line
//         properties.lfb = (void*)((ulong)mbox[28]);
//     } else {
//         uart_puts("Unable to set screen resolution to 1024x768x32\n");
//     }
//     memset(&attrib, 0x0, sizeof(struct lfb_handler));
//     attrib.back = RGB_Black;
//     attrib.front = RGB_White;
// }

// void lfb_puts(char const *s)
// {
//     while (*s) {
//         lfb_putchar(*s);
//         s++;
//     }
// }

// void lfb_putchar(char c)
// {
//     psf_t *font = (psf_t *)&_binary_font_font_psf_start;
//     // get the offset of the glyph. Need to adjust this to support unicode table
//     uchar *glyph = (uchar*)&_binary_font_font_psf_start +
//      font->headersize + ((uchar)c < font->numglyph ? c : 0) * font->bytesperglyph;
//     // calculate the offset on screen
//     int offs = (attrib.y * font->height * properties.pitch) + (attrib.x * (font->width + 1) * 4);
//     // variables
//     int i, j, line, mask, bytesperline = (font->width + 7) / 8;
//     if (c == '\r')
//         attrib.x = 0;
//     else
//         if (c == '\n') {
//             attrib.x = 0;
//             attrib.y++;
//         } else {
//             // display a character
//             for (j = 0; j < (int)font->height; j++) {
//                 // display one row
//                 line= offs;
//                 mask = 1 << (font->width - 1);
//                 for (i = 0; i < (int)font->width; i++) {
//                     *((u32_t*)(properties.lfb + line)) = ((int)*glyph) & mask ? attrib.front : attrib.back;
//                     mask >>= 1;
//                     line += 4;
//                 }
//                 glyph += bytesperline;
//                 offs += properties.pitch;
//             }
//             attrib.x++;
//         }
// }

// void lfb_clear(void)
// {
//     uchar *ptr = properties.lfb;

//     for (u32_t y = 0; y < properties.height; y++) {
//         for (u32_t x = 0; x < properties.width; x++) {
//             *((u32_t*)ptr) = 0x0;
//             ptr += 4;
//         }
//         ptr += properties.pitch - properties.width * 4;
//     }
// }