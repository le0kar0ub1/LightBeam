#include "target/raspi/raspi3/driver/lfb.h"
#include "target/raspi/raspi3/memory/mmu.h"

extern uint64 __KEND;

void mmu_init(void)
{
    uint64 ENDPOINT = (uint64)&__KEND;

    uint64 *paging = (uint64 *)ENDPOINT;
    uint64 kmap = ENDPOINT / PAGESIZE;

    paging[0] = ENDPOINT + (2 * PAGESIZE);
    while (1);
}