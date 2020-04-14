#include "target/raspi/common/bcm283X/mbox.h"
#include "target/raspi/common/bcm283X/fb.h"
#include "kernel/lib/lib.h"

/* We will provide driver function when needed */
// https://github.com/raspberrypi/firmware/wiki/Mailbox-property-interface

/*
 * Mbox framebuffer
 */
enum {
    MBOX_TAG_FB_GET_GPIOVIRT        = 0x00040010,
    MBOX_TAG_FB_ALLOCATE_BUFFER     = 0x00040001,
    MBOX_TAG_FB_RELEASE_BUFFER      = 0x00048001,
    MBOX_TAG_FB_BLANK_SCREEN        = 0x00040002,
    MBOX_TAG_FB_GET_PHYS_WH         = 0x00040003,
    MBOX_TAG_FB_TEST_PHYS_WH        = 0x00044003,
    MBOX_TAG_FB_SET_PHYS_WH         = 0x00048003,
    MBOX_TAG_FB_GET_VIRT_WH         = 0x00040004,
    MBOX_TAG_FB_TEST_VIRT_WH        = 0x00044004,
    MBOX_TAG_FB_SET_VIRT_WH         = 0x00048004,
    MBOX_TAG_FB_GET_DEPTH           = 0x00040005,
    MBOX_TAG_FB_TEST_DEPTH          = 0x00044005,
    MBOX_TAG_FB_SET_DEPTH           = 0x00048005,
    MBOX_TAG_FB_GET_PIXEL_ORDER     = 0x00040006,
    MBOX_TAG_FB_TEST_PIXEL_ORDER    = 0x00044006,
    MBOX_TAG_FB_SET_PIXEL_ORDER     = 0x00048006,
    MBOX_TAG_FB_GET_ALPHA_MODE      = 0x00040007,
    MBOX_TAG_FB_TEST_ALPHA_MODE     = 0x00044007,
    MBOX_TAG_FB_SET_ALPHA_MODE      = 0x00048007,
    MBOX_TAG_FB_GET_PITCH           = 0x00040008,
    MBOX_TAG_FB_GET_VIRT_OFFSET     = 0x00040009,
    MBOX_TAG_FB_TEST_VIRT_OFFSET    = 0x00044009,
    MBOX_TAG_FB_SET_VIRT_OFFSET     = 0x00048009,
    MBOX_TAG_FB_GET_OVERSCAN        = 0x0004000a,
    MBOX_TAG_FB_TEST_OVERSCAN       = 0x0004400a,
    MBOX_TAG_FB_SET_OVERSCAN        = 0x0004800a,
    MBOX_TAG_FB_GET_PALETTE         = 0x0004000b,
    MBOX_TAG_FB_TEST_PALETTE        = 0x0004400b,
    MBOX_TAG_FB_SET_PALETTE         = 0x0004800b,
};

struct mbox_fb_gpiovirt_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t val;
    } tag;
    u32_t end;
};

struct mbox_fb_pitch_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t val;
    } tag;
    u32_t end;
};

struct mbox_fb_alpha_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t val;
    } tag;
    u32_t end;
};

struct mbox_fb_info_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t width;
        u32_t height;
    } phys;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t width;
        u32_t height;
    } virt;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t bpp;
    } depth;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t xoffset;
        u32_t yoffset;
    } offset;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t vaddr;
        u32_t vsize;
    } allocate;
    u32_t end;
};

struct mbox_fb_offset_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t xoffset;
        u32_t yoffset;
    } tag;
    u32_t end;
};

struct mbox_fb_porder_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t order;
    } tag;
    u32_t end;
};

u32_t bcm283x_mbox_fb_get_gpiovirt(void)
{
    struct mbox_fb_gpiovirt_msg_t msg __attribute__((aligned(16)));
    struct mbox_fb_gpiovirt_msg_t * p = &msg;

    p->size = sizeof(struct mbox_fb_gpiovirt_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_FB_GET_GPIOVIRT;
    p->tag.size = 4;
    p->tag.len = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm283x_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    return p->tag.val & 0x3fffffff;
}

u32_t bcm283x_mbox_fb_get_pitch(void)
{
    struct mbox_fb_pitch_msg_t msg __attribute__((aligned(16)));
    struct mbox_fb_pitch_msg_t * p = &msg;

    p->size = sizeof(struct mbox_fb_pitch_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_FB_GET_PITCH;
    p->tag.size = 4;
    p->tag.len = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm283x_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    return p->tag.val;
}

bool bcm283x_mbox_fb_set_porder(int rgb)
{
    struct mbox_fb_porder_msg_t msg __attribute__((aligned(16)));
    struct mbox_fb_porder_msg_t * p = &msg;

    p->size = sizeof(struct mbox_fb_porder_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_FB_SET_PIXEL_ORDER;
    p->tag.size = 4;
    p->tag.len = 4;
    p->tag.order = rgb;
    p->end = 0;

    bcm283x_mbox_call(p);
    if(p->code != 0x80000000)
        return false;
    return true;
}

void *bcm283x_mbox_fb_alloc(int width, int height, int bpp, int nrender)
{
    struct mbox_fb_info_msg_t msg __attribute__((aligned(16)));
    struct mbox_fb_info_msg_t * p = &msg;

    p->size = sizeof(struct mbox_fb_info_msg_t);
    p->code = 0;
    p->phys.tag = MBOX_TAG_FB_SET_PHYS_WH;
    p->phys.size = 8;
    p->phys.len = 8;
    p->phys.width = width;
    p->phys.height = height;
    p->virt.tag = MBOX_TAG_FB_SET_VIRT_WH;
    p->virt.size = 8;
    p->virt.len = 8;
    p->virt.width = width;
    p->virt.height = height * nrender;
    p->depth.tag = MBOX_TAG_FB_SET_DEPTH;
    p->depth.size = 4;
    p->depth.len = 4;
    p->depth.bpp = bpp;
    p->allocate.tag = MBOX_TAG_FB_ALLOCATE_BUFFER;
    p->allocate.size = 8;
    p->allocate.len = 4;
    p->allocate.vaddr = 0x3C100000; // The design of MBOX driver forces us to give the virtual address
    p->allocate.vsize = 0;
    p->end = 0;

    bcm283x_mbox_call(p);
    if(p->code != 0x80000000)
        return NULL;
    return (void *)((u64_t)(p->allocate.vaddr & 0x3fffffff));
}

bool bcm283x_mbox_fb_setoffset(int xoffset, int yoffset)
{
    struct mbox_fb_offset_msg_t msg __attribute__((aligned(16)));
    struct mbox_fb_offset_msg_t * p = &msg;

    p->size = sizeof(struct mbox_fb_offset_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_FB_SET_VIRT_OFFSET;
    p->tag.size = 8;
    p->tag.len = 8;
    p->tag.xoffset = xoffset;
    p->tag.yoffset = yoffset;
    p->end = 0;

    bcm283x_mbox_call(p);
    if(p->code != 0x80000000)
        return false;
    return true;
}


bool bcm283x_mbox_fb_setalpha(int alpha)
{
    struct mbox_fb_alpha_msg_t msg __attribute__((aligned(16)));
    struct mbox_fb_alpha_msg_t *p = &msg;

    p->size = sizeof(struct mbox_fb_alpha_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_FB_SET_VIRT_OFFSET;
    p->tag.size = 4;
    p->tag.len = 4;
    p->tag.val = alpha;
    p->end = 0;

    bcm283x_mbox_call(p);
    if(p->code != 0x80000000)
        return false;
    return true;
}
