.if sysz == 64
.equ __KERNEL_ADDR_TRNS, 0xFFFFFFFF80000000
.else
.equ __KERNEL_ADDR_TRNS, 0xC0000000
.endif

.macro LV2P addr, reg
    mov \addr - __KERNEL_ADDR_TRNS, \reg
.endm

.macro SV2P addr, reg
    mov \reg, \addr - __KERNEL_ADDR_TRNS
.endm

.equ KERNEL_PAGE_INDEX_START, (0xC0000000 >> 22)

.equ NULL_SELECTOR,          0x00
.equ KERNEL_CODE_SELECTOR,   0x08
.equ KERNEL_DATA_SELECTOR,   0x10
.equ USER_CODE_SELECTOR,     0x18
.equ USER_DATA_SELECTOR,     0x20
