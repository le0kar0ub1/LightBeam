#ifndef __ASMINLINE_H_
#define __ASMINLINE_H_

#include "lightbeam.h"

enum msr_id
{
    MSR_APIC_BASE       = 0x1B,
};

enum port
{
    PORT_PIC_MASTER_CMD      = 0x20,
    PORT_PIC_MASTER_DATA     = 0x21,
    PORT_IMCR_ADDRESS        = 0x22,
    PORT_IMCR_DATA           = 0x23,

    /* PIT PUCE */
    PORT_PIT0_IO             = 0x40,
    PORT_PIT1_IO             = 0x41,
    PORT_PIT2_IO             = 0x42,
    PORT_PIT_CMD_WRONLY      = 0x43,
    PORT_PIT2_HP             = 0x61,

    /* KEYBOARD PORT (also PS2 port) */
    PORT_PS2_KEYBOARD_DATA   = 0x60,
    PORT_PS2_KEYBOARD_CMD    = 0x60,
    PORT_PS2_KEYBOARD_STATUS = 0x64,

    PORT_CMOS                = 0x70,
    PORT_CMOS_DATA           = 0x71,
    PORT_PIC_SLAVE_CMD       = 0xA0,
    PORT_PIC_SLAVE_DATA      = 0xA1,
};

static inline void invlpg(void *p)
{
    asm volatile("invlpg (%0)" : : "r"(p) : "memory");
}

static inline uintptr get_cr2(void)
{
    uintptr out;
    asm volatile("mov %%cr2, %0" : "=a"(out));
    return (out);
}

static inline uintptr get_cr3(void)
{
    uintptr out;
    asm volatile("mov %%cr3, %0" : "=a"(out));
    return (out);
}

static inline void set_cr3(uintptr cr3)
{
    asm volatile("mov %0, %%cr3" :: "r"(cr3));
}


static inline uint64 rdtsc(void)
{
    uint64 ret;
    asm volatile("rdtsc" : "=A"(ret));
    return (ret);
}

static inline void cpuid(uint32 id, uint32 *eax, uint32 *edx)
{
    asm volatile("cpuid" : "=a"(*eax), "=d"(*edx) : "a"(id) : "ebx", "ecx");
}

/* wait an interrupt */
static inline void hlt(void)
{
    asm volatile("hlt");
}

/* pushfq/popfq instruction*/
static inline void pushfq(void)
{
    asm volatile("pushfq");
}

static inline void popfq(void)
{
    asm volatile("popfq");
}

/* enable interruption */
static inline void sti(void)
{
    asm volatile("sti");
}

/* disable interruption */
static inline void cli(void)
{
    asm volatile("cli");
}

/* enable direction flag */
static inline void std(void)
{
    asm volatile("std");
}

/* disable direction flag */
static inline void cld(void)
{
    asm volatile("cld");
}


/* force a thread to sleep */
static inline void pause(void)
{
    asm volatile("pause");
}

/* fire an interrupt */
static inline void interrupt(uchar vector)
{
    asm volatile("int %0" :: "i"(vector));
}

static inline uint xchg(uint volatile *addr, uint newval)
{
    uint res;

    asm volatile("lock xchgl %0, %1;" : "+m"(*addr), "=a"(res) : "1"(newval) : "cc");
    return (res);
}

#if ARCH_DIMENSION == 32
    static inline uint64 read_rflags(void)
    {
        return (__builtin_ia32_readeflags_u32());
    }

    static inline void write_rflags(uint64 rflags)
    {
        __builtin_ia32_writeeflags_u32(rflags);
    }
#elif ARCH_DIMENSION == 64
    static inline uint64 read_rflags(void)
    {
        return (__builtin_ia32_readeflags_u64());
    }

    static inline void write_rflags(uint64 rflags)
    {
        __builtin_ia32_writeeflags_u64(rflags);
    }
#endif

static inline uint64 get_rflags(void)
{
    uint64 e;

    asm volatile("pushfq; pop %0" : "=rm"(e) :: "memory");
    return (e);
}

static inline void set_rflags(uint64 value)
{
    asm volatile("push %0; popfq" :: "g"(value) : "memory", "cc");
}


static inline void preempt_inc(void)
{
    asm volatile("lock incl %%gs:0x18" :: );
}

static inline void preempt_dec(void)
{
    asm volatile("lock decl %%gs:0x18" :: );
}

/* read port (byte) */
static inline uchar inb(ushort port)
{
    uchar ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
    return (ret);
}

/* read port (word) */
static inline ushort inw(ushort port)
{
    ushort ret;
    asm volatile("inw %1, %0" : "=a"(ret) : "d"(port));
    return (ret);
}

/* read port (double) */
static inline uint ind(ushort port)
{
    uint ret;
    asm volatile("inl %1, %0" : "=a"(ret) : "d"(port));
    return (ret);
}

/* write port (byte) */
static inline void outb(ushort port, uchar data)
{
    asm volatile("outb %0, %1" :: "a"(data), "d"(port));
}

/* write port (word) */
static inline void outw(ushort port, ushort data)
{
    asm volatile("outw %0, %1" :: "a"(data), "d"(port));
}

/* write port (double) */
static inline void outd(ushort port, uint data)
{
    asm volatile("outl %0, %1" :: "a"(data), "d"(port));
}

static inline void io_delay(void)
{
    asm volatile("outb %%al, $0x80" : : "a"(0));
}

#endif