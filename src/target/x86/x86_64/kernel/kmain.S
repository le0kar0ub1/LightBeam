.code64

.section .text

.global kernelmain

kernelmain:
    call idt_init
    call idt_load

    mov $0x2f592f412f4b2f4f, %rax
    mov %rax, (__KERNEL_ADDR_TRNS + 0xB8000)

    hlt
