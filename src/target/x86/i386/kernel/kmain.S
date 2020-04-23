.code32

.section .text

.global kernelmain

kernelmain:
    call idt_init
    call idt_load

    call multiboot_parse_tags # parse the multiboot header

    pushl $0x0
    call run_initcall_level # run boot initcalls

    pushl $0x1
    call run_initcall_level # run pure initcalls

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
