#include "def/typedef.h"
#include "target/raspi/raspi1/proto.h"

uint32 mmioRead(uint32 base, uint32 reg)
{
    membarrier();
    return *(volatile uint32 *)(ARCH_RASP_MMIOBASE + base + reg);
}

void mmioWrite(uint32 base, uint32 reg, uint32 value)
{
    membarrier();
    *(volatile uint32 *)(ARCH_RASP_MMIOBASE + base + reg) = value;
    membarrier();
}