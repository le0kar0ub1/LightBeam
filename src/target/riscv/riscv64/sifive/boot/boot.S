.global _start

.extern _vectorisr
.extern __bss_start
.extern __bss_size
.extern __bss_end

.section .init.text, "ax"

_start:
    la t0, _vectorisr
    csrw mtvec, t0
    csrwi mstatus, 0
    csrwi mie, 0

    li  x1, 0
    li  x2, 0
    li  x3, 0
    li  x4, 0
    li  x5, 0
    li  x6, 0
    li  x7, 0
    li  x8, 0
    li  x9, 0
    # save a0 and a1; arguments from previous boot loader stage:
    # li  x10,0
    # li  x11,0
    li x12, 0
    li x13, 0
    li x14, 0
    li x15, 0
    li x16, 0
    li x17, 0
    li x18, 0
    li x19, 0
    li x20, 0
    li x21, 0
    li x22, 0
    li x23, 0
    li x24, 0
    li x25, 0
    li x26, 0
    li x27, 0
    li x28, 0
    li x29, 0
    li x30, 0
    li x31, 0

    /* Clear BSS for flat non-ELF images */
    la a3, __bss_start
    la a4, __bss_end
    ble a4, a3, clear_bss_end
clear_bss:
    sw zero, (a3)
    add a3, a3, 8
    blt a3, a4, clear_bss
clear_bss_end:

    j clear_bss_end
