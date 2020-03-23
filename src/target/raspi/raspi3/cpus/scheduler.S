.global cpu_warbase
.global cpuScheduler

.extern lfb_cpu_log

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

    /* Yes, if core0 is here we are grave in the shit */
    cmp x6, #0
    beq cpuScheduler

    mov x7, #0x8
    mul x6, x6, x7

    ldr x4, [x5, x6]
    cmp x4, #0
    beq cpuScheduler

    mov x7, #0
    str x7, [x5, x6] // clear the called routine

    ldr x30, =cpuScheduler          // Set link register to secondary spin address
    blr x4                          // Call address in x4 
    /* #UNREACHABLE */
    b cpuScheduler


.global _cpuroutine
.section .data
/* CPUS Routines entry point */
_cpuroutine:
    __cpuroutine_core0: .8byte 0
    __cpuroutine_core1: .8byte 0
    __cpuroutine_core2: .8byte 0
    __cpuroutine_core3: .8byte 0
