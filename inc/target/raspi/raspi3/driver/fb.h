#ifndef __RPIFB_H_
#define __RPIFB_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"


enum MODE256RGBCOLOR
{
    RGB_Black           = 0x000000,
    RGBB_Red            = 0xAA0000,
    RGBB_Green          = 0x00AA00,
    RGBB_Yellow         = 0xAAAA00,
    RGBB_Blue           = 0x0000AA,
    RGBB_Magenta        = 0xAA00AA,
    RGBB_Cyan           = 0x00AAAA,
    RGBB_White          = 0xAAAAAA,
    RGBB_BoldBlack      = 0x555555,
    RGBB_BoldRed        = 0xFF5555,
    RGBB_BoldGreen      = 0x55FF55,
    RGBB_BoldYellow     = 0xFFFF55,
    RGBB_BoldBlue       = 0x5555FF,
    RGBB_BoldMagenta    = 0xFF55FF,
    RGBB_BoldCyan       = 0x55FFFF,
    RGBB_BoldWhite      = 0xFFFFFF,

    RGB_Azure          = 0x0066BB,
    RGB_BoldAzure      = 0x0088FF,
    RGB_Blue           = 0x0000BB,
    RGB_BoldBlue       = 0x0000FF,
    RGB_Cyan           = 0x00BBBB,
    RGB_BoldCyan       = 0x00FFFF,
    RGB_Ebony          = 0x000000,
    RGB_BoldEbony      = 0x666666,
    RGB_Green          = 0x00BB00,
    RGB_BoldGreen      = 0x00FF00,
    RGB_Jade           = 0x00BB66,
    RGB_BoldJade       = 0x00FF88,
    RGB_Lime           = 0x66BB00,
    RGB_BoldLime       = 0x88FF00,
    RGB_Magenta        = 0xBB00BB,
    RGB_BoldMagenta    = 0xFF00FF,
    RGB_Orange         = 0xBB6600,
    RGB_BoldOrange     = 0xFF8800,
    RGB_Pink           = 0xBB0066,
    RGB_BoldPink       = 0xFF0088,
    RGB_Red            = 0xBB0000,
    RGB_BoldRed        = 0xFF0000,
    RGB_Silver         = 0x888888,
    RGB_BoldSilver     = 0xDDDDDD,
    RGB_Tan            = 0x886600,
    RGB_BoldTan        = 0xDDBB00,
    RGB_Violet         = 0x6600BB,
    RGB_BoldViolet     = 0x8800FF,
    RGB_White          = 0xBBBBBB,
    RGB_BoldWhite      = 0xFFFFFF,
    RGB_Yellow         = 0xBBBB00,
    RGB_BoldYellow     = 0xFFFF00,
};

#define RPIFB_256MODE_PREFIX_LENGHT 0x6
#define RPIFB_256MODE_FOREGROUND_PREFIX  "[38;5;"
#define RPIFB_256MODE_BACKGROUND_PREFIX  "[48;5;"
#define RPIFB_256MODE_SUFFIX             'm'
#define RPIFB_256MODE_SUFFIX_LENGHT 0x1

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
    u32_t sequence;
    u32_t color;
} __packed;

void rpifb_init(u32_t, u32_t, u32_t, u32_t, u32_t);

void rpifb_szputs(char const *, u32_t);
void rpifb_puts(char const *);
void rpifb_clear(void);

void rpifb_printfhandler_modcolor(u64_t );
void rpifb_printfhandler_bckcolor(void);
void rpifb_printfhandler_noerasing(void);
void rpifb_kprint(char const *, ...);

void rpifb_set_pos(u32_t, u32_t);
u32_t rpifb_get_posx(void);
u32_t rpifb_get_posy(void);
void rpifb_set_color(u32_t, u32_t);

void rpifb_set_front(u32_t);
void rpifb_set_back(u32_t);

#endif