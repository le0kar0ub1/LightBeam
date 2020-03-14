#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/mbox.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "def/keyword.h"

volatile uint __aligned(16) mbox[36];

#define VIDEOCORE_MBOX  (ARCH_RASP_MMIOBASE + 0x0000B880)
#define MBOX_READ       ((volatile uint *)(VIDEOCORE_MBOX + 0x0))
#define MBOX_POLL       ((volatile uint *)(VIDEOCORE_MBOX + 0x10))
#define MBOX_SENDER     ((volatile uint *)(VIDEOCORE_MBOX + 0x14))
#define MBOX_STATUS     ((volatile uint *)(VIDEOCORE_MBOX + 0x18))
#define MBOX_CONFIG     ((volatile uint *)(VIDEOCORE_MBOX + 0x1C))
#define MBOX_WRITE      ((volatile uint *)(VIDEOCORE_MBOX + 0x20))
#define MBOX_RESPONSE   0x80000000
#define MBOX_FULL       0x80000000
#define MBOX_EMPTY      0x40000000

smplock_t lock;

int mbox_call(uchar ch)
{
    semaphore_inc(&lock);
    uint r = (((uint)((ulong) & mbox) & ~0xF) | (ch & 0xF));

    while (*MBOX_STATUS & MBOX_FULL)
        asm volatile("nop");
    *MBOX_WRITE = r;
    while (1) {
        while (*MBOX_STATUS & MBOX_EMPTY)
            asm volatile("nop");
        if (r == *MBOX_READ) {
            semaphore_dec(&lock);
            return (mbox[1] == MBOX_RESPONSE);
        }
    }
    semaphore_dec(&lock);
    return (0);
}