.code32

.include "target/x86/common/boot.inc"

.extern __BSS_START
.extern __BSS_END

.section .text

.global clear_bss

/*
** BSS section clear
*/
clear_bss:
    LV2P $__BSS_START, %eax
    LV2P $__BSS_END, %ebx
    .bssclear:
        movb $0x0, (%eax)
        incl %eax
        cmpl %ebx, %eax
        jne .bssclear
    ret
