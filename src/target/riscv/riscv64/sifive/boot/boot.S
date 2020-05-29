.global _start

.extern _vectors
.extern __bss_start
.extern __bss_size
.extern __bss_end

.section .init.text, "ax"

_start:
    _hang: j _hang
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
    la a3, lucky_hart
    li a2, 1
    amoadd.w a3, a2, (a3)
    bnez a3, .XcoreStartup

    /* Clear BSS for flat non-ELF images */
    la a3, __bss_start
    la a4, __bss_end
    ble a4, a3, clear_bss_end
clear_bss:
    sw zero, (a3)
    add a3, a3, 8
    blt a3, a4, clear_bss
clear_bss_end:

    /* Save hart ID and DTB physical address */
    # mv s0, a0
    # mv s1, a1
    # la a2, boot_cpu_hartid
    # sw a0, (a2)

.XcoreStartup:
    j .XcoreStartup