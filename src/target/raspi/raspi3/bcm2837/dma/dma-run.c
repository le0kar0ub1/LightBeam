#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaControlBlock_t *dmaCtrlBlk[BCM2837_DMA_CTRLBLCK_NUMBR];

#pragma message "write my driver :)"

void bcm2837_dma_interrupt_handler(void);
void bcm2837_dma_interrupt_handler(void)
{

}

static void bcm2837_dma_start_transfer(void)
{

}

bool bcm2837_dma_run_transfer(void *, void *, size_t);
bool bcm2837_dma_run_transfer(void *src __unused, void *dest __unused, size_t sz __unused)
{
    if (!IS_ALIGN(src, BCM2837_DMA_ADDRALIGN))
        return (false);
    return (true);
}