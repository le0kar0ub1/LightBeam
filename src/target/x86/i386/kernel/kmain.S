.code32

.section .text

.global kernelmain

kernelmain:
    hlt

okay:
    movl $0x2f4b2f4f, 0xB8000 + __KERNEL_ADDR_TRNS
    movl $0x2f592f41, 0xB8004 + __KERNEL_ADDR_TRNS
    hlt
