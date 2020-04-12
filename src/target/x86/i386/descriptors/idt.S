.code32

.include "target/x86/shared/boot.inc"

.section .data

.global idt
.global idt_start
.global idt_end

idt:
    idt_start:
        .rept 256
            .2byte 0                    # Low 16 bits of ISR
            .2byte KERNEL_CODE_SELECTOR # Code selector
            .byte  0
            .byte  0x8E                 # Present, ring-0, 32-bits interrupt gate
            .2byte 0                    # High 16 bits of ISR
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