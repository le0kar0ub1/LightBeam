#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "kernel/io.h"
#include "def/typedef.h"

enum {
    MBOX_CH_POWER_MANAGEMENT    = 0,
    MBOX_CH_FRAMEBUFFER         = 1,
    MBOX_CH_VIRTUAL_UART        = 2,
    MBOX_CH_VCHIQ               = 3,
    MBOX_CH_LEDS                = 4,
    MBOX_CH_BUTTONS             = 5,
    MBOX_CH_TOUCHSCREEN         = 6,
    MBOX_CH_UNUSED              = 7,
    MBOX_CH_TAGS_ARM_TO_VC      = 8,
    MBOX_CH_TAGS_VC_TO_ARM      = 9,
};

static void bcm2837_mbox_write(int channel, u32_t data)
{
    virtaddr_t virt = (virtaddr_t)BCM2837_MBOX_BASE;

    while((read32((virtaddr_t)((u64_t)virt + MBOX_STATUS)) & (1 << 31)) != 0);
    write32((virtaddr_t)((u64_t)virt + MBOX_WRITE), (data & ~0xf) | (channel & 0xf));
}

static u32_t bcm2837_mbox_read(int channel)
{
    virtaddr_t virt = (virtaddr_t)BCM2837_MBOX_BASE;
    u32_t data;

    do {
        while((read32((virtaddr_t)((u64_t)virt + MBOX_STATUS)) & (1 << 30)) != 0);
        data = read32((virtaddr_t)((u64_t)virt + MBOX_READ));
    } while ((data & 0xf) != (u32_t)channel);

    return (data & ~0xf);
}

static void bcm2837_mbox_call(void * msg)
{
    u32_t data = 0xC0000000 + (u64_t)msg;

    bcm2837_mbox_write(MBOX_CH_TAGS_ARM_TO_VC, data);
    bcm2837_mbox_read(MBOX_CH_TAGS_ARM_TO_VC);
}

/*
 * Mbox videocore
 */
enum {
    MBOX_TAG_VC_GET_FIRMWARE_REV    = 0x00000001,
};

struct mbox_vc_msg_t {
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

int bcm2837_mbox_vc_get_firmware_revison(void)
{
    struct mbox_vc_msg_t msg __attribute__((aligned(16)));
    struct mbox_vc_msg_t * p = &msg;

    p->size = sizeof(struct mbox_vc_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_VC_GET_FIRMWARE_REV;
    p->tag.size = 4;
    p->tag.len = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    return p->tag.val;
}

/*
 * Mbox hardware
 */
enum {
    MBOX_TAG_HARDWARE_GET_MODEL         = 0x00010001,
    MBOX_TAG_HARDWARE_GET_REV           = 0x00010002,
    MBOX_TAG_HARDWARE_GET_MAC_ADDRESS   = 0x00010003,
    MBOX_TAG_HARDWARE_GET_SERIAL        = 0x00010004,
    MBOX_TAG_HARDWARE_GET_ARM_MEMORY    = 0x00010005,
    MBOX_TAG_HARDWARE_GET_VC_MEMORY     = 0x00010006,
    MBOX_TAG_HARDWARE_GET_CLOCKS        = 0x00010007,
};

struct mbox_hardware_msg_t {
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

struct mbox_hardware_mac_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        uint8_t val[6];
    } tag;
    u32_t end;
};

struct mbox_hardware_serial_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u64_t val;
    } tag;
    u32_t end;
};

struct mbox_hardware_memory_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t mbase;
        u32_t msize;
    } tag;
    u32_t end;
};

int bcm2837_mbox_hardware_get_model(void)
{
    struct mbox_hardware_msg_t msg __attribute__((aligned(16)));
    struct mbox_hardware_msg_t * p = &msg;

    p->size = sizeof(struct mbox_hardware_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_HARDWARE_GET_MODEL;
    p->tag.size = 4;
    p->tag.len = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_hardware_get_revison(void)
{
    struct mbox_hardware_msg_t msg __attribute__((aligned(16)));
    struct mbox_hardware_msg_t * p = &msg;

    p->size = sizeof(struct mbox_hardware_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_HARDWARE_GET_REV;
    p->tag.size = 4;
    p->tag.len = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_hardware_get_mac_address(uint8_t * mac)
{
    struct mbox_hardware_mac_msg_t msg __attribute__((aligned(16)));
    struct mbox_hardware_mac_msg_t * p = &msg;

    p->size = sizeof(struct mbox_hardware_mac_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_HARDWARE_GET_MAC_ADDRESS;
    p->tag.size = 6;
    p->tag.len = 0;
    p->tag.val[0] = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    mac[0] = p->tag.val[0];
    mac[1] = p->tag.val[1];
    mac[2] = p->tag.val[2];
    mac[3] = p->tag.val[3];
    mac[4] = p->tag.val[4];
    mac[5] = p->tag.val[5];
    return 0;
}

int bcm2837_mbox_hardware_get_serial(u64_t * sn)
{
    struct mbox_hardware_serial_msg_t msg __attribute__((aligned(16)));
    struct mbox_hardware_serial_msg_t * p = &msg;

    p->size = sizeof(struct mbox_hardware_serial_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_HARDWARE_GET_SERIAL;
    p->tag.size = 8;
    p->tag.len = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    *sn = p->tag.val;
    return 0;
}

int bcm2837_mbox_hardware_get_arm_memory(u32_t * base, u32_t * size)
{
    struct mbox_hardware_memory_msg_t msg __attribute__((aligned(16)));
    struct mbox_hardware_memory_msg_t * p = &msg;

    p->size = sizeof(struct mbox_hardware_memory_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_HARDWARE_GET_ARM_MEMORY;
    p->tag.size = 8;
    p->tag.len = 0;
    p->tag.mbase = 0;
    p->tag.msize = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    *base = p->tag.mbase;
    *size = p->tag.msize;
    return 0;
}

int bcm2837_mbox_hardware_get_vc_memory(u32_t * base, u32_t * size)
{
    struct mbox_hardware_memory_msg_t msg __attribute__((aligned(16)));
    struct mbox_hardware_memory_msg_t * p = &msg;

    p->size = sizeof(struct mbox_hardware_memory_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_HARDWARE_GET_VC_MEMORY;
    p->tag.size = 8;
    p->tag.len = 0;
    p->tag.mbase = 0;
    p->tag.msize = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    *base = p->tag.mbase;
    *size = p->tag.msize;
    return 0;
}

/*
 * Mbox clock
 */
enum {
    MBOX_TAG_CLOCK_GET_TURBO    = 0x00030009,
    MBOX_TAG_CLOCK_SET_TURBO    = 0x00038009,
    MBOX_TAG_CLOCK_GET_STATE    = 0x00030001,
    MBOX_TAG_CLOCK_SET_STATE    = 0x00038001,
    MBOX_TAG_CLOCK_GET_RATE     = 0x00030002,
    MBOX_TAG_CLOCK_SET_RATE     = 0x00038002,
    MBOX_TAG_CLOCK_GET_MAX_RATE = 0x00030004,
    MBOX_TAG_CLOCK_GET_MIN_RATE = 0x00030007,
};

struct mbox_clock_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t id;
        u32_t val;
    } tag;
    u32_t end;
};

int bcm2837_mbox_clock_get_turbo(void)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_GET_TURBO;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)0)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_clock_set_turbo(int level)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_SET_TURBO;
    p->tag.size = 8;
    p->tag.len = 8;
    p->tag.id = 0;
    p->tag.val = level ? 1 : 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)0)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_clock_get_state(int id)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_GET_STATE;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = id;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return (p->tag.val & 0x3);
}

int bcm2837_mbox_clock_set_state(int id, int state)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_SET_STATE;
    p->tag.size = 8;
    p->tag.len = 8;
    p->tag.id = id;
    p->tag.val = state & 0x3;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return (p->tag.val & 0x3);
}

int bcm2837_mbox_clock_get_rate(int id)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_GET_RATE;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = id;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_clock_set_rate(int id, int rate)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_SET_RATE;
    p->tag.size = 8;
    p->tag.len = 8;
    p->tag.id = id;
    p->tag.val = rate;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_clock_get_max_rate(int id)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_GET_MAX_RATE;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = id;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_clock_get_min_rate(int id)
{
    struct mbox_clock_msg_t msg __attribute__((aligned(16)));
    struct mbox_clock_msg_t * p = &msg;

    p->size = sizeof(struct mbox_clock_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_CLOCK_GET_MIN_RATE;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = id;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return p->tag.val;
}

/*
 * Mbox power
 */
enum {
    MBOX_TAG_POWER_GET_STATE    = 0x00020001,
    MBOX_TAG_POWER_SET_STATE    = 0x00028001,
};

struct mbox_power_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t id;
        u32_t val;
    } tag;
    u32_t end;
};

int bcm2837_mbox_power_get_state(int id)
{
    struct mbox_power_msg_t msg __attribute__((aligned(16)));
    struct mbox_power_msg_t * p = &msg;

    p->size = sizeof(struct mbox_power_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_POWER_GET_STATE;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = id;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return (p->tag.val & 0x3);
}

int bcm2837_mbox_power_set_state(int id, int state)
{
    struct mbox_power_msg_t msg __attribute__((aligned(16)));
    struct mbox_power_msg_t * p = &msg;

    p->size = sizeof(struct mbox_power_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_POWER_SET_STATE;
    p->tag.size = 8;
    p->tag.len = 8;
    p->tag.id = id;
    p->tag.val = state & 0x3;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)id)
        return -1;
    return (p->tag.val & 0x3);
}

/*
 * Mbox temperature
 */
enum {
    MBOX_TAG_TEMP_GET       = 0x00030006,
    MBOX_TAG_TEMP_GET_MAX   = 0x0003000A,
};

struct mbox_temp_msg_t {
    u32_t size;
    u32_t code;
    struct {
        u32_t tag;
        u32_t size;
        u32_t len;
        u32_t id;
        u32_t val;
    } tag;
    u32_t end;
};

int bcm2837_mbox_temp_get(void)
{
    struct mbox_temp_msg_t msg __attribute__((aligned(16)));
    struct mbox_temp_msg_t * p = &msg;

    p->size = sizeof(struct mbox_temp_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_TEMP_GET;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)0)
        return -1;
    return p->tag.val;
}

int bcm2837_mbox_temp_get_max(void)
{
    struct mbox_temp_msg_t msg __attribute__((aligned(16)));
    struct mbox_temp_msg_t * p = &msg;

    p->size = sizeof(struct mbox_temp_msg_t);
    p->code = 0;
    p->tag.tag = MBOX_TAG_TEMP_GET_MAX;
    p->tag.size = 8;
    p->tag.len = 4;
    p->tag.id = 0;
    p->tag.val = 0;
    p->end = 0;

    bcm2837_mbox_call(p);
    if(p->code != 0x80000000)
        return -1;
    if(p->tag.id != (uint)0)
        return -1;
    return p->tag.val;
}