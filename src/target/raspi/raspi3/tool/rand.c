#include "target/raspi/raspi3/rand.h"

#define RNG_CTRL        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00104000))
#define RNG_STATUS      ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00104004))
#define RNG_DATA        ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00104008))
#define RNG_INT_MASK    ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00104010))

/**
 * Initialize the RNG
 */
void rand_init()
{
    *RNG_STATUS = 0x40000;
    // mask interrupt
    *RNG_INT_MASK |= 1;
    // enable
    *RNG_CTRL |= 1;
    // wait for gaining some entropy
    while(!((*RNG_STATUS) >> 24));
}

/**
 * Return a random number between [min..max]
 */
u32_t rand(u32_t min, u32_t max)
{
    return (*RNG_DATA % (max - min) + min);
}