#include "def/keyword.h"
#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/driver/mbox.h"
#include "target/raspi/raspi3/cpus/cpus.h"
#include "target/raspi/raspi3/datastructure.h"
#include "target/raspi/raspi3/system.h"
#include "target/raspi/raspi3/memory/mmu.h"

volatile u32_t mbox[36] __aligned(16);

#define VIDEOCORE_MBOX  (ARCH_RASP_MMIOBASE + 0x0000B880)
#define MBOX_READ       ((volatile u32_t *)(VIDEOCORE_MBOX + 0x0))
#define MBOX_POLL       ((volatile u32_t *)(VIDEOCORE_MBOX + 0x10))
#define MBOX_SENDER     ((volatile u32_t *)(VIDEOCORE_MBOX + 0x14))
#define MBOX_STATUS     ((volatile u32_t *)(VIDEOCORE_MBOX + 0x18))
#define MBOX_CONFIG     ((volatile u32_t *)(VIDEOCORE_MBOX + 0x1C))
#define MBOX_WRITE      ((volatile u32_t *)(VIDEOCORE_MBOX + 0x20))
#define MBOX_FULL       0x80000000
#define MBOX_EMPTY      0x40000000

smplock_t lock;

int mbox_call(uchar ch)
{
    semaphore_inc(&lock);
    u32_t r = (((u32_t)((ulong) & mbox) & ~0xF) | (ch & 0xF));

    while (*MBOX_STATUS & MBOX_FULL);
    *MBOX_WRITE = r;
    while (1) {
        while (*MBOX_STATUS & MBOX_EMPTY);
        if (r == *MBOX_READ) {
            semaphore_dec(&lock);
            return (mbox[1] == MBOX_FULL);
        }
    }
    semaphore_dec(&lock);
    return (0);
}

bool mailbox_write(MBOX_CHANNEL channel, u32_t message)
{
    semaphore_inc(&lock);
    if ((channel >= 0) && (channel <= MB_CHANNEL_GPU))
    {
        message &= ~(0xF);
        message |= channel;
        while ((MAILBOX->Status1 & MAIL_FULL) != 0);
        MAILBOX->Write1 = message;
        semaphore_dec(&lock);
        return (true);
    }
    semaphore_dec(&lock);
    return (false);
}

u32_t mailbox_read(MBOX_CHANNEL channel)
{
    if ((channel >= 0) && (channel <= MB_CHANNEL_GPU))
    {
        u32_t value;
        do {
            while ((MAILBOX->Status0 & MAIL_EMPTY) != 0);
            value = MAILBOX->Read0; 
        } while ((value & 0xF) != channel);
        value &= ~(0xF);
        return (value);
    }
    return (0xFEEDDEAD);
}

bool mailbox_tag_message(u32_t* response_buf,                   // Pointer to response buffer
                          u8_t data_count,                       // Number of u32_t variadic data following
                          ...)                                      // Variadic u32_t values for call
{
    u32_t message[data_count + 3] __aligned(16);
    u32_t addr = (u32_t)(uintptr_t)&message[0];
    __builtin_va_list list;
    __builtin_va_start(list, data_count);                                       // Start variadic argument
    message[0] = (data_count + 3) * 4;                              // Size of message needed
    message[data_count + 2] = 0;                                    // Set end pointer to zero
    message[1] = 0;                                                 // Zero response message
    for (int i = 0; i < data_count; i++)
        message[2 + i] = __builtin_va_arg(list, u32_t);                  // Fetch next variadic
    __builtin_va_end(list);                                                 // variadic cleanup 

    asm volatile("dc civac, %0" : : "r" (addr) : "memory");     // Ensure coherence

    mailbox_write(MB_CHANNEL_TAGS, ARMToGPU((mmuval_t)addr));         // Write message to mailbox
    mailbox_read(MB_CHANNEL_TAGS);                                  // Read the response

    asm volatile("dc civac, %0" : : "r" (addr) : "memory");     // Ensure coherence

    if (message[1] == MBOX_FULL) {                                 // Check success flag
        if (response_buf) {                                         // If buffer NULL used then don't want response
            for (int i = 0; i < data_count; i++)
                response_buf[i] = message[2 + i];                   // Transfer out each response message
        }
        return (true);                                                // message success
    }
    return (false);                                                   // Message failed
}