#ifndef __DMA_H_
#define __DMA_H_

#include "lightbeam.h"

#define BCM2837_DMA_ENTRY ((void *)((u64_t)ARCH_RASP_MMIOBASE + 0x7000))
#define BCM2837_DMA_CTRLBLCK_PITCH 0x100
#define BCM2837_DMA_CTRLBLCK_NUMBR 0x10

#define BCM2837_DMA_INTSTATUSREG ((void *)((u64_t)BCM2837_DMA_ENTRY + 0xFE0))
#define BCM2837_DMA_ENABLEREG    ((void *)((u64_t)BCM2837_DMA_ENTRY + 0xFF0))

#define BCM2837_DMA_ADDRALIGN 0x20

struct dma_ctrlStatus_t
{
    u32_t active         : 1; // write 1 == transfer starting
    u32_t end            : 1; // if 1 the transfer is completed (write 1 to clear)
    u32_t intState       : 1; // write 1 == clear
    u32_t dreqState      : 1; // 1 == requesting data & 0 == no request
    u32_t paused         : 1; // 1 == paused & 0 == running
    u32_t dreqStopDma    : 1; // 1 == paused & 0 == running
    u32_t waitingwrites  : 1; // if 1 == dma waiting the last write
    u32_t _reserved2     : 1;
    u32_t error          : 1; // if 1 error occured
    u32_t _reserved1     : 7;
    u32_t priority       : 4; // set priority of normal AXI bus
    u32_t panic_priority : 4; // set priority of panicking bus
    u32_t _reserved0     : 4;
    u32_t waitwrites     : 1;
    u32_t disdebug       : 1; // if 1 DMA unsensible to pause signal
    u32_t abort          : 1; // write 1 == abort CB
    u32_t reset          : 1; // write 1 == reset
};

struct dma_ctrlblockAddr_t
{
    u32_t addr;
};

struct dma_transferInformation_t
{
    u32_t inten       : 1; // if 1 -> interrupt when transfer done
    u32_t tdmode      : 1; // (rtfm)
    u32_t _reserved0  : 1;
    u32_t waitResp    : 1; // if 1 -> wait for end of write
    u32_t destInc     : 1; // if 1 -> automate inc address by 32 or 4 if DESTWiDTH == 0
    u32_t destWidth   : 1; // if 1 -> 128b address else 32
    u32_t destDreq    : 1; // if 1 -> PERMAP gate the dest writes
    u32_t destIgnore  : 1; // if 1 -> No write
    u32_t srcInc      : 1; // if 1 -> automate inc address by 32 or 4 if SRCWiDTH == 0
    u32_t srcWidth    : 1; // if 1 -> 128b address else 32
    u32_t srcDreq     : 1; // if 1 -> PERMAP gate the dest writes
    u32_t srcIgnore   : 1; // if 1 -> No read
    u32_t burstLenght : 4; // Burst dma transfers (rtfm)
    u32_t permap      : 5; // peripheral number (1-31)
    u32_t wait        : 5; // wait X cycles after each R/W operation
    u32_t noWideBurst : 1; // (rtfm)
    u32_t _reserved_1 : 5; 
};

struct dma_sourceAddr_t
{
    u32_t addr;
};

struct dma_destinationAddr_t
{
    u32_t addr;
};

struct dma_transactionLenght_t
{
    u32_t xlenght   : 16; // lenght transfer size
    u32_t ylenght   : 15; // if tdmode then transfer X * Y
    u32_t _reserved : 1;
};

// if tdmode only
struct dma_stride_t
{
    u32_t destStride : 16; // (if 2d mode) signed 2s complement to dest address at each end row
    u32_t srcStride  : 16; // (if 2d mode) signed 2s complement to src address at each end row
};

// must be 0x100 aligned
struct dma_nextCtrlBlockAddr_t
{
    u32_t addr; // next ctrblk for chain DMA operation
};

struct dma_debug_t
{
    u32_t lastReadNoSet : 1;
    u32_t fifoErr       : 1;
    u32_t readErr       : 1;
    u32_t _reserved0    : 1;
    u32_t stadingWrites : 4; // get not already been received write
    u32_t dmaID         : 8; // get channel dma id
    u32_t dmaState      : 9; // channel state
    u32_t version       : 3;
    u32_t dmaLite       : 1; // if 1 dma is reduced performance
    u32_t _reserved1    : 3;
};


struct dma_intStatus_t
{
    u32_t INT0      : 1;   // Interrupt status of DMA engine 0 RW 0x0
    u32_t INT1      : 1;   // Interrupt status of DMA engine 1 RW 0x0
    u32_t INT2      : 1;   // Interrupt status of DMA engine 2 RW 0x0
    u32_t INT3      : 1;   // Interrupt status of DMA engine 3 RW 0x0
    u32_t INT4      : 1;   // Interrupt status of DMA engine 4 RW 0x0
    u32_t INT5      : 1;   // Interrupt status of DMA engine 5 RW 0x0
    u32_t INT6      : 1;   // Interrupt status of DMA engine 6 RW 0x0
    u32_t INT7      : 1;   // Interrupt status of DMA engine 7 RW 0x0
    u32_t INT8      : 1;   // Interrupt status of DMA engine 8 RW 0x0
    u32_t INT9      : 1;   // Interrupt status of DMA engine 9 RW 0x0
    u32_t INT10     : 1;   // Interrupt status of DMA engine 10 RW 0x0
    u32_t INT11     : 1;   // Interrupt status of DMA engine 11 RW 0x0
    u32_t INT12     : 1;   // Interrupt status of DMA engine 12 RW 0x0
    u32_t INT13     : 1;   // Interrupt status of DMA engine 13 RW 0x0
    u32_t INT14     : 1;   // Interrupt status of DMA engine 14 RW 0x0
    u32_t INT15     : 1;   // Interrupt status of DMA engine 15 RW 0x0
    u32_t _reserved : 16;
};

struct dma_enable_t
{
    u32_t EN0      : 1;    // enable DMA engine 0 RW 0x0
    u32_t EN1      : 1;    // enable DMA engine 1 RW 0x0
    u32_t EN2      : 1;    // enable DMA engine 2 RW 0x0
    u32_t EN3      : 1;    // enable DMA engine 3 RW 0x0
    u32_t EN4      : 1;    // enable DMA engine 4 RW 0x0
    u32_t EN5      : 1;    // enable DMA engine 5 RW 0x0
    u32_t EN6      : 1;    // enable DMA engine 6 RW 0x0
    u32_t EN7      : 1;    // enable DMA engine 7 RW 0x0
    u32_t EN8      : 1;    // enable DMA engine 8 RW 0x0
    u32_t EN9      : 1;    // enable DMA engine 9 RW 0x0
    u32_t EN10     : 1;   // enable DMA engine 10 RW 0x0
    u32_t EN11     : 1;   // enable DMA engine 11 RW 0x0
    u32_t EN12     : 1;   // enable DMA engine 12 RW 0x0
    u32_t EN13     : 1;   // enable DMA engine 13 RW 0x0
    u32_t EN14     : 1;   // enable DMA engine 14 RW 0x0
    u32_t EN15     : 1;   // enable DMA engine 15 RW 0x0
    u32_t _reserved : 16;
};

struct dmaControlBlock_t
{
/* offset */
/*  0x0   */  struct dma_ctrlStatus_t ctrlStatus;
/*  0x4   */  struct dma_ctrlblockAddr_t ctrlblockAddr;
/*  0x8   */  struct dma_transferInformation_t transferInformation;
/*  0xC   */  struct dma_sourceAddr_t sourceAddr;
/*  0x10  */  struct dma_destinationAddr_t destinationAddr;
/*  0x14  */  struct dma_transactionLenght_t transactionLenght;
/*  0x18  */  struct dma_stride_t stride;
/*  0x1C  */  struct dma_nextCtrlBlockAddr_t nextCtrlBlockAddr;
/*  0x20  */  struct dma_debug_t debug;
};

void bcm2837_dma_disable_engine(u8_t);
void bcm2837_dma_enable_engine(u8_t);
void bcm2837_dma_disable_engine_int(u8_t);
void bcm2837_dma_enable_engine_int(u8_t);

bool bcm2837_dma_get_engine_state(u8_t);
bool bcm2837_dma_get_engine_intstatus(u8_t);


/* BCM2837 official spec
The DMA is started by writing the address of a CB structure into the CONBLK_AD register
and then setting the ACTIVE bit. The DMA will fetch the CB from the address set in the
SCB_ADDR field of this reg and it will load it into the read-only registers described below.
It will then begin a DMA transfer according to the information in the CB.
When it has completed the current DMA transfer (length => 0) the DMA will update the
CONBLK_AD register with the contents of the NEXTCONBK register, fetch a new CB from
that address, and start the whole procedure once again.
The DMA will stop (and clear the ACTIVE bit) when it has completed a DMA transfer and
the NEXTCONBK register is set to 0x0000_0000. It will load this value into the
CONBLK_AD reg and then stop. 

Most of the control block registers cannot be written to directly as they loaded automatically
from memory. They can be read to provide status information, and to indicate the progress of
the current DMA transfer. The value loaded into the NEXTCONBK register can be
overwritten so that the linked list of Control Block data structures can be dynamically altered.
However it is only safe to do this when the DMA is paused. 
*/

#endif