.global _start

.extern _vectors
.extern __bss_start
.extern __bss_size
.extern __bss_end

.section .init.text, "ax"

_start:
    /* clear all interrupts */
    csrw sie, x0

    .option push
    .option norelax
        la gp, __global_pointer
    .option pop

    /*
    ** Disable FPU to detect illegal usage of
    ** floating point in kernel space
    */
    li t0, 0x00006000
    csrc sstatus, t0

    /* Pick one hart to run the main boot sequence */
    la a3, hart_lottery
    li a2, 1
    amoadd.w a3, a2, (a3)
    bnez a3, .Lsecondary_start

    /* Clear BSS for flat non-ELF images */
    la a3, __bss_start
    la a4, __bss_end
    ble a4, a3, clear_bss_done
clear_bss:
    sw zero, (a3)
    add a3, a3, 8
    blt a3, a4, clear_bss
clear_bss_done:

    /* save hart id and dtb pointer */
    mv tp, a0
    mv s1, a1

    la sp, _stack_top

    /* load interrupt vector */
    # la t0, _vectors
    # csrw mtvec, t0

_hang:
    j _hang

.section .bss
_stack_bottom:
.rept 0x4000
    .byte
.endr
_stack_top:
