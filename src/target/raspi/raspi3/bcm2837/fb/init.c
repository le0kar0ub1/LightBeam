#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/bcm2837/fb.h"
#include "arch/overworld/overworld.h"

#pragma message "initcall me"

void *bcm2837_rpifb_init(u32_t width, u32_t height, u32_t bpp, u32_t nrender, u32_t rgb)
{
    void *addr = bcm2837_mbox_fb_alloc(width, height, bpp, nrender);

    if (!addr)
        return (NULL);
    if (!bcm2837_mbox_fb_setoffset(0, 0))
        return (NULL);
    if (!bcm2837_mbox_fb_set_porder(rgb))
        return (NULL);
    return (addr);
}