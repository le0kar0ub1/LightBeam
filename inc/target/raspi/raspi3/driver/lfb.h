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

void lfb_init(void);
void lfb_print(int, int, char const *);
void lfb_clear(void);
void lfb_clear_rect(void);

#endif