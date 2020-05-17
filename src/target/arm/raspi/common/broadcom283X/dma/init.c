#include "lightbeam.h"
#include "target/arm/raspi/common/bcm283X/dma.h"
#include "kernel/init/initcalls.h"

volatile struct dma_intStatus_t *dmaIntStatus = NULL;
volatile struct dma_enable_t    *dmaEnableReg = NULL;

volatile struct dmaEngineRegister_t *dmaEngineRegs[BCM283x_DMA_CTRLBLCK_NUMBR] = {NULL};

static void bcm283x_dma_init(void)
{
    for (u8_t i = 0x0; i < BCM283x_DMA_CTRLBLCK_NUMBR; i++)
        dmaEngineRegs[i] = ADD_TO_PTR(BCM283x_DMA_ENTRY, i * BCM283x_DMA_CTRLBLCK_PITCH);
    dmaIntStatus = (struct dma_intStatus_t *)BCM283x_DMA_INTSTATUSREG;
    dmaEnableReg = (struct dma_enable_t *)BCM283x_DMA_ENABLEREG;
    /* Disable all DMA engines */
    memset((void *)dmaEnableReg, 0x0, sizeof(struct dma_enable_t));
}

core_initcall(bcm283x_dma_init);