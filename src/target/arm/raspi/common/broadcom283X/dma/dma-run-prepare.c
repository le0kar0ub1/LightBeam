#include "lightbeam.h"
#include "target/arm/raspi/common/bcm283X/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaEngineRegister_t *dmaEngineRegs[];

void bcm283x_dma_set_next_ctrlblk(struct dmaControlBlock_t *ctrblk, void *addr)
{
    ctrblk->nextCtrlBlockAddr.addr = (u32_t)(archv_t)addr;
}

void bcm283x_dma_set_address_inc(struct dmaControlBlock_t *ctrblk, bool val)
{
    ctrblk->transferInformation.destInc = val;
    ctrblk->transferInformation.srcInc  = val;
}

void bcm283x_dma_set_source_address(struct dmaControlBlock_t *ctrblk, void *src)
{
    ctrblk->sourceAddr.addr = (u32_t)(u64_t)src;
}

void bcm283x_dma_set_destination_address(struct dmaControlBlock_t *ctrblk, void *dest)
{
    ctrblk->destinationAddr.addr = (u32_t)(u64_t)dest;
}

void bcm283x_dma_set_transfer_size(struct dmaControlBlock_t *ctrblk, u16_t sz)
{
    ctrblk->transactionLenght.xlenght = sz;
    ctrblk->transactionLenght.ylenght = 0x1;
}

void bcm283x_dma_2Dmode_set_transfer_size(struct dmaControlBlock_t *ctrblk, u16_t xsz, u16_t ysz)
{
    ctrblk->transactionLenght.xlenght = xsz;
    ctrblk->transactionLenght.ylenght = ysz;
}

void bcm283x_dma_set_final_interrupt(struct dmaControlBlock_t *ctrblk, bool val)
{
    ctrblk->transferInformation.inten = val;
}

void bcm283x_dma_set_peripheral(struct dmaControlBlock_t *ctrblk, u8_t periph)
{
    ctrblk->transferInformation.permap = periph;
}

void bcm283x_dma_set_ctrblk_addr(u8_t engine, void *addr)
{
    if (engine > BCM283x_DMA_CTRLBLCK_NUMBR)
        return;
    dmaEngineRegs[engine]->ctrlblockAddr.addr = (u32_t)(archv_t)addr;
}