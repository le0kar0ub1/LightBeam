.code32

.include "target/x86/common/boot.inc"

.section .data

.global idt
.global idt_start
.global idt_end

idt:
idt_start:
    .rept 256
        .2byte 0x0                  # Low 16 bits of ISR
        .2byte KERNEL_CODE_SELECTOR # Code selector
        .byte  0x0
        .byte  0x8E                 # Present, ring-0, 32-bits interrupt gate
        .2byte 0x0                  # High 16 bits of ISR
    .endr
idt_end:

.section .rodata

.global idtptr

idtptr:
    .2byte idt_end - idt_start - 0x1
    .4byte idt_start

.section .text

.global idt_load

idt_load:
    lidt idtptr
    ret

.global idt_init

idt_init:
    movl $isr, %esi
    movl $idt, %edi
    movl $0x100, %ecx
    .fill_idt:
        movl %esi, %ebx
        movw %bx, (%edi)
        shrl $0x10, %ebx 
        movw %bx, 6(%edi)
        addl $0xC, %esi
        addl $0x8, %edi 
        loop .fill_idt
    ret
