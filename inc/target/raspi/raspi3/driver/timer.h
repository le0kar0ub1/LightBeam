#ifndef __TIMER_H_
#define __TIMER_H_

#include <stdbool.h>
#include "def/typedef.h"
#include "target/raspi/raspi3/cpus/cpus.h"

#define MS_TO_US(x) (x * 1000)
#define S_TO_US(x)  (x * 1000000)

#define TIMER_CS   (ARCH_RASP_MMIOBASE + 0x00003000)
#define TIMER_CLO  (ARCH_RASP_MMIOBASE + 0x00003004)
#define TIMER_CHI  (ARCH_RASP_MMIOBASE + 0x00003008)
#define TIMER_C0   (ARCH_RASP_MMIOBASE + 0x0000300C)
#define TIMER_C1   (ARCH_RASP_MMIOBASE + 0x00003010)
#define TIMER_C2   (ARCH_RASP_MMIOBASE + 0x00003014)
#define TIMER_C3   (ARCH_RASP_MMIOBASE + 0x00003018)

#define TIMER_CS_M0 (1 << 0)
#define TIMER_CS_M1 (1 << 1)
#define TIMER_CS_M2 (1 << 2)
#define TIMER_CS_M3 (1 << 3)

bool timerIrqSetup(uint32);
uintptr TimerFiqSetup(uint32, void(*)(void));

void LocalTimerSetup(uint32);
void LocalTimerIrqSetup(uint32, enum CPUS_ID);


#endif