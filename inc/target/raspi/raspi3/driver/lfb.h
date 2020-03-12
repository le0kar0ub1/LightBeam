#ifndef __LFB_H_
#define __LFB_H_

#include "def/typedef.h"

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
} __attribute__((packed));

void lfb_init(void);
void lfb_print(int, int, char const *);
void lfb_clear(void);
void lfb_clear_rect(void);

void lfb_base_intput(int, int);
void lfb_base_longput(long, int);
void lfb_kprint_switch_type(char const **, __builtin_va_list *);
void lfb_kprint(char const *, ...);

void lfb_puts(char const *);
void lfb_putchar(char);

void lfb_set_pos(uint, uint);
void lfb_set_posx(uint);
void lfb_set_posy(uint);

#endif