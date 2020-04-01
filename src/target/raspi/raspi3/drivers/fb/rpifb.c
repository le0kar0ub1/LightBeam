#include "lightbeam.h"
#include "target/raspi/raspi3/driver/fb.h"

extern volatile uchar _binary_font_font_psf_start;

extern volatile struct rpifb_properties properties;

extern volatile struct rpifb_handler attrib;

static smplock_t lock = SMPLOCK_INIT();

void rpifb_set_pos(u32_t x, u32_t y)
{
    attrib.x = x;
    attrib.y = y;
}

u32_t rpifb_get_posx(void)
{
    return (attrib.x);
}

u32_t rpifb_get_posy(void)
{
    return (attrib.y);
}

void rpifb_set_color(u32_t back, u32_t front)
{
    attrib.back = back;
    attrib.front = front;
}

void rpifb_set_front(u32_t front)
{
    attrib.front = front;
}

void rpifb_set_back(u32_t back)
{
    attrib.back = back;
}


void rpifb_clear(void)
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

static void rpifb_putc(char c)
{
    psf_t *font = (psf_t *)&_binary_font_font_psf_start;
    uchar *glyph = (uchar*)&_binary_font_font_psf_start +
     font->headersize + ((uchar)c < font->numglyph ? c : 0) * font->bytesperglyph;
    int offs = (attrib.y * font->height * properties.pitch) + (attrib.x * (font->width + 1) * 4);
    int i, j, line, mask, bytesperline = (font->width + 7) / 8;
    if (c == '\r')
        attrib.x = 0;
    else
        if (c == '\n') {
            attrib.x = 0;
            attrib.y++;
        } else {
            for (j = 0; j < (int)font->height; j++) {
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

static struct rpifb_escape_sequence_color_t rpifb_escape_sequence_color[] =
{
    {0, RGB_Black}, 
    {1, RGBB_Red}, 
    {2, RGBB_Green}, 
    {3, RGBB_Yellow}, 
    {4, RGBB_Blue}, 
    {5, RGBB_Magenta}, 
    {6, RGBB_Cyan}, 
    {7, RGBB_White}, 
    {8, RGBB_BoldBlack}, 
    {9, RGBB_BoldRed}, 
    {10, RGBB_BoldGreen}, 
    {11, RGBB_BoldYellow}, 
    {12, RGBB_BoldBlue}, 
    {13, RGBB_BoldMagenta}, 
    {13, RGBB_BoldCyan}, 
    {15, RGBB_BoldWhite}, 
    {25, RGB_Azure},
    {33, RGB_BoldAzure},
    {19, RGB_Blue},
    {21, RGB_BoldBlue},
    {37, RGB_Cyan},
    {51, RGB_BoldCyan},
    {16, RGB_Ebony},
    {59, RGB_BoldEbony},
    {34, RGB_Green},
    {46, RGB_BoldGreen},
    {35, RGB_Jade},
    {48, RGB_BoldJade},
    {70, RGB_Lime},
    {118, RGB_BoldLime},
    {127, RGB_Magenta},
    {201, RGB_BoldMagenta},
    {130, RGB_Orange},
    {208, RGB_BoldOrange},
    {125, RGB_Pink},
    {198, RGB_BoldPink},
    {124, RGB_Red},
    {196, RGB_BoldRed},
    {102, RGB_Silver},
    {188, RGB_BoldSilver},
    {94, RGB_Tan},
    {178, RGB_BoldTan},
    {55, RGB_Violet},
    {93, RGB_BoldViolet},
    {145, RGB_White},
    {231, RGB_BoldWhite},
    {142, RGB_Yellow},
    {226, RGB_BoldYellow},
    {0xFFFF, 0xFFFF}
};


#define ISNOTHING  0
#define ISBACK     1
#define ISFRONT    2

static u32_t rpifb_handle_escape_sequence(char const *s)
{
    u32_t inc = 0x0;
    u8_t which = ISNOTHING;

    if (strlen(s) < 8)
        return (inc);
    if (strncmp(s, RPIFB_256MODE_BACKGROUND_PREFIX, RPIFB_256MODE_PREFIX_LENGHT))
        which = ISBACK;
    else if (strncmp(s, RPIFB_256MODE_FOREGROUND_PREFIX, RPIFB_256MODE_PREFIX_LENGHT))
        which = ISFRONT;
    else
        return (0x0);
    inc = RPIFB_256MODE_PREFIX_LENGHT;
    char get[4];
    u32_t i = 0;
    for (; i < 3 && s[inc] != RPIFB_256MODE_SUFFIX; i++, inc++)
        get[i] = s[inc];
    if (s[inc] != RPIFB_256MODE_SUFFIX)
        return (0x0);
    get[i] = 0x0;
    u32_t nbr = atoib(&(*get), 10);
    for (i = 0; rpifb_escape_sequence_color[i].sequence != 0xFFFF &&
    rpifb_escape_sequence_color[i].sequence != nbr; i++);

    if (rpifb_escape_sequence_color[i].sequence != 0xFFFF) {
        if (which == ISBACK)
            rpifb_set_back(rpifb_escape_sequence_color[i].color);
        else
            rpifb_set_front(rpifb_escape_sequence_color[i].sequence);
    }
    return (inc);

}

void rpifb_szputs(char const *s, u32_t sz)
{
    semaphore_inc(&lock);
    for (u32_t pr = 0x0; s[pr] && pr < sz; pr++) 
    {
        switch (s[pr])
        {
            case '\e':
                pr += rpifb_handle_escape_sequence(s + pr + 1);
                break;
            default:
                rpifb_putc(s[pr]);
                break;
        }
    }
    semaphore_dec(&lock);
}