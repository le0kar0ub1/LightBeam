#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaControlBlock_t *dmaCtrlBlk[BCM2837_DMA_CTRLBLCK_NUMBR];

#pragma message "write my driver :)"

static void bcm2837_dma_start_transfer(void)
{

}

bool bcm2837_dma_run_transfer(void *, void *, size_t);
bool bcm2837_dma_run_transfer(void *src, void *dest, size_t sz)
{
    /* Adress must be 32B aligned */
    // if (!IS_ALIGNED(src, BCM2837_DMA_ADDRALIGN))
        // return (false);
    /* Get a unused engine for ou DMA operation */
    u8_t engine = bcm2837_dma_get_unused_engine();
    if (engine == (u8_t)-1)
        return (false);
    cycle_delay(100000000);
    bcm2837_dma_set_address_inc(engine, true);
    bcm2837_dma_set_source_address(engine, src);
    bcm2837_dma_set_destination_address(engine, dest);
    bcm2837_dma_set_transfer_size(engine, sz);
    bcm2837_dma_set_final_interrupt(engine, true);
    bcm2837_dma_set_peripheral(engine, 1);
    bcm2837_dma_active_transfer(engine);
    cycle_delay(100000000);
    if (dmaCtrlBlk[engine]->ctrlStatus.error == 1)
        uart_kprint("ERROR\n");
    return (true);
}