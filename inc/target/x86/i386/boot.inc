.macro LV2P addr, reg
    mov \addr - 0xC0000000, \reg
.endm

.macro SV2P addr, reg
    mov \reg, \addr - 0xC0000000
.endm
