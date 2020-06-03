#include "target/x86/x86.h"
#include "target/x86/common/drivers/vga.h"

/*
** VGA handling data
*/
static struct vga vga =
{
    .attrib = 0x0,
    .buff = ADD_PTR(VGA_BUFFER_ADDRESS, &__KERNEL_ADDR_TRNS),
    .posx = 0x0,
    .posy = 0x0,
};

/*
** enable the cursor
*/
void vga_cursor_enable(uint8 start, uint8 end)
{
    outb(CRTC_INDEX, 0x0A);
    outb(CRTC_DATA, (inb(CRTC_DATA) & 0xC0) | start);

    outb(CRTC_INDEX, 0x0B);
    outb(CRTC_DATA, (inb(CRTC_DATA) & 0xE0) | end);
}

/*
** disable the cursor
*/
void vga_cursor_disable(void)
{
    outb(CRTC_INDEX, 0x0A);
    outb(CRTC_DATA, 0x20);
}

/*
** Synchronize the cursor with the virtual cursor
*/
static void vga_cursor_update(void)
{
    uint pos = vga.posy * VGA_WIDTH + vga.posx;
    outb(0x3D4, 14);
    outb(0x3D5, pos >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, pos);
}

/*
** Set the screen cursor position
*/
uint16 vga_cursor_get_position(void)
{
    uint16 pos = 0x0;

    outb(CRTC_INDEX, 0x0F);
    pos |= inb(CRTC_DATA);
    outb(CRTC_INDEX, 0x0E);
    pos |= ((uint16)inb(CRTC_DATA)) << 0x8;
    return (pos);
}

/*
** VGA set the background & foreground color
*/
void vga_set_color(enum vga_color bg, enum vga_color fg)
{
    vga.attrib = ((bg << 0x4) | (fg & 0xF)) << 0x8;
}

/*
** scroll one line
*/
static void vga_scroll(void)
{
    void* start = (void *)ADD_TO_PTR(VGA_BUFFER_ADDRESS, VGA_WIDTH * 2);
    uint32_t size = vga.posy * VGA_WIDTH * 2;

    if(vga.posy < VGA_HEIGHT - 0x1)
        return;
    memcpy(VGA_BUFFER_ADDRESS, start, size);
    start = (void *)ADD_TO_PTR(VGA_BUFFER_ADDRESS, size);
    memsetw(start, vga.attrib | 0x20, VGA_WIDTH);
}

/*
** fulle screen clear
*/
void vga_clear(void)
{
    memsetw(vga.buff, vga.attrib | 0x20, VGA_WIDTH * VGA_HEIGHT);
    vga.posx = 0x0;
    vga.posy = 0x0;
    vga_cursor_update();
}

/*
** Print a char
*/
static void vga_putchar(int c)
{
    switch (c)
    {
        case '\n': /* new line */
            vga.posx = 0x0;
            vga.posy++;
            break;
        case '\t': /* tabulation */
            vga.posx = (vga.posx + 8u) & ~7u;
            break;
        case '\r': /* carriage return */
            vga.posx = 0;
            break;
        case '\b': /* backspace */
            if (vga.posx == 0) {
                vga.posy -= (vga.posy > 0);
                vga.posx = VGA_WIDTH - 1;
            } else {
                vga.posx -= (vga.posx > 0);
            }
            break;
        default:
            *(vga.buff + vga.posy * VGA_WIDTH + vga.posx) = vga.attrib | (uchar)c;
            vga.posx += 1;
            break;
    }
    vga.posy += (vga.posx >= VGA_WIDTH);
    vga.posx *= (vga.posx < VGA_WIDTH);
    while (vga.posy >= VGA_HEIGHT) {
        vga_scroll();
        vga.posy -= 1;
    }
}

static spinlock_t lock = SPINLOCK_INIT();

/*
** The printf callable function
*/
void vga_szputs(char const *s, size_t sz)
{
    spinlock_lock(&lock);
    for (size_t i = 0x0; s[i] &&  i < sz; i++)
        vga_putchar(s[i]);
    vga_cursor_update();
    spinlock_unlock(&lock);
}

/*
** Must Not Be Used
*/
void vga_puts(char const *s)
{
    while (*s) {
        vga_putchar(*s);
        s++;
    }
    vga_cursor_update();
}

