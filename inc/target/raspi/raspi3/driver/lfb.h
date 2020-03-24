#ifndef __LFB_H_
#define __LFB_H_

#include "def/typedef.h"

enum RGBCOLORS {
    RGB_Black   = 0x000000,
    RGB_White   = 0xFFFFFF,
    RGB_Orange  = 0xFFA500,
    RGB_Red     = 0xFF0000,
    RGB_Lime    = 0x00FF00,
    RGB_Blue    = 0x0000FF,
    RGB_Yellow  = 0xFFFF00,
    RGB_Cyan    = 0x00FFFF,
    RGB_Magenta = 0xFF00FF,
    RGB_Silver  = 0xC0C0C0,
    RGB_Gray    = 0x808080,
    RGB_Maroon  = 0x800000,
    RGB_Olive   = 0x808000,
    RGB_Green   = 0x008000,
    RGB_Purple  = 0x800080,
    RGB_Teal    = 0x008080,
    RGB_Navy    = 0x000080
};

/* PC Screen Font as used by Linux Console */
typedef struct {
    uint  magic;
    uint  version;
    uint  headersize;
    uint  flags;
    uint  numglyph;
    uint  bytesperglyph;
    uint  height;
    uint  width;
    uchar glyphs;
} __attribute__((packed)) psf_t;

struct lfb_properties {
    uchar *lfb;
    uint width;
    uint height;
    uint pitch;
} __attribute__((packed));

struct lfb_handler {
    uint x;
    uint y;
    uint back;
    uint front;
} __attribute__((packed));

void lfb_init(void);
void lfb_print(int, int, char const *);
void lfb_clear(void);
void lfb_clear_rect(void);

void lfb_base_intput(int, int);
void lfb_base_longput(long, int);
void lfb_kprint_switch_type(char const **, __builtin_va_list *);
void lfb_kprint(char const *, ...);
void __lfb_kprint(char const *, __builtin_va_list);

void lfb_puts(char const *);
void lfb_putchar(char);

void lfb_set_pos(uint, uint);
uint lfb_get_posx(void);
uint lfb_get_posy(void);
void lfb_set_color(uint, uint);

#endif