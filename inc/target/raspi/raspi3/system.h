#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include <stdarg.h>
#include "kernel/def/keyword.h"
#include "target/raspi/shared/bcm283X/datastructure.h"

#define ARM_MODE_USR 0x10   /* Normal User Mode                                       */
#define ARM_MODE_FIQ 0x11   /* FIQ Processing Fast Interrupts Mode                    */
#define ARM_MODE_IRQ 0x12   /* IRQ Processing Standard Interrupts Mode                */
#define ARM_MODE_SVC 0x13   /* Supervisor Processing Software Interrupts Mode         */
#define ARM_MODE_ABT 0x17   /* Abort Processing memory Faults Mode                    */
#define ARM_MODE_UND 0x1B   /* Undefined Processing Undefined Instructions Mode       */
#define ARM_MODE_SYS 0x1F   /* System Running Priviledged Operating System Tasks Mode */

#define GPIO ((volatile __aligned(4) struct GPIORegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0x200000))
#define SYSTEMTIMER ((volatile __aligned(4) struct SystemTimerRegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0x3000))
#define IRQ ((volatile __aligned(4) struct IrqControlRegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0xB200))
#define ARMTIMER ((volatile __aligned(4) struct ArmTimerRegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0xB400))
#define MAILBOX ((volatile __aligned(4) struct MailBoxRegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0xB880))
#define MINIUART ((volatile struct MiniUARTRegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0x00215040))
#define PL011UART ((volatile struct PL011UARTRegisters *)(uintptr_t)(ARCH_RASP_MMIOBASE + 0x00201000))
#define QA7 ((volatile __aligned(4) struct QA7Registers *)(uintptr_t)(0x40000024))

void helloFromLightBeam(void);
void setup_level(void);

u64_t timer_getTickCount64(void);
void timer_wait(u64_t);
void system_charging(u32_t);

/* Classical kernel PANIC */
void PANIC(char const *, ...);

#endif