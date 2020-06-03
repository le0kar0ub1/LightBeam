.code64

.include "target/x86/common/boot.inc"

.section .text

.global interrupt_handler

/*
** Prepare dispatcher
*/
interrupt_handler:
    pushq %rbp
    pushq %rdi
    pushq %rsi
    pushq %rbx
    pushq %rdx
    pushq %rcx
    pushq %rax

    pushq %r8
    pushq %r9
    pushq %r10
    pushq %r11
    pushq %r12
    pushq %r13
    pushq %r14
    pushq %r15

    mov %ds, %rax
    pushq %rax
    mov %es, %rax
    pushq %rax
    mov %fs, %rax
    pushq %rax
    mov %gs, %rax
    pushq %rax

    movw $KERNEL_DATA_SELECTOR, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %fs
    movw %ax, %gs

    mov %rsp, %rdi

    call interrupt_dispatch

    popq %rax
    mov %ax, %gs
    popq %rax
    mov %ax, %fs
    popq %rax
    mov %ax, %es
    popq %rax
    mov %ax, %ds

    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %r11
    popq %r10
    popq %r9
    popq %r8

    popq %rax
    popq %rcx
    popq %rdx
    popq %rbx
    popq %rsi
    popq %rdi
    popq %rbp

    addq $0x10, %rsp

    iretq
