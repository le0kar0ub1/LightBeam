.global _start

.include "target/riscv/riscv64/sifive/boot.inc"

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
        sd zero, (a3)
        add a3, a3, 8
        blt a3, a4, clear_bss
    clear_bss_end:

    # cpu get id and dichotomy
    csrr a0, mhartid
    li a3, 0
    bgt a0, a3, coreXBoot
    j core0boot

coreXBoot:
    # Set MSIE bit to receive IPI
    li a2, MIP_MSIP
    csrw mie, a2
    .coreXwait:
        wfi
        # Only start if MIP_MSIP is set
        csrr a2, mip
        andi a2, a2, MIP_MSIP
        beqz a2, .coreXwait

        li s1, 0x02000000 # CLINT addr
        csrr s2, mhartid
        slli s2, s2, 2
        add s2, s2, s1
        sw zero, 0(s2)
        fence
        csrw mip, 0
        li a2, 5
        bltu a0, a2, .coreXtriggered
        j .coreXwait

.coreXtriggered:
    # stack setup
    csrr a0, mhartid
    addi a0, a0, 1
    la a1, __STACK_SIZE
    mul a0, a0, a1
    la sp, __stackcore__
    add sp, sp, a0
    j xinit

core0boot:
    # stack setup
    la sp, __stackcore__
    la a1, __STACK_SIZE
    add sp, sp, a1
    j kmain
