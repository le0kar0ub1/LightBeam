#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"
#include "kernel/init/initcalls.h"

struct dma_intStatus_t *dmaIntStatus = NULL;
struct dma_enable_t    *dmaEnable    = NULL;

struct dmaControlBlock_t *dmaCtrlBlk[BCM2837_DMA_CTRLBLCK_NUMBR] = {NULL};

static void bcm2837_dma_init(void)
{
    for (u8_t i = 0x0; i < BCM2837_DMA_CTRLBLCK_NUMBR; i++)
        dmaCtrlBlk[i] = ADD_TO_PTR(BCM2837_DMA_ENTRY, i * BCM2837_DMA_CTRLBLCK_PITCH);
    dmaIntStatus = (struct dma_intStatus_t *)BCM2837_DMA_INTSTATUSREG;
    dmaEnable    = (struct dma_enable_t *)BCM2837_DMA_ENABLEREG;
}

core_initcall(bcm2837_dma_init);