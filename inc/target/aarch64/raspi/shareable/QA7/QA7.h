#ifndef __BCM_QA7_H_
#define __BCM_QA7_H_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

// https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2836/QA7_rev3.4.pdf

#define BCM_QA7_ENTRY ((void *)(0x40000000))

enum CoreRouting
{
    LOCALTIMER_TO_CORE0_IRQ = 0,
    LOCALTIMER_TO_CORE1_IRQ = 1,
    LOCALTIMER_TO_CORE2_IRQ = 2,
    LOCALTIMER_TO_CORE3_IRQ = 3,
    LOCALTIMER_TO_CORE0_FIQ = 4,
    LOCALTIMER_TO_CORE1_FIQ = 5,
    LOCALTIMER_TO_CORE2_FIQ = 6,
    LOCALTIMER_TO_CORE3_FIQ = 7
};

struct ctrlReg_t
{
    u32_t _reserved0   : 8;
    u32_t clockSource  : 1;
    u32_t increment    : 1;
    u32_t _reserved1   : 22;
} __attribute__((__packed__, aligned(4)));

struct GPUintRouting_t
{
    u32_t irq : 2; 
    u32_t fiq : 2;
    u32_t _reserved : 28;
} __attribute__((__packed__, aligned(4)));

struct perfMonitorIntRouting_t
{
    u32_t PMU_IRQ0ctrl : 1;
    u32_t PMU_IRQ1ctrl : 1;
    u32_t PMU_IRQ2ctrl : 1;
    u32_t PMU_IRQ3ctrl : 1;
    u32_t PMU_FIQ0ctrl : 1;
    u32_t PMU_FIQ1ctrl : 1;
    u32_t PMU_FIQ2ctrl : 1;
    u32_t PMU_FIQ3ctrl : 1;
    u32_t _reserved   : 24;
} __attribute__((__packed__, aligned(4)));

struct coreXTimerIntCtrl_t
{
    u32_t nCNTPSIRQ_IRQ : 1;   // @0 Secure physical timer event IRQ enabled, This bit is only valid if bit 4 is clear otherwise it is ignored. 
    u32_t nCNTPNSIRQ_IRQ : 1;  // @1 Non-secure physical timer event IRQ enabled, This bit is only valid if bit 5 is clear otherwise it is ignored
    u32_t nCNTHPIRQ_IRQ : 1;   // @2 Hypervisor physical timer event IRQ enabled, This bit is only valid if bit 6 is clear otherwise it is ignored
    u32_t nCNTVIRQ_IRQ : 1;    // @3 Virtual physical timer event IRQ enabled, This bit is only valid if bit 7 is clear otherwise it is ignored
    u32_t nCNTPSIRQ_FIQ : 1;   // @4 Secure physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (0) 
    u32_t nCNTPNSIRQ_FIQ : 1;  // @5 Non-secure physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (1)
    u32_t nCNTHPIRQ_FIQ : 1;   // @6 Hypervisor physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (2)
    u32_t nCNTVIRQ_FIQ : 1;    // @7 Virtual physical timer event FIQ enabled, If set, this bit overrides the IRQ bit (3)
    u32_t _reserved   : 24;
} __attribute__((__packed__, aligned(4)));

struct coreXMboxintCtrl_t
{
    u32_t MBOX_IRQ0ctrl : 1;
    u32_t MBOX_IRQ1ctrl : 1;
    u32_t MBOX_IRQ2ctrl : 1;
    u32_t MBOX_IRQ3ctrl : 1;
    u32_t MBOX_FIQ0ctrl : 1;
    u32_t MBOX_FIQ1ctrl : 1;
    u32_t MBOX_FIQ2ctrl : 1;
    u32_t MBOX_FIQ3ctrl : 1;
    u32_t _reserved     : 24;
} __attribute__((__packed__, aligned(4)));

struct corexIQ_Source_t
{
    u32_t CNTPSIRQ  : 1;
    u32_t CNTPNSIRQ : 1;
    u32_t CNTHPIRQ  : 1;
    u32_t CNTVIRQ   : 1;
    u32_t MBOX0Int  : 1;
    u32_t MBOX1Int  : 1;
    u32_t MBOX2Int  : 1;
    u32_t MBOX3Int  : 1;
    u32_t GPUInt    : 1;
    u32_t PMUint    : 1;
    u32_t AXIoutstandingInt : 1; // core0 only & 0 if FIQ
    u32_t localTimerInt : 1;
    u32_t peripheralInt : 6;
    u32_t _reserved   : 14;
} __attribute__((__packed__, aligned(4)));

struct TimerCtrl_t
{
    u32_t reload      : 28;
    u32_t timerEnable : 1;
    u32_t intEnable   : 1;
    u32_t _reserved   : 1;
    u32_t intPending  : 1; // RO
} __attribute__((__packed__, aligned(4)));

struct TimerClearReload_t
{
    u32_t _reserved  : 28;
    u32_t reload     : 1; // RW
    u32_t intClr     : 1; // RW
} __attribute__((__packed__, aligned(4)));

struct timerRouting_t
{
    enum CoreRouting route : 3;
    u32_t _reserved        : 29;
} __attribute__((__packed__, aligned(4)));

struct bcm_qa7_regs_t
{
/* 0x00 */ struct ctrlReg_t ctrlReg;
/* 0x04 */ u32_t _unused0;
/* 0x08 */ u32_t coreTimerPrescaler; // timer-freq == (2^31 / prescaler) * freq input
/* 0x0C */ struct GPUintRouting_t GPUintRouting;
/* 0x10 */ struct perfMonitorIntRouting_t perfMonitor_IntRoutingSet;
/* 0x14 */ struct perfMonitorIntRouting_t perfMonitor_IntRoutingClear;
/* 0x18 */ u32_t _unused1;
/* 0x1C */ u32_t coreTimerAccessLS32;
/* 0x20 */ u32_t coreTimerAccessMS32;
/* 0x24 */ struct timerRouting_t timerRouting;
/* 0x28 */ u32_t GPIORouting;
/* 0x2C */ u32_t AxiOutstandingcounters;
/* 0x30 */ u32_t AxiOutstandingIRQ;
/* 0x34 */ struct TimerCtrl_t timerCtrl;
/* 0x38 */ struct TimerClearReload_t timerClearReload;
/* 0x3C */ u32_t _unused3;
/* 0x40 */ struct coreXTimerIntCtrl_t core0TimerIntCtrl;
/* 0x44 */ struct coreXTimerIntCtrl_t core1TimerIntCtrl;
/* 0x48 */ struct coreXTimerIntCtrl_t core2TimerIntCtrl;
/* 0x4C */ struct coreXTimerIntCtrl_t core3TimerIntCtrl;
/* 0x50 */ struct coreXMboxintCtrl_t core0MboxintCtrl;
/* 0x54 */ struct coreXMboxintCtrl_t core1MboxintCtrl;
/* 0x58 */ struct coreXMboxintCtrl_t core2MboxintCtrl;
/* 0x5C */ struct coreXMboxintCtrl_t core3MboxintCtrl;
/* 0x60 */ struct corexIQ_Source_t core0IRQ_Source;
/* 0x64 */ struct corexIQ_Source_t core1IRQ_Source;
/* 0x68 */ struct corexIQ_Source_t core2IRQ_Source;
/* 0x6C */ struct corexIQ_Source_t core3IRQ_Source;
/* 0x70 */ struct corexIQ_Source_t core0FIQ_Source;
/* 0x74 */ struct corexIQ_Source_t core1FIQ_Source;
/* 0x78 */ struct corexIQ_Source_t core2FIQ_Source;
/* 0x7C */ struct corexIQ_Source_t core3FIQ_Source;
/* 0x80 */ u32_t core0Mbox0WO; // write-set (WO)
/* 0x84 */ u32_t core0Mbox1WO; // write-set (WO)
/* 0x88 */ u32_t core0Mbox2WO; // write-set (WO)
/* 0x8C */ u32_t core0Mbox3WO; // write-set (WO)
/* 0x90 */ u32_t core1Mbox0WO; // write-set (WO)
/* 0x94 */ u32_t core1Mbox1WO; // write-set (WO)
/* 0x98 */ u32_t core1Mbox2WO; // write-set (WO)
/* 0x9C */ u32_t core1Mbox3WO; // write-set (WO)
/* 0xA0 */ u32_t core2Mbox0WO; // write-set (WO)
/* 0xA4 */ u32_t core2Mbox1WO; // write-set (WO)
/* 0xA8 */ u32_t core2Mbox2WO; // write-set (WO)
/* 0xAC */ u32_t core2Mbox3WO; // write-set (WO)
/* 0xB0 */ u32_t core3Mbox0WO; // write-set (WO)
/* 0xB4 */ u32_t core3Mbox1WO; // write-set (WO)
/* 0xB8 */ u32_t core3Mbox2WO; // write-set (WO)
/* 0xBC */ u32_t core3Mbox3WO; // write-set (WO)
/* 0xC0 */ u32_t core0Mbox0RDnCLR; // read & write-high-to-clear
/* 0xC4 */ u32_t core0Mbox1RDnCLR; // read & write-high-to-clear
/* 0xC8 */ u32_t core0Mbox2RDnCLR; // read & write-high-to-clear
/* 0xCC */ u32_t core0Mbox3RDnCLR; // read & write-high-to-clear
/* 0xD0 */ u32_t core1Mbox0RDnCLR; // read & write-high-to-clear
/* 0xD4 */ u32_t core1Mbox1RDnCLR; // read & write-high-to-clear
/* 0xD8 */ u32_t core1Mbox2RDnCLR; // read & write-high-to-clear
/* 0xDC */ u32_t core1Mbox3RDnCLR; // read & write-high-to-clear
/* 0xE0 */ u32_t core2Mbox0RDnCLR; // read & write-high-to-clear
/* 0xE4 */ u32_t core2Mbox1RDnCLR; // read & write-high-to-clear
/* 0xE8 */ u32_t core2Mbox2RDnCLR; // read & write-high-to-clear
/* 0xEC */ u32_t core2Mbox3RDnCLR; // read & write-high-to-clear
/* 0xF0 */ u32_t core3Mbox0RDnCLR; // read & write-high-to-clear
/* 0xF4 */ u32_t core3Mbox1RDnCLR; // read & write-high-to-clear
/* 0xF8 */ u32_t core3Mbox2RDnCLR; // read & write-high-to-clear
/* 0xFC */ u32_t core3MboRnWDTCLR; // read & write-high-to-clear
} __attribute__((__packed__, aligned(4)));

#define CORE0_TIMER_IRQCNTL 0x40000040
#define CORE1_TIMER_IRQCNTL 0x40000044
#define CORE2_TIMER_IRQCNTL 0x40000048
#define CORE3_TIMER_IRQCNTL 0x4000004C
// Where to route timer interrupt to, IRQ/FIQ
// Setting both the IRQ and FIQ bit gives an FIQ
#define TIMER0_IRQ 0x01
#define TIMER1_IRQ 0x02
#define TIMER2_IRQ 0x04
#define TIMER3_IRQ 0x08
#define TIMER0_FIQ 0x10
#define TIMER1_FIQ 0x20
#define TIMER2_FIQ 0x40
#define TIMER3_FIQ 0x80
// Mailbox interrupt control registers
#define CORE0_MBOX_IRQCNTL 0x40000050
#define CORE1_MBOX_IRQCNTL 0x40000054
#define CORE2_MBOX_IRQCNTL 0x40000058
#define CORE3_MBOX_IRQCNTL 0x4000005C
// Where to route mailbox interrupt to, IRQ/FIQ
// Setting both the IRQ and FIQ bit gives an FIQ
#define MBOX0_IRQ 0x01
#define MBOX1_IRQ 0x02
#define MBOX2_IRQ 0x04
#define MBOX3_IRQ 0x08
#define MBOX0_FIQ 0x10
#define MBOX1_FIQ 0x20
#define MBOX2_FIQ 0x40
#define MBOX3_FIQ 0x80
// IRQ & FIQ source registers
#define CORE0_IRQ_SOURCE 0x40000060
#define CORE1_IRQ_SOURCE 0x40000064
#define CORE2_IRQ_SOURCE 0x40000068
#define CORE3_IRQ_SOURCE 0x4000006C
#define CORE0_FIQ_SOURCE 0x40000070
#define CORE1_FIQ_SOURCE 0x40000074
#define CORE2_FIQ_SOURCE 0x40000078
#define CORE3_FIQ_SOURCE 0x4000007C
// Interrupt source bits
// IRQ and FIQ are the same
// GPU bits can be set for one core only
#define INT_SRC_TIMER0 0x00000001
#define INT_SRC_TIMER1 0x00000002
#define INT_SRC_TIMER2 0x00000004
#define INT_SRC_TIMER3 0x00000008
#define INT_SRC_MBOX0 0x00000010
#define INT_SRC_MBOX1 0x00000020
#define INT_SRC_MBOX2 0x00000040
#define INT_SRC_MBOX3 0x00000080
#define INT_SRC_GPU 0x00000100
#define INT_SRC_PMU 0x00000200
// Mailbox write-set registers (Write only)
#define CORE0_MBOX0_SET 0x40000080
#define CORE0_MBOX1_SET 0x40000084
#define CORE0_MBOX2_SET 0x40000088
#define CORE0_MBOX3_SET 0x4000008C
#define CORE1_MBOX0_SET 0x40000090
#define CORE1_MBOX1_SET 0x40000094
#define CORE1_MBOX2_SET 0x40000098
#define CORE1_MBOX3_SET 0x4000009C
#define CORE2_MBOX0_SET 0x400000A0
#define CORE2_MBOX1_SET 0x400000A4
#define CORE2_MBOX2_SET 0x400000A8
#define CORE2_MBOX3_SET 0x400000AC
#define CORE3_MBOX0_SET 0x400000B0
#define CORE3_MBOX1_SET 0x400000B4
#define CORE3_MBOX2_SET 0x400000B8
#define CORE3_MBOX3_SET 0x400000BC
// Mailbox write-clear registers (Read & Write)
#define CORE0_MBOX0_RDCLR 0x400000C0
#define CORE0_MBOX1_RDCLR 0x400000C4
#define CORE0_MBOX2_RDCLR 0x400000C8
#define CORE0_MBOX3_RDCLR 0x400000CC
#define CORE1_MBOX0_RDCLR 0x400000D0
#define CORE1_MBOX1_RDCLR 0x400000D4
#define CORE1_MBOX2_RDCLR 0x400000D8
#define CORE1_MBOX3_RDCLR 0x400000DC
#define CORE2_MBOX0_RDCLR 0x400000E0
#define CORE2_MBOX1_RDCLR 0x400000E4
#define CORE2_MBOX2_RDCLR 0x400000E8
#define CORE2_MBOX3_RDCLR 0x400000EC
#define CORE3_MBOX0_RDCLR 0x400000F0
#define CORE3_MBOX1_RDCLR 0x400000F4
#define CORE3_MBOX2_RDCLR 0x400000F8
#define CORE3_MBOX3_RDCLR 0x400000FC

#endif