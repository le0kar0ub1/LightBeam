#include "lightbeam.h"
#include "target/aarch64/raspi/raspi3/drivers/fb.h"

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

#define ISNOTHING  0
#define ISBACK     1
#define ISFRONT    2

extern struct colors256Xterm_t colors256Xterm[];

static u32_t rpifb_handle_escape_sequence(char const *s)
{
    u32_t inc = 0x0;
    u8_t which = ISNOTHING;

    if (strlen(s) < 7)
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
    for (i = 0; colors256Xterm[i].s != NULL &&
    colors256Xterm[i].id != nbr; i++);

    if (colors256Xterm[i].s != NULL) {
        if (which == ISBACK)
            rpifb_set_back(colors256Xterm[i].hex);
        else
            rpifb_set_front(colors256Xterm[i].hex);
    }
    return (inc + 1);

}

void rpifb_szputs(char const *s, size_t sz)
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