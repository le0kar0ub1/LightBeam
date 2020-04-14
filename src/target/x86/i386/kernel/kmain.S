.code32

.section .text

.global kernelmain

kernelmain:
    call idt_init
    call idt_load

    pushl $0x0
    call run_initcall_level

    pushl $.imhere
    call  vga_printf
    pushl $.imhere
    call  serial_printf

    hlt

okay:
    cli
    movl $0x2f4b2f4f, 0xB8000 + __KERNEL_ADDR_TRNS
    movl $0x2f592f41, 0xB8004 + __KERNEL_ADDR_TRNS
    hlt

.section .data
.imhere: .asciz "Hello X wolrd\n"
