#ifndef _VGA_DRIVER_H
#define _VGA_DRIVER_H

#include "target/x86/x86.h"

#define VGA_WIDTH  80
#define VGA_HEIGHT 25

#define VGA_BUFFER_ADDRESS ((uint16 *)(0xB8000))

#define CRTC_DATA  0x3D5
#define CRTC_INDEX 0x3D4

struct vga
{
    uint16  attrib; // AKA the color & text
    uint16 *buff;   // located at physical address 0xB8000
    uint   posx;    // current pos in vga buffer x
    uint   posy;    // current pos in vga buffer y
};

enum vga_color
{
    VGA_BLACK       = 0x0,
    VGA_BLUE        = 0x1,
    VGA_GREEN       = 0x2,
    VGA_CYAN        = 0x3,
    VGA_RED         = 0x4,
    VGA_PINK        = 0x5,
    VGA_BROWN       = 0x6,
    VGA_LIGHT_GREY  = 0x7,
    VGA_DARK_GREY   = 0x8,
    VGA_LIGHT_BLUE  = 0x9,
    VGA_LIGHT_GREEN = 0xA,
    VGA_LIGHT_CYAN  = 0xB,
    VGA_LIGHT_RED   = 0xC,
    VGA_LIGHT_PINK  = 0xD,
    VGA_YELLOW      = 0xE,
    VGA_WHITE       = 0xF
};

void vga_printf(char const *fmt, ...);

void vga_set_color(enum vga_color bg, enum vga_color fg);
void vga_clear(void);

void vga_szputs(char const *s, size_t sz);
void vga_puts(char const *s);
void vga_cursor_enable(uint8, uint8);
void vga_cursor_disable(void);
uint16 vga_cursor_get_position(void);

#endif
