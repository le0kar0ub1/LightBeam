#ifndef __X86_H_
#define __X86_H_

#include "lightbeam.h"

#include "target/x86/common/asminline.h"
#include "target/x86/common/atomic.h"
#include "target/x86/common/cpus/cpuid.h"

#include "target/x86/common/schedule/spinlock.h"

#include "target/x86/common/interrupts/interrupts.h"

#include "target/x86/common/drivers/serial.h"
#include "target/x86/common/drivers/vga.h"

void PANIC(char const *, ...);

#endif