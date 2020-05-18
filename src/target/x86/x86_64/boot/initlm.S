.code64

.section .text

.global lmworld

lmworld:
    hlt
    movq $stack_top, %rsp
    pushq 0x0
    hlt
    lea .higher_half, %rax
    jmp *%rax
    .higher_half:
    hlt

    movq $gdtptr, %rax
    lgdt (%rax)

    # LV2P $.kpage_first_entry, %eax
    # movl $0x0, .kpage_first_entry

    # lgdt gdtptr
    # # Reload Boot Values
    # subl $0x8, %esp # multiboot structure & caller address pushed

    # popl %ebx
    # addl $__KERNEL_ADDR_TRNS, %ebx
    # mov $multiboot_virtaddr, %eax
    # mov %ebx, (%eax) # in our multiboot parser file

    jmp kernelmain
