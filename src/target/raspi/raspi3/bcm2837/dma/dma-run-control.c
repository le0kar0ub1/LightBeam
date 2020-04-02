#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaEngineRegister_t *dmaEngineRegs[];

void bcm2837_dma_active_transfer(u8_t engine)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaEngineRegs[engine]->ctrlStatus.active = true;
}

void bcm2837_dma_interrupt_handler(void);
void bcm2837_dma_interrupt_handler(void)
{

}

void bcm2837_dma_abort_transfer(u8_t engine)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaEngineRegs[engine]->ctrlStatus.abort = true;
}

void bcm2837_dma_reset_transfer(u8_t engine)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaEngineRegs[engine]->ctrlStatus.abort = true;
}