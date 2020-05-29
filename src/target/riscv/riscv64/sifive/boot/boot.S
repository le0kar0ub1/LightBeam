.global _start

.extern _vectors
.extern __bss_start
.extern __bss_size

.section .init.text, "ax"

_start:
    la sp, _stack_top

    .option push
    .option norelax
        la gp, __global_pointer$
    .option pop

    /* save hart id and dtb pointer */
    mv tp, a0
    mv s1, a1

    /* clear all interrupts */
    csrw sie, x0

    /* load interrupt vector */
    # la t0, _vectors
    # csrw mtvec, t0

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
.rept 0x4000
    .byte
.endr
_stack_top:
