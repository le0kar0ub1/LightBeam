#include "lightbeam.h"
#include "target/raspi/shared/bcm283X/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaEngineRegister_t *dmaEngineRegs[];

#pragma message "write my driver :)"

static void bcm283x_dma_start_transfer(u8_t engine, void *blk)
{
    if (engine > BCM283x_DMA_CTRLBLCK_NUMBR)
        return;
    bcm283x_dma_set_ctrblk_addr(engine, blk);
    bcm283x_dma_active_transfer(engine);
}

struct dmaControlBlock_t dmatestctrl;
// void dmatest(void);
// void dmatest(void)
// {
//     char d[20] __aligned(32); 
//     char const *s __aligned(32) = "transfer me";
//     bcm283x_dma_enable_engine(0);
//     bcm283x_dma_enable_engine_int(0);
//     rpifb_kprint("GOOD? -> %s\n" , bcm283x_dma_run_transfer((void*)s, (void*)d, 4) == true ? "yes" : "no");
//     cycle_delay(200000000);
//     d[15] = 0x0;
//     rpifb_kprint("gotit? -> %s\n", d);
// }


bool bcm283x_dma_run_transfer(void *, void *, size_t);
bool bcm283x_dma_run_transfer(void *src __unused, void *dest __unused, size_t sz __unused)
{
    /* Adress must be 32B aligned */
    // if (!IS_ALIGNED(src, BCM283x_DMA_ADDRALIGN))
        // return (false);
    /* Get a unused engine for ou DMA operation */
    u8_t engine = bcm283x_dma_get_unused_engine();
    if (engine == (u8_t)-1)
        return (false);
    /* Set up our run */
    bcm283x_dma_set_address_inc(&dmatestctrl, true);
    bcm283x_dma_set_source_address(&dmatestctrl, src);
    bcm283x_dma_set_destination_address(&dmatestctrl, dest);
    bcm283x_dma_set_transfer_size(&dmatestctrl, sz);
    bcm283x_dma_set_final_interrupt(&dmatestctrl, true);
    bcm283x_dma_set_peripheral(&dmatestctrl, 0); // unpaced run
    bcm283x_dma_set_next_ctrlblk(&dmatestctrl, NULL); // next ctrlblk
    bcm283x_dma_set_ctrblk_addr(engine, &dmatestctrl);
    bcm283x_dma_active_transfer(engine);
    return (true);
}