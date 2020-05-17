.include "arch/aarch64/archutils.inc"
.include "target/arm/raspi/raspi3/cpus/cpus.inc"

.extern _cpustate

.global cpuGetState

.section .text
.balign 4
/* bool cpuGetState(u8_t cpuid) */
cpuGetState:
    prologue

    ldr x1, =_cpustate
    add x1, x1, x0
    
    ldr x1, [x1]
    and x1, x1, #1

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
_cpustate: .4byte 0
