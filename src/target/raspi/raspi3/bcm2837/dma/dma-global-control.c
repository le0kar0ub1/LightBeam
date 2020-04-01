#include "lightbeam.h"
#include "target/raspi/raspi3/bcm2837/dma.h"

extern volatile struct dma_intStatus_t *dmaIntStatus;
extern volatile struct dma_enable_t    *dmaEnableReg;

extern volatile struct dmaControlBlock_t *dmaCtrlBlk[BCM2837_DMA_CTRLBLCK_NUMBR];

static bool ownered[BCM2837_DMA_CTRLBLCK_NUMBR] = {false};

static void bcm2837_dma_set_engine_state(u8_t engine, bool val)
{
    switch (engine)
    {
        case 0:
            dmaEnableReg->EN0 = val;
            break;
        case 1:
            dmaEnableReg->EN1 = val;
            break;
        case 2:
            dmaEnableReg->EN2 = val;
            break;
        case 3:
            dmaEnableReg->EN3 = val;
            break;
        case 4:
            dmaEnableReg->EN4 = val;
            break;
        case 5:
            dmaEnableReg->EN5 = val;
            break;
        case 6:
            dmaEnableReg->EN6 = val;
            break;
        case 7:
            dmaEnableReg->EN7 = val;
            break;
        case 8:
            dmaEnableReg->EN8 = val;
            break;
        case 9:
            dmaEnableReg->EN9 = val;
            break;
        case 10:
            dmaEnableReg->EN10 = val;
            break;
        case 11:
            dmaEnableReg->EN11 = val;
            break;
        case 12:
            dmaEnableReg->EN12 = val;
            break;
        case 13:
            dmaEnableReg->EN13 = val;
            break;
        case 14:
            dmaEnableReg->EN14 = val;
            break;
        case 15:
            dmaEnableReg->EN15 = val;
            break;
        default:
            break;
    }
}

static void bcm2837_dma_set_interrupt_state(u8_t engine, bool val)
{
    switch (engine)
    {
        case 0:
            dmaIntStatus->INT0 = val;
            break;
        case 1:
            dmaIntStatus->INT1 = val;
            break;
        case 2:
            dmaIntStatus->INT2 = val;
            break;
        case 3:
            dmaIntStatus->INT3 = val;
            break;
        case 4:
            dmaIntStatus->INT4 = val;
            break;
        case 5:
            dmaIntStatus->INT5 = val;
            break;
        case 6:
            dmaIntStatus->INT6 = val;
            break;
        case 7:
            dmaIntStatus->INT7 = val;
            break;
        case 8:
            dmaIntStatus->INT8 = val;
            break;
        case 9:
            dmaIntStatus->INT9 = val;
            break;
        case 10:
            dmaIntStatus->INT10 = val;
            break;
        case 11:
            dmaIntStatus->INT11 = val;
            break;
        case 12:
            dmaIntStatus->INT12 = val;
            break;
        case 13:
            dmaIntStatus->INT13 = val;
            break;
        case 14:
            dmaIntStatus->INT14 = val;
            break;
        case 15:
            dmaIntStatus->INT15 = val;
            break;
        default:
            break;
    }
}

bool bcm2837_dma_get_engine_state(u8_t engine)
{
    return ((*(u32_t *)dmaEnableReg) & (1 << engine));
}

bool bcm2837_dma_get_engine_intstatus(u8_t engine)
{
    return ((*(u32_t *)dmaIntStatus) & (1 << engine));
}

void bcm2837_dma_disable_engine(u8_t engine)
{
    bcm2837_dma_set_engine_state(engine, false);
}

void bcm2837_dma_enable_engine(u8_t engine)
{
    bcm2837_dma_set_engine_state(engine, true);
}

void bcm2837_dma_disable_engine_int(u8_t engine)
{
    bcm2837_dma_set_interrupt_state(engine, false);
}

void bcm2837_dma_enable_engine_int(u8_t engine)
{
    bcm2837_dma_set_interrupt_state(engine, true);
}

int bcm2837_dma_get_unused_engine(void)
{
    int i = 0;
    while (i < BCM2837_DMA_CTRLBLCK_NUMBR)
    {
        if (ownered[i] == false && bcm2837_dma_get_engine_state(i))
        {
            bcm2837_dma_lock_engine(i);
            return (i);
        }
        i++;
    }
    return (-1);
}

void bcm2837_dma_lock_engine(u8_t engine)
{
    if (engine > BCM2837_DMA_CTRLBLCK_NUMBR || ownered[engine])
        return;
    ownered[engine] = true;
}

void bcm2837_dma_release_engine(u8_t engine)
{
    ownered[engine] = false;
}
