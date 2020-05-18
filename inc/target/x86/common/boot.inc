.if sysz == 64
    .equ __KERNEL_ADDR_TRNS, 0xFFFFFFFF80000000
.else
    .equ __KERNEL_ADDR_TRNS, 0xC0000000
.endif

.macro LV2P addr, reg
    movl \addr - __KERNEL_ADDR_TRNS, \reg
.endm

.macro SV2P reg, addr
    movl \reg, \addr - __KERNEL_ADDR_TRNS
.endm

.equ MMU_PRESENT,   (1 << 0)
.equ MMU_WRITABLE,  (1 << 1)
.equ MMU_SZ_TWO_MB, (1 << 7)

.if sysz == 64
    .equ PAGE_ENTRY_NBR, 0x200
    .equ PAGE_TOTAL_SZ,  0x1000
    .equ KERNEL_PML4_INDEX_START, (__KERNEL_ADDR_TRNS >> 39 & ((1 << 9) - 1))
    .equ KERNEL_PDP_INDEX_START,  (__KERNEL_ADDR_TRNS >> 30 & ((1 << 9) - 1))
    .equ KERNEL_PD_INDEX_START,   (__KERNEL_ADDR_TRNS >> 21 & ((1 << 9) - 1))
.else
    .equ KERNEL_PAGEDIR_INDEX_START, (__KERNEL_ADDR_TRNS >> 22 & ((1 << 10) - 1))
    .equ PAGE_ENTRY_NBR, 0x400
    .equ PAGE_TOTAL_SZ,  0x1000
.endif

.equ NULL_SELECTOR,          0x00
.equ KERNEL_CODE_SELECTOR,   0x08
.equ KERNEL_DATA_SELECTOR,   0x10
.equ USER_CODE_SELECTOR,     0x18
.equ USER_DATA_SELECTOR,     0x20
.equ TSS_SELECTOR,           0x28
