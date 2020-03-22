#ifndef __GPIO_H_
#define __GPIO_H_

#include "def/typedef.h"

#define GPFSEL0         ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200000))
#define GPFSEL1         ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200004))
#define GPFSEL2         ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200008))
#define GPFSEL3         ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x0020000C))
#define GPFSEL4         ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200010))
#define GPFSEL5         ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200014))
#define GPSET0          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x0020001C))
#define GPSET1          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200020))
#define GPCLR0          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200028))
#define GPLEV0          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200034))
#define GPLEV1          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200038))
#define GPEDS0          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200040))
#define GPEDS1          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200044))
#define GPHEN0          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200064))
#define GPHEN1          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200068))
#define GPPUD0          ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200094))
#define GPPUDCLK0       ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x00200098))
#define GPPUDCLK1       ((volatile uint *)(ARCH_RASP_MMIOBASE + 0x0020009C))

#endif