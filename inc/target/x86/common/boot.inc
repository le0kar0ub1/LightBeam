.if sysz == 64
    .equ __RECURSIVE_MAPPING_ADDR, 0xffffff7fbfdfe000
    .equ __RECURSIVE_MAPPING_IDX,  510
    .equ __KERNEL_ADDR_TRNS,       0xFFFFFFFF80000000
.elseif sysz == 32
    .equ __RECURSIVE_MAPPING_ADDR, 0xFFFFF000
    .equ __RECURSIVE_MAPPING_IDX,  1023
    .equ __KERNEL_ADDR_TRNS, 0xC0000000
.else
    .err
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
    .equ PAGE_ENTRY_SZ,  0x8
    .equ PAGE_ENTRY_NBR, 0x200
    .equ PAGE_TOTAL_SZ,  PAGE_ENTRY_NBR * PAGE_ENTRY_SZ
    .equ KERNEL_PML4_INDEX_START, ((__KERNEL_ADDR_TRNS >> 39) & ((1 << 9) - 1))
    .equ KERNEL_PDP_INDEX_START,  ((__KERNEL_ADDR_TRNS >> 30) & ((1 << 9) - 1))
    .equ KERNEL_PD_INDEX_START,   ((__KERNEL_ADDR_TRNS >> 21) & ((1 << 9) - 1))
    .equ KERNEL_PT_INDEX_START,   ((__KERNEL_ADDR_TRNS >> 12) & ((1 << 9) - 1))
.elseif sysz == 32
    .equ KERNEL_PAGEDIR_INDEX_START, (__KERNEL_ADDR_TRNS >> 22 & ((1 << 10) - 1))
    .equ PAGE_ENTRY_SZ,  0x4
    .equ PAGE_ENTRY_NBR, 0x400
    .equ PAGE_TOTAL_SZ,  PAGE_ENTRY_NBR * PAGE_ENTRY_SZ
.else
    .err
.endif

.equ NULL_SELECTOR,          0x00
.equ KERNEL_CODE_SELECTOR,   0x08
.equ KERNEL_DATA_SELECTOR,   0x10
.equ USER_CODE_SELECTOR,     0x18
.equ USER_DATA_SELECTOR,     0x20
.equ TSS_SELECTOR,           0x28
