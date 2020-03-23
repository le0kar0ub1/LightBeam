.include "arch/aarch64/archutils.inc"
.include "target/raspi/raspi3/cpus/cpus.inc"

.extern _cpustate

.global cpuGetState

.section .text
/* bool cpuGetState(uint8 cpuid) */
cpuGetState:
    prologue

    mov x1, #0x1
    lsl x1, x1, x0

    ldr x2, =_cpustate
    ldr x2, [x2]

    and x1, x1, x2

    cmp x1, #CPU_IS_SLEEPING
    beq .cpuIsSleeping 

    mov x0, #CPU_IS_WORKING
    epilogue
    ret

.cpuIsSleeping:
    mov x0, #CPU_IS_SLEEPING
    epilogue
    ret

.global _cpustate
.section .data
.balign 4
_cpustate: .byte 0
