.include "arch/aarch64/archutils.inc"
.include "target/raspi/raspi3/cpus/cpus.inc"

.global cpu_warbase
.global cpuScheduler

.extern lfb_cpu_log

.extern _cpustate

.section .text
.balign 4
cpu_warbase:
    ldr x0, =_cpustart
    bl lfb_cpu_log
    b cpuScheduler

.section .data
_cpustart: .string "started"

.section .text
.balign 4
cpuScheduler:
    wfe

    ldr x5, =_cpuroutine
    mrs x6, MPIDR_EL1
    and x6, x6, #0x3

    /* Yes, if cpu0 is here, we are grave in the shit */
    cmp x6, #0
    beq cpuScheduler

    mov x7, #0x8
    mul x6, x6, x7

    ldr x4, [x5, x6]
    cmp x4, #0
    beq cpuScheduler

    mov x7, #0
    str x7, [x5, x6] // clear the called routine

    ldr x30, =cpuScheduler // Set link register
    blr x4 // call the routine

    /* UNREACHABLE */
    b cpuScheduler


.global _cpuroutine
.section .data
/* CPUS Routines entry point */
 _cpuroutine:
     __cpu0Routine: .quad 0
     __cpu1Routine: .quad 0
     __cpu2Routine: .quad 0
     __cpu3Routine: .quad 0

    ._cpureturn:
        __cpu0Return: .byte 0
        __cpu1Return: .byte 0
        __cpu2Return: .byte 0
        __cpu3Return: .byte 0


.section .text
.global cpu_getReadyOne
.balign 4
cpu_getReadyOne:
    prologue

    

    epilogue
    ret
