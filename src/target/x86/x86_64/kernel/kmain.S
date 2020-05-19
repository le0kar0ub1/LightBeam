.code64

.section .text

.global kernelmain

kernelmain:
    call idt_init
    call idt_load

    #call multiboot_parse_tags

    call run_inithooks

    movq $.imalive, %rdi
    call vga_puts
    movq $.imalive, %rdi
    call serial_puts

okay:
    cli
    movl $0x2f4b2f4f, 0xB8000 + __KERNEL_ADDR_TRNS
    movl $0x2f592f41, 0xB8004 + __KERNEL_ADDR_TRNS
    hlt

.section .data
.imalive: .asciz "Hello world\n"
