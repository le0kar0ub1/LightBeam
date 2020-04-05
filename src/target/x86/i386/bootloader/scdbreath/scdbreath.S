.section .text.boot, "ax"

_scdbreath:
    jmp _scdbreath

.section .data.boot, "awd"

.balign 8
_bootgdt16:
    .word   _bootgdt16_end - _bootgdt16 - 1
    .long   0
    .word   0
    .quad   0x0000000000000000  /* Reserved */
    .quad   0x00cf9a000000ffff  /* __KERNEL_CS */
    .quad   0x00cf92000000ffff  /* __KERNEL_DS */
_bootgdt16_end:
