.code32

.section .text

.global kernelmain

kernelmain:
    call idt_init
    call idt_load

    # parse the multiboot header
    call multiboot_parse_tags

    call run_inithooks

    pushl $.imalive
    call  vga_printf
    pushl $.imalive
    call  serial_printf

    hlt

okay:
    cli
    movl $0x2f4b2f4f, 0xB8000 + __KERNEL_ADDR_TRNS
    movl $0x2f592f41, 0xB8004 + __KERNEL_ADDR_TRNS
    hlt

.section .data
.imalive: .asciz "Hello world\n"
