#ifndef __X86_H_
#define __X86_H_

#include "lightbeam.h"

#define ARCH_x86_64 64
#define ARCH_i386   32

#include "arch/x86/asminline.h"
#include "arch/x86/atomic.h"
#include "arch/x86/spinlock.h"

#include "target/x86/common/cpus/cpuid.h"

#include "target/x86/common/interrupts/interrupts.h"

#include "target/x86/common/drivers/serial.h"
#include "target/x86/common/drivers/vga.h"

extern uintptr __KERNEL_ADDR_TRNS;
extern uintptr __KERNEL_PHYS_LINK;
extern uintptr __KERNEL_VIRT_LINK;
extern uintptr __KERNEL_PHYS_END;
extern uintptr __KERNEL_VIRT_END;

void PANIC(char const *, ...) __noreturn;

#endif