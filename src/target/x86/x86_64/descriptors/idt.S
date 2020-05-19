.code64

.include "target/x86/common/boot.inc"

.section .data

.global idt
.global idt_start
.global idt_end

.align 16
idt:
idt_start:
    .rept 256
        .2byte 0x0                  # Low 16 bits of ISR
        .2byte KERNEL_CODE_SELECTOR # Code selector
        .byte  0x0                  # IST mechanism
        .byte  0x8E                 # Present, ring-0, 32-bits interrupt gate
        .2byte 0x0                  # Middle 16 bits of ISR
        .4byte 0x0                  # High 32 bits ISR
        .4byte 0x0                  # reserved
    .endr
idt_end:

.section .rodata

.global idtptr

.align 16
idtptr:
    .2byte idt_end - idt_start - 0x1
    .8byte idt_start

.section .text

.global idt_load

idt_load:
    lidt idtptr
    ret

.global idt_init

idt_init:
    movq $isr, %rsi
    movq $idt, %rdi
    movq $0x100, %rcx
    .fill_idt:
        movq %rsi, %rbx
        movw %bx, (%rdi)
        shrq $0x10, %rbx 
        movw %bx, 6(%rdi)
        shrq $0x10, %rbx
        movl %ebx, 8(%rdi)
        addq $0x9, %rsi
        addq $0x10, %rdi 
        loop .fill_idt
    ret
