#ifndef __RPIFB_H_
#define __RPIFB_H_

#include "def/typedef.h"
#include "def/keyword.h"

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
    u32_t  magic;
    u32_t  version;
    u32_t  headersize;
    u32_t  flags;
    u32_t  numglyph;
    u32_t  bytesperglyph;
    u32_t  height;
    u32_t  width;
    uchar glyphs;
} __attribute__((packed)) psf_t;

struct rpifb_properties {
    uchar *lfb;
    u32_t width;
    u32_t height;
    u32_t pitch;
} __attribute__((packed));

struct rpifb_handler {
    u32_t x;
    u32_t y;
    u32_t back;
    u32_t front;
} __attribute__((packed));

struct rpifb_escape_sequence_color_t
{
    char const *sequence;
    u32_t color;
} __packed;

void rpifb_init(u32_t, u32_t, u32_t, u32_t, u32_t);

void rpifb_putc(char);
void rpifb_puts(char const *);
void rpifb_print(int, int, char const *);
void rpifb_clear(void);
void rpifb_clear_rect(void);

void rpifb_printfhandler_modcolor(u64_t );
void rpifb_printfhandler_bckcolor(void);
void rpifb_printfhandler_noerasing(void);
void rpifb_kprint(char const *, ...);

void rpifb_puts(char const *);
void rpifb_putc(char);

void rpifb_set_pos(u32_t, u32_t);
u32_t rpifb_get_posx(void);
u32_t rpifb_get_posy(void);
void rpifb_set_color(u32_t, u32_t);

#endif