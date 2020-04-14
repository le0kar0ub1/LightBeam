#ifndef __BCM283x_RPIFB_H_
#define __BCM283x_RPIFB_H_

#include "kernel/def/typedef.h"

void *bcm283x_rpifb_init(u32_t, u32_t, u32_t, u32_t, u32_t);
u32_t bcm283x_mbox_fb_get_gpiovirt(void);
void * bcm283x_mbox_fb_alloc(int, int, int, int);
bool bcm283x_mbox_fb_setoffset(int, int);
u32_t bcm283x_mbox_fb_get_pitch(void);
bool bcm283x_mbox_fb_set_porder(int);
bool bcm283x_mbox_fb_setalpha(int);

#define BRINGUP_DEFAULT_WIDTH  1024
#define BRINGUP_DEFAULT_HEIGHT 768
#define BRINGUP_DEFAULT_BPP    32
#define BRINGUP_DEFAULT_RENDER 1
#define BRINGUP_DEFAULT_ORDER  0

#endif