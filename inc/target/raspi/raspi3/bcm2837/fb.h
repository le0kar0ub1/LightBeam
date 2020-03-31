#ifndef __BCM2837_RPIfb_H_
#define __BCM2837_RPIfb_H_

#include "def/typedef.h"

void *bcm2837_rpifb_init(u32_t, u32_t, u32_t, u32_t, u32_t);
u32_t bcm2837_mbox_fb_get_gpiovirt(void);
void * bcm2837_mbox_fb_alloc(int, int, int, int);
bool bcm2837_mbox_fb_setoffset(int, int);
u32_t bcm2837_mbox_fb_get_pitch(void);
bool bcm2837_mbox_fb_set_porder(int);

#endif