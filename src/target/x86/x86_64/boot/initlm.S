.code64

.include "target/x86/common/boot.inc"

.section .text

.global lmworld

/*
** init long mode
** reaload values
** jump into kernel main
*/
lmworld:
    movw $KERNEL_DATA_SELECTOR, %ax
    movw %ax, %ds
    movw %ax, %ss
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs

    lea .higher_half, %rax
    jmp *%rax
    .higher_half:

    # reload stack
    movq $stack_top, %rsp

    # reload gdt
    movq $gdtptr, %rax
    lgdt (%rax)

    addq $__KERNEL_ADDR_TRNS, %rbx # mb2 address
    pushq %rbx
    mov $multiboot_virtaddr, %rax
    mov %rbx, (%rax) # in our multiboot parser file

    jmp kernelmain
