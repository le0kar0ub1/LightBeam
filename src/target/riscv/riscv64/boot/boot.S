.global _start

.extern _vectors
.extern __bss_start
.extern __bss_size

.section .init.text, "ax"

_start:
    la sp, _stack_top

    la x5,  _vectors
    csrw mtvec, x5

    la x5, __bss_start
    la x6, __bss_end
_clear_bss:
    sw x0, (0)(x5)
    add x5, x5, 4
    blt x5, x6, _clear_bss

_hang:
    j _hang

.section .bss
_stack_bottom:
.rept
    .4byte
.endr
_stack_top:
