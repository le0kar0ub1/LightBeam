#include "target/raspi/raspi3/driver/uart.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "arch/overworld/overworld.h"

/* mailbox message buffer */
volatile uint32_t  __attribute__((aligned(16))) mbox[36];

#define VIDEOCORE_MBOX  (ARCH_RASP_MMIOBASE+0x0000B880)
#define MBOX_READ       ((volatile uint32_t*)(VIDEOCORE_MBOX+0x0))
#define MBOX_POLL       ((volatile uint32_t*)(VIDEOCORE_MBOX+0x10))
#define MBOX_SENDER     ((volatile uint32_t*)(VIDEOCORE_MBOX+0x14))
#define MBOX_STATUS     ((volatile uint32_t*)(VIDEOCORE_MBOX+0x18))
#define MBOX_CONFIG     ((volatile uint32_t*)(VIDEOCORE_MBOX+0x1C))
#define MBOX_WRITE      ((volatile uint32_t*)(VIDEOCORE_MBOX+0x20))
#define MBOX_RESPONSE   0x80000000
#define MBOX_FULL       0x80000000
#define MBOX_EMPTY      0x40000000

struct __attribute__((__packed__, aligned(4))) mbox_registers
{
        const volatile uint32_t read_0; // 0x00         Read data from VC to ARM
        uint32_t unused[3];             // 0x04-0x0F
        volatile uint32_t peek_0;       // 0x10
        volatile uint32_t sender_0;     // 0x14
        volatile uint32_t status_0;     // 0x18         Status of VC to ARM
        volatile uint32_t config0;      // 0x1C
        volatile uint32_t write_1;      // 0x20         Write data from ARM to VC
        uint32_t unused_2[3];           // 0x24-0x2F
        volatile uint32_t peek_1;       // 0x30
        volatile uint32_t sender_1;     // 0x34
        volatile uint32_t status_1;     // 0x38         Status of ARM to VC
        volatile uint32_t config_1;     // 0x3C
};

_Static_assert((sizeof(struct mbox_registers) == 0x40), "Structure MailBoxRegisters should be 0x40 bytes in size");

#define MAILBOX_FOR_READ_WRITES ((volatile __attribute__((aligned(4))) struct mbox_registers*)(uint32_t *)(ARCH_RASP_MMIOBASE + 0xB880))
#define MBOX_CH_POWER   0
#define MBOX_CH_FB      1
#define MBOX_CH_VUART   2
#define MBOX_CH_VCHIQ   3
#define MBOX_CH_LEDS    4
#define MBOX_CH_BTNS    5
#define MBOX_CH_TOUCH   6
#define MBOX_CH_COUNT   7
#define MBOX_CH_PROP    8

/* tags */
#define MBOX_TAG_SETPOWER       0x28001
#define MBOX_TAG_SETCLKRATE     0x38002
#define MBOX_TAG_SETVOLTAGE	0x38003
#define MBOX_TAG_LAST           0
#define MBOX_REQUEST    0
#define MAIL_EMPTY	0x40000000		/* Mailbox Status Register: Mailbox Empty */
#define MAIL_FULL	0x80000000	/* Mailbox Status Register: Mailbox Full  */
/**
 * Make a mailbox call. Returns 0 on failure, non-zero on success
 */
int32_t mailbox_call(uint8_t ch)
{
	uint32_t r;
	/* wait until we can write to the mailbox */
	do{asm volatile("nop");}while(*MBOX_STATUS & MBOX_FULL);
	/* write the address of our message to the mailbox with channel identifier */
	*MBOX_WRITE = (((uint32_t)((uint64_t)&mailbox)&~0xF) | (ch&0xF));
	/* now wait for the response */
	while(1) {
		/* is there a response? */
		do{asm volatile("nop");}while(*MBOX_STATUS & MBOX_EMPTY);
		r=*MBOX_READ;
		/* is it a response to our message? */
		if((unsigned char)(r&0xF)==ch && (r&~0xF)==(uint32_t)((uint64_t)&mailbox))
			/* is it a valid successful response? */
			return mailbox[1]==MBOX_RESPONSE;
	}
	return 0;
}

extern volatile uchar _binary_font_font_psf_start;

static struct lfb_properties properties;

static struct lfb_handler attrib;

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
    mbox[24] = 0;           //RGB

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
    memset(&attrib, 0x0, sizeof(struct lfb_handler));
    attrib.back = RGB_Black;
    attrib.front = RGB_White;
}

void lfb_puts(char const *s)
{
    while (*s) {
        lfb_putc(*s);
        s++;
    }
}

void lfb_putc(char c)
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