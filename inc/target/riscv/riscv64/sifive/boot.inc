.equ MSTATUS_UIE,         0x00000001
.equ MSTATUS_SIE,         0x00000002
.equ MSTATUS_HIE,         0x00000004
.equ MSTATUS_MIE,         0x00000008
.equ MSTATUS_UPIE,        0x00000010
.equ MSTATUS_SPIE,        0x00000020
.equ MSTATUS_HPIE,        0x00000040
.equ MSTATUS_MPIE,        0x00000080
.equ MSTATUS_SPP,         0x00000100
.equ MSTATUS_HPP,         0x00000600
.equ MSTATUS_MPP,         0x00001800
.equ MSTATUS_FS,          0x00006000
.equ MSTATUS_XS,          0x00018000
.equ MSTATUS_MPRV,        0x00020000
.equ MSTATUS_SUM,         0x00040000
.equ MSTATUS_MXR,         0x00080000
.equ MSTATUS_TVM,         0x00100000
.equ MSTATUS_TW,          0x00200000
.equ MSTATUS_TSR,         0x00400000
.equ MSTATUS32_SD,        0x80000000
.equ MSTATUS64_SD,        0x8000000000000000

.equ MCAUSE32_CAUSE,       0x7FFFFFFF
.equ MCAUSE64_CAUSE,       0x7FFFFFFFFFFFFFFF
.equ MCAUSE32_INT,         0x80000000
.equ MCAUSE64_INT,         0x8000000000000000

.equ SSTATUS_UIE,         0x00000001
.equ SSTATUS_SIE,         0x00000002
.equ SSTATUS_UPIE,        0x00000010
.equ SSTATUS_SPIE,        0x00000020
.equ SSTATUS_SPP,         0x00000100
.equ SSTATUS_FS,          0x00006000
.equ SSTATUS_XS,          0x00018000
.equ SSTATUS_SUM,         0x00040000
.equ SSTATUS_MXR,         0x00080000
.equ SSTATUS32_SD,        0x80000000
.equ SSTATUS64_SD,        0x8000000000000000

.equ DCSR_XDEBUGVER,      (3U<<30)
.equ DCSR_NDRESET,        (1<<29)
.equ DCSR_FULLRESET,      (1<<28)
.equ DCSR_EBREAKM,        (1<<15)
.equ DCSR_EBREAKH,        (1<<14)
.equ DCSR_EBREAKS,        (1<<13)
.equ DCSR_EBREAKU,        (1<<12)
.equ DCSR_STOPCYCLE,      (1<<10)
.equ DCSR_STOPTIME,       (1<<9)
.equ DCSR_CAUSE,          (7<<6)
.equ DCSR_DEBUGINT,       (1<<5)
.equ DCSR_HALT,           (1<<3)
.equ DCSR_STEP,           (1<<2)
.equ DCSR_PRV,            (3<<0)

.equ DCSR_CAUSE_NONE,     0
.equ DCSR_CAUSE_SWBP,     1
.equ DCSR_CAUSE_HWBP,     2
.equ DCSR_CAUSE_DEBUGINT, 3
.equ DCSR_CAUSE_STEP,     4
.equ DCSR_CAUSE_HALT,     5

.equ MCONTROL_SELECT,     (1<<19)
.equ MCONTROL_TIMING,     (1<<18)
.equ MCONTROL_ACTION,     (0x3f<<12)
.equ MCONTROL_CHAIN,      (1<<11)
.equ MCONTROL_MATCH,      (0xf<<7)
.equ MCONTROL_M,          (1<<6)
.equ MCONTROL_H,          (1<<5)
.equ MCONTROL_S,          (1<<4)
.equ MCONTROL_U,          (1<<3)
.equ MCONTROL_EXECUTE,    (1<<2)
.equ MCONTROL_STORE,      (1<<1)
.equ MCONTROL_LOAD,       (1<<0)

.equ MCONTROL_TYPE_NONE,      0
.equ MCONTROL_TYPE_MATCH,     2

.equ MCONTROL_ACTION_DEBUG_EXCEPTION,   0
.equ MCONTROL_ACTION_DEBUG_MODE,        1
.equ MCONTROL_ACTION_TRACE_START,       2
.equ MCONTROL_ACTION_TRACE_STOP,        3
.equ MCONTROL_ACTION_TRACE_EMIT,        4

.equ MCONTROL_MATCH_EQUAL,     0
.equ MCONTROL_MATCH_NAPOT,     1
.equ MCONTROL_MATCH_GE,        2
.equ MCONTROL_MATCH_LT,        3
.equ MCONTROL_MATCH_MASK_LOW,  4
.equ MCONTROL_MATCH_MASK_HIGH, 5

.equ IRQ_S_SOFT,   1
.equ IRQ_H_SOFT,   2
.equ IRQ_M_SOFT,   3
.equ IRQ_S_TIMER,  5
.equ IRQ_H_TIMER,  6
.equ IRQ_M_TIMER,  7
.equ IRQ_S_EXT,    9
.equ IRQ_H_EXT,    10
.equ IRQ_M_EXT,    11
.equ IRQ_COP,      12
.equ IRQ_HOST,     13

.equ MIP_SSIP,            (1 << IRQ_S_SOFT)
.equ MIP_HSIP,            (1 << IRQ_H_SOFT)
.equ MIP_MSIP,            (1 << IRQ_M_SOFT)
.equ MIP_STIP,            (1 << IRQ_S_TIMER)
.equ MIP_HTIP,            (1 << IRQ_H_TIMER)
.equ MIP_MTIP,            (1 << IRQ_M_TIMER)
.equ MIP_SEIP,            (1 << IRQ_S_EXT)
.equ MIP_HEIP,            (1 << IRQ_H_EXT)
.equ MIP_MEIP,            (1 << IRQ_M_EXT)

.equ SIP_SSIP, MIP_SSIP
.equ SIP_STIP, MIP_STIP

.equ PRV_U, 0
.equ PRV_S, 1
.equ PRV_H, 2
.equ PRV_M, 3

.equ SPTBR32_MODE, 0x80000000
.equ SPTBR32_ASID, 0x7FC00000
.equ SPTBR32_PPN,  0x003FFFFF
.equ SPTBR64_MODE, 0xF000000000000000
.equ SPTBR64_ASID, 0x0FFFF00000000000
.equ SPTBR64_PPN,  0x00000FFFFFFFFFFF

.equ SPTBR_MODE_OFF,  0
.equ SPTBR_MODE_SV32, 1
.equ SPTBR_MODE_SV39, 8
.equ SPTBR_MODE_SV48, 9
.equ SPTBR_MODE_SV57, 10
.equ SPTBR_MODE_SV64, 11

.equ PMP_R,     0x01
.equ PMP_W,     0x02
.equ PMP_X,     0x04
.equ PMP_A,     0x18
.equ PMP_L,     0x80
.equ PMP_SHIFT, 2

.equ PMP_TOR,   0x08
.equ PMP_NA4,   0x10
.equ PMP_NAPOT, 0x18

.equ DEFAULT_RSTVEC,     0x00001000
.equ CLINT_BASE,         0x02000000
.equ CLINT_SIZE,         0x000c0000
.equ EXT_IO_BASE,        0x40000000
.equ DRAM_BASE,          0x80000000

.equ PTE_V,     0x001 # Valid
.equ PTE_R,     0x002 # Read
.equ PTE_W,     0x004 # Write
.equ PTE_X,     0x008 # Execute
.equ PTE_U,     0x010 # User
.equ PTE_G,     0x020 # Global
.equ PTE_A,     0x040 # Accessed
.equ PTE_D,     0x080 # Dirty
.equ PTE_SOFT,  0x300 # Reserved for Software
