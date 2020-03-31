#ifndef __BCM2837_MBOX_H__
#define __BCM2837_MBOX_H__

#include <stdint.h>
#include "kernel/def/typedef.h"

#define BCM2837_MBOX_BASE   (0x3f00b880)

#define MBOX_READ           (0x00)
#define MBOX_STATUS         (0x18)
#define MBOX_CONFIG         (0x1c)
#define MBOX_WRITE          (0x20)

#define BCM2837_AUX_BASE    (0x3f215000)

#define AUX_IRQ             (0x00)
#define AUX_ENB             (0x04)

/* Mbox call */
void bcm2837_mbox_call(void *);

/* Mbox videocore */
int bcm2837_mbox_vc_get_firmware_revison(void);

/* Mbox hardware */
int bcm2837_mbox_hardware_get_model(void);
int bcm2837_mbox_hardware_get_revison(void);
int bcm2837_mbox_hardware_get_mac_address(u8_t *);
int bcm2837_mbox_hardware_get_serial(u64_t *);
int bcm2837_mbox_hardware_get_arm_memory(u32_t *, u32_t *);
int bcm2837_mbox_hardware_get_vc_memory(u32_t *, u32_t *);

/* Mbox clock */
enum {
    MBOX_CLOCK_ID_EMMC      = 1,
    MBOX_CLOCK_ID_UART      = 2,
    MBOX_CLOCK_ID_ARM       = 3,
    MBOX_CLOCK_ID_CORE      = 4,
    MBOX_CLOCK_ID_V3D       = 5,
    MBOX_CLOCK_ID_H264      = 6,
    MBOX_CLOCK_ID_ISP       = 7,
    MBOX_CLOCK_ID_SDRAM     = 8,
    MBOX_CLOCK_ID_PIXEL     = 9,
    MBOX_CLOCK_ID_PWM       = 10,
};

int bcm2837_mbox_clock_get_turbo(void);
int bcm2837_mbox_clock_set_turbo(int level);
int bcm2837_mbox_clock_get_state(int id);
int bcm2837_mbox_clock_set_state(int id, int state);
int bcm2837_mbox_clock_get_rate(int id);
int bcm2837_mbox_clock_set_rate(int id, int rate);
int bcm2837_mbox_clock_get_max_rate(int id);
int bcm2837_mbox_clock_get_min_rate(int id);

/* Mbox power */
enum {
    MBOX_POWER_ID_SDCARD    = 0,
    MBOX_POWER_ID_UART0     = 1,
    MBOX_POWER_ID_UART1     = 2,
    MBOX_POWER_ID_USBHCD    = 3,
    MBOX_POWER_ID_I2C0      = 4,
    MBOX_POWER_ID_I2C1      = 5,
    MBOX_POWER_ID_I2C2      = 6,
    MBOX_POWER_ID_SPI       = 7,
    MBOX_POWER_ID_CCP2TX    = 8,
};
int bcm2837_mbox_power_get_state(int id);
int bcm2837_mbox_power_set_state(int id, int state);

/* Mbox temperature */
int bcm2837_mbox_temp_get(void);
int bcm2837_mbox_temp_get_max(void);

/* Mbox framebuffer */
u32_t bcm2837_mbox_fb_get_gpiovirt(void);
void * bcm2837_mbox_fb_alloc(int, int, int, int);
bool bcm2837_mbox_fb_setoffset(int, int);
u32_t bcm2837_mbox_fb_get_pitch(void);
bool bcm2837_mbox_fb_set_porder(int);

#endif /* __BCM2837_MBOX_H__ */
