.code32

.section .text

.global kernelmain

kernelmain:
    call idt_init
    call idt_load

    movl $0x2f4b2f4f, 0xB8000 + __KERNEL_ADDR_TRNS
    movl $0x2f592f41, 0xB8004 + __KERNEL_ADDR_TRNS

    push $0x0
    call run_initcall_level

    hlt

    pushl $okay
    pushl $0x0
    call isr_register_handler

    sti

    mov $0x0, %eax
    div %eax, %eax

#    hlt

okay:
    movl $0x2f4b2f4f, 0xB8000 + __KERNEL_ADDR_TRNS
    movl $0x2f592f41, 0xB8004 + __KERNEL_ADDR_TRNS
    hlt
