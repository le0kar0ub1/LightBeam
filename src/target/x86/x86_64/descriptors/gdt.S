.code32

.include "target/x86/common/boot.inc"

.global gdtptr
.global gdtptr_phys
.global gdt


.section .rodata

.align 16
gdtptr:
    .2byte gdt_end - gdt_start - 1
    .8byte gdt

.align 16
gdtptr_phys:
    .2byte gdt_end - gdt_start - 1
    .4byte gdt - __KERNEL_ADDR_TRNS

.section .data

.align 16
gdt:
gdt_start:
    # NUll Selector
    .4byte 0
    .4byte 0

    # Kernel Code Selector
    .2byte 0xFFFF       # limit 15:0
    .2byte 0x0000       # base 15:0
    .byte  0x00         # base 23:16
    .byte  0b10011010   # P(1) DPL(00) (1) C(1) D(0) R(1) A(0)
    .byte  0b10101111   # G(1) S(1) (0) (0) limit 19:16
    .byte  0x00         # base 31:24

    # Kernel Data Selector
    .2byte 0xFFFF       # limit 15:0
    .2byte 0x0000       # base 15:0
    .byte  0x00         # base 23:16
    .byte  0b10010010   # P(1) DPL(00) (1) C(0) E(0) W(1) A(0)
    .byte  0b0000000     # G(1) S(1) (0) (0) limit 19:16
    .byte  0x00         # base 31:24

    # User Code Selector
    .2byte 0xFFFF       # limit 15:0
    .2byte 0x0000       # base 15:0
    .byte  0x00         # base 23:16
    .byte  0b11111010   # P(1) DPL(11) (1) C(1) D(0) R(1) A(0)
    .byte  0b11001111   # G(1) S(1) (0) (0) limit 19:16
    .byte  0x00         # base 31:24

    # User Data Selector
    .2byte 0xFFFF       # limit 15:0
    .2byte 0x0000       # base 15:0
    .byte  0x00         # base 23:16
    .byte  0b11110010   # P(1) DPL(11) (1) C(0) E(0) W(1) A(0)
    .byte  0b11001111   # G(1) S(1) (0) (0) limit 19:16
    .byte  0x00         # base 31:24

     #
    # Space for TSS
     #

    .4byte 0
    .4byte 0
gdt_end:
