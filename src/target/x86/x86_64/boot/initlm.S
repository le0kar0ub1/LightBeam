
.section .text

.code32

.global initlm

initlm:
    movl $0xC0000080, %eax
    rdmsr
    orl $((0x1 << 0x8) | (0x1 << 0xB)), %eax
    wrmsr

    ret

.code64

.global setuplm

setuplm:

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
    # movl $stack_top, %esp
    # subl $0x8, %esp # multiboot structure & caller address pushed

    # popl %ebx
    # addl $__KERNEL_ADDR_TRNS, %ebx
    # mov $multiboot_virtaddr, %eax
    # mov %ebx, (%eax) # in our multiboot parser file

    ret
