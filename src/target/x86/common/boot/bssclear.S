.code32

.extern __BSS_START
.extern __BSS_END

.global clear_bss

/*
** BSS section clear
*/

clear_bss:
    movl $__BSS_START, %eax
    .bssclear:
        movb $0x0, (%eax)
        incl %eax
        cmpl $__BSS_END, %eax
        jne .bssclear
    ret
