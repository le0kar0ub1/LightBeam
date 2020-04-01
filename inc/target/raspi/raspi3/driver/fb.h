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


#define FRT_ESCAPE_SEQUENCE256_ANSI(x) "\e[38;5;"#x"m"
#define BCK_ESCAPE_SEQUENCE256_ANSI(x) "\e[48;5;"#x"m"

#define ESC_FRT_RGB_Black        FRT_ESCAPE_SEQUENCE256_ANSI(0)
#define ESC_FRT_RGBB_Red         FRT_ESCAPE_SEQUENCE256_ANSI(1)
#define ESC_FRT_RGBB_Green       FRT_ESCAPE_SEQUENCE256_ANSI(2)
#define ESC_FRT_RGBB_Yellow      FRT_ESCAPE_SEQUENCE256_ANSI(3)
#define ESC_FRT_RGBB_Blue        FRT_ESCAPE_SEQUENCE256_ANSI(4)
#define ESC_FRT_RGBB_Magenta     FRT_ESCAPE_SEQUENCE256_ANSI(5)
#define ESC_FRT_RGBB_Cyan        FRT_ESCAPE_SEQUENCE256_ANSI(6)
#define ESC_FRT_RGBB_White       FRT_ESCAPE_SEQUENCE256_ANSI(7)
#define ESC_FRT_RGBB_BBlack      FRT_ESCAPE_SEQUENCE256_ANSI(8)
#define ESC_FRT_RGBB_BRed        FRT_ESCAPE_SEQUENCE256_ANSI(9)
#define ESC_FRT_RGBB_BGreen      FRT_ESCAPE_SEQUENCE256_ANSI(10)
#define ESC_FRT_RGBB_BYellow     FRT_ESCAPE_SEQUENCE256_ANSI(11)
#define ESC_FRT_RGBB_BBlue       FRT_ESCAPE_SEQUENCE256_ANSI(12)
#define ESC_FRT_RGBB_BMagenta    FRT_ESCAPE_SEQUENCE256_ANSI(13)
#define ESC_FRT_RGBB_BCyan       FRT_ESCAPE_SEQUENCE256_ANSI(13)
#define ESC_FRT_RGBB_BWhite      FRT_ESCAPE_SEQUENCE256_ANSI(15)
#define ESC_FRT_RGB_Azure        FRT_ESCAPE_SEQUENCE256_ANSI(25)
#define ESC_FRT_RGB_BAzure       FRT_ESCAPE_SEQUENCE256_ANSI(33)
#define ESC_FRT_RGB_Blue         FRT_ESCAPE_SEQUENCE256_ANSI(19)
#define ESC_FRT_RGB_BBlue        FRT_ESCAPE_SEQUENCE256_ANSI(21)
#define ESC_FRT_RGB_Cyan         FRT_ESCAPE_SEQUENCE256_ANSI(37)
#define ESC_FRT_RGB_BCyan        FRT_ESCAPE_SEQUENCE256_ANSI(51)
#define ESC_FRT_RGB_Ebony        FRT_ESCAPE_SEQUENCE256_ANSI(16)
#define ESC_FRT_RGB_BEbony       FRT_ESCAPE_SEQUENCE256_ANSI(59)
#define ESC_FRT_RGB_Green        FRT_ESCAPE_SEQUENCE256_ANSI(34)
#define ESC_FRT_RGB_BGreen       FRT_ESCAPE_SEQUENCE256_ANSI(46)
#define ESC_FRT_RGB_Jade         FRT_ESCAPE_SEQUENCE256_ANSI(35)
#define ESC_FRT_RGB_BJade        FRT_ESCAPE_SEQUENCE256_ANSI(48)
#define ESC_FRT_RGB_Lime         FRT_ESCAPE_SEQUENCE256_ANSI(70)
#define ESC_FRT_RGB_BLime        FRT_ESCAPE_SEQUENCE256_ANSI(118)
#define ESC_FRT_RGB_Magenta      FRT_ESCAPE_SEQUENCE256_ANSI(127)
#define ESC_FRT_RGB_BMagenta     FRT_ESCAPE_SEQUENCE256_ANSI(201)
#define ESC_FRT_RGB_Orange       FRT_ESCAPE_SEQUENCE256_ANSI(130)
#define ESC_FRT_RGB_BOrange      FRT_ESCAPE_SEQUENCE256_ANSI(208)
#define ESC_FRT_RGB_Pink         FRT_ESCAPE_SEQUENCE256_ANSI(125)
#define ESC_FRT_RGB_BPink        FRT_ESCAPE_SEQUENCE256_ANSI(198)
#define ESC_FRT_RGB_Red          FRT_ESCAPE_SEQUENCE256_ANSI(124)
#define ESC_FRT_RGB_BRed         FRT_ESCAPE_SEQUENCE256_ANSI(196)
#define ESC_FRT_RGB_Silver       FRT_ESCAPE_SEQUENCE256_ANSI(102)
#define ESC_FRT_RGB_BSilver      FRT_ESCAPE_SEQUENCE256_ANSI(188)
#define ESC_FRT_RGB_Tan          FRT_ESCAPE_SEQUENCE256_ANSI(94)
#define ESC_FRT_RGB_BTan         FRT_ESCAPE_SEQUENCE256_ANSI(178)
#define ESC_FRT_RGB_Violet       FRT_ESCAPE_SEQUENCE256_ANSI(55)
#define ESC_FRT_RGB_BViolet      FRT_ESCAPE_SEQUENCE256_ANSI(93)
#define ESC_FRT_RGB_White        FRT_ESCAPE_SEQUENCE256_ANSI(145)
#define ESC_FRT_RGB_BWhite       FRT_ESCAPE_SEQUENCE256_ANSI(231)
#define ESC_FRT_RGB_Yellow       FRT_ESCAPE_SEQUENCE256_ANSI(142)
#define ESC_FRT_RGB_BYellow      FRT_ESCAPE_SEQUENCE256_ANSI(226)

#define ESC_BCK_RGB_Black        BCK_ESCAPE_SEQUENCE256_ANSI(0)
#define ESC_BCK_RGBB_Red         BCK_ESCAPE_SEQUENCE256_ANSI(1)
#define ESC_BCK_RGBB_Green       BCK_ESCAPE_SEQUENCE256_ANSI(2)
#define ESC_BCK_RGBB_Yellow      BCK_ESCAPE_SEQUENCE256_ANSI(3)
#define ESC_BCK_RGBB_Blue        BCK_ESCAPE_SEQUENCE256_ANSI(4)
#define ESC_BCK_RGBB_Magenta     BCK_ESCAPE_SEQUENCE256_ANSI(5)
#define ESC_BCK_RGBB_Cyan        BCK_ESCAPE_SEQUENCE256_ANSI(6)
#define ESC_BCK_RGBB_White       BCK_ESCAPE_SEQUENCE256_ANSI(7)
#define ESC_BCK_RGBB_BBlack      BCK_ESCAPE_SEQUENCE256_ANSI(8)
#define ESC_BCK_RGBB_BRed        BCK_ESCAPE_SEQUENCE256_ANSI(9)
#define ESC_BCK_RGBB_BGreen      BCK_ESCAPE_SEQUENCE256_ANSI(10)
#define ESC_BCK_RGBB_BYellow     BCK_ESCAPE_SEQUENCE256_ANSI(11)
#define ESC_BCK_RGBB_BBlue       BCK_ESCAPE_SEQUENCE256_ANSI(12)
#define ESC_BCK_RGBB_BMagenta    BCK_ESCAPE_SEQUENCE256_ANSI(13)
#define ESC_BCK_RGBB_BCyan       BCK_ESCAPE_SEQUENCE256_ANSI(13)
#define ESC_BCK_RGBB_BWhite      BCK_ESCAPE_SEQUENCE256_ANSI(15)
#define ESC_BCK_RGB_Azure        BCK_ESCAPE_SEQUENCE256_ANSI(25)
#define ESC_BCK_RGB_BAzure       BCK_ESCAPE_SEQUENCE256_ANSI(33)
#define ESC_BCK_RGB_Blue         BCK_ESCAPE_SEQUENCE256_ANSI(19)
#define ESC_BCK_RGB_BBlue        BCK_ESCAPE_SEQUENCE256_ANSI(21)
#define ESC_BCK_RGB_Cyan         BCK_ESCAPE_SEQUENCE256_ANSI(37)
#define ESC_BCK_RGB_BCyan        BCK_ESCAPE_SEQUENCE256_ANSI(51)
#define ESC_BCK_RGB_Ebony        BCK_ESCAPE_SEQUENCE256_ANSI(16)
#define ESC_BCK_RGB_BEbony       BCK_ESCAPE_SEQUENCE256_ANSI(59)
#define ESC_BCK_RGB_Green        BCK_ESCAPE_SEQUENCE256_ANSI(34)
#define ESC_BCK_RGB_BGreen       BCK_ESCAPE_SEQUENCE256_ANSI(46)
#define ESC_BCK_RGB_Jade         BCK_ESCAPE_SEQUENCE256_ANSI(35)
#define ESC_BCK_RGB_BJade        BCK_ESCAPE_SEQUENCE256_ANSI(48)
#define ESC_BCK_RGB_Lime         BCK_ESCAPE_SEQUENCE256_ANSI(70)
#define ESC_BCK_RGB_BLime        BCK_ESCAPE_SEQUENCE256_ANSI(118)
#define ESC_BCK_RGB_Magenta      BCK_ESCAPE_SEQUENCE256_ANSI(127)
#define ESC_BCK_RGB_BMagenta     BCK_ESCAPE_SEQUENCE256_ANSI(201)
#define ESC_BCK_RGB_Orange       BCK_ESCAPE_SEQUENCE256_ANSI(130)
#define ESC_BCK_RGB_BOrange      BCK_ESCAPE_SEQUENCE256_ANSI(208)
#define ESC_BCK_RGB_Pink         BCK_ESCAPE_SEQUENCE256_ANSI(125)
#define ESC_BCK_RGB_BPink        BCK_ESCAPE_SEQUENCE256_ANSI(198)
#define ESC_BCK_RGB_Red          BCK_ESCAPE_SEQUENCE256_ANSI(124)
#define ESC_BCK_RGB_BRed         BCK_ESCAPE_SEQUENCE256_ANSI(196)
#define ESC_BCK_RGB_Silver       BCK_ESCAPE_SEQUENCE256_ANSI(102)
#define ESC_BCK_RGB_BSilver      BCK_ESCAPE_SEQUENCE256_ANSI(188)
#define ESC_BCK_RGB_Tan          BCK_ESCAPE_SEQUENCE256_ANSI(94)
#define ESC_BCK_RGB_BTan         BCK_ESCAPE_SEQUENCE256_ANSI(178)
#define ESC_BCK_RGB_Violet       BCK_ESCAPE_SEQUENCE256_ANSI(55)
#define ESC_BCK_RGB_BViolet      BCK_ESCAPE_SEQUENCE256_ANSI(93)
#define ESC_BCK_RGB_White        BCK_ESCAPE_SEQUENCE256_ANSI(145)
#define ESC_BCK_RGB_BWhite       BCK_ESCAPE_SEQUENCE256_ANSI(231)
#define ESC_BCK_RGB_Yellow       BCK_ESCAPE_SEQUENCE256_ANSI(142)
#define ESC_BCK_RGB_BYellow      BCK_ESCAPE_SEQUENCE256_ANSI(226)

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