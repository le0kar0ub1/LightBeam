#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaEngineRegister_t *dmaEngineRegs[];

#pragma message "write my driver :)"

static void bcm2837_dma_start_transfer(u8_t engine, void *blk)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR)
        return;
    bcm2837_dma_set_ctrblk_addr(engine, blk);
    bcm2837_dma_active_transfer(engine);
}

struct dmaControlBlock_t dmatestctrl;

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
    /* Set up our run */
    bcm2837_dma_set_address_inc(&dmatestctrl, true);
    bcm2837_dma_set_source_address(&dmatestctrl, src);
    bcm2837_dma_set_destination_address(&dmatestctrl, dest);
    bcm2837_dma_set_transfer_size(&dmatestctrl, sz);
    bcm2837_dma_set_final_interrupt(&dmatestctrl, true);
    bcm2837_dma_set_peripheral(&dmatestctrl, 0); // unpaced run
    bcm2837_dma_set_next_ctrlblk(&dmatestctrl, NULL); // next ctrlblk
    bcm2837_dma_set_ctrblk_addr(engine, &dmatestctrl);
    bcm2837_dma_active_transfer(engine);
    cycle_delay(100000000);
    if (dmaEngineRegs[engine]->ctrlStatus.error == 1)
        uart_kprint("ERROR\n");
    return (true);
}