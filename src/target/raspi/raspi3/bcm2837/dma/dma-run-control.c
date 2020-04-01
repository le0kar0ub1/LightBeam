#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaControlBlock_t *dmaCtrlBlk[BCM2837_DMA_CTRLBLCK_NUMBR];

void bcm2837_dma_active_transfer(u8_t engine)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaCtrlBlk[engine]->ctrlStatus.active = true;
}

void bcm2837_dma_interrupt_handler(void);
void bcm2837_dma_interrupt_handler(void)
{

}

void bcm2837_dma_set_address_inc(u8_t engine, bool val)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaCtrlBlk[engine]->transferInformation.destInc = val;
    dmaCtrlBlk[engine]->transferInformation.srcInc  = val;
}

void bcm2837_dma_set_source_address(u8_t engine, void *src)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaCtrlBlk[engine]->sourceAddr.addr = (u32_t)(u64_t)src;
}

void bcm2837_dma_set_destination_address(u8_t engine, void *dest)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaCtrlBlk[engine]->destinationAddr.addr = (u32_t)(u64_t)dest;
}

void bcm2837_dma_set_transfer_size(u8_t engine, u16_t sz)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaCtrlBlk[engine]->transactionLenght.xlenght = sz;
    dmaCtrlBlk[engine]->transactionLenght.ylenght = 0x1;
}

void bcm2837_dma_2Dmode_set_transfer_size(u8_t engine, u16_t xsz, u16_t ysz)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    dmaCtrlBlk[engine]->transactionLenght.xlenght = xsz;
    dmaCtrlBlk[engine]->transactionLenght.ylenght = ysz;
}