.code32

.include "target/x86/common/boot.inc"

.section .text

.global interrupt_handler

/*
** Prepare dispatcher
*/
interrupt_handler:
    cli
    pushal

    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs

    movw $KERNEL_DATA_SELECTOR, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs

    pushl %esp

    call interrupt_dispatch

    addl $0x4, %esp

    popl %gs
    popl %fs
    popl %es
    popl %ds

    popal

    addl $0x8, %esp

    iret
