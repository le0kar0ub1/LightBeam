#ifndef __BCM2837_RPIFB_H_
#define __BCM2837_RPIFB_H_

#include "def/typedef.h"

void *bcm2837_rpifb_init(u32_t, u32_t, u32_t, u32_t, u32_t);
u32_t bcm2837_mbox_fb_get_gpiovirt(void);
void * bcm2837_mbox_fb_alloc(int, int, int, int);
bool bcm2837_mbox_fb_setoffset(int, int);
u32_t bcm2837_mbox_fb_get_pitch(void);
bool bcm2837_mbox_fb_set_porder(int);
bool bcm2837_mbox_fb_setalpha(int);

#define BRINGUP_DEFAULT_WIDTH  1024
#define BRINGUP_DEFAULT_HEIGHT 768
#define BRINGUP_DEFAULT_BPP    32
#define BRINGUP_DEFAULT_RENDER 1
#define BRINGUP_DEFAULT_ORDER  0


#endif