.include "arch/aarch64/archutils.inc"
.include "target/raspi/raspi3/cpus/cpus.inc"

.global cpuExecRoutine

.section .text

.extern _cpustate

.extern _cpuroutine

/* bool cpuExecRoutine(uint8 core, void (*func)(void)) */
.balign 4
cpuExecRoutine:
    prologue

    ldr x2, =_cpustate
    ldr x2, [x2]
    mov x3, #0x1
    lsl x3, x3, x0
    and x2, x3, x2
    cmp x2, #CPU_IS_WORKING
    beq CoreExecuteFail

    ldr x3, =_cpuroutine
    mov x2, #8
    mul x2, x0, x2

    str x1, [x3, x2] // the function to call

    /* We must set the cpu as in work in the caller else if shit will happens */
    .setCpuIsWorking:
        mov x3, #0x1
        lsl x1, x3, x0

        ldr x4, =_cpustate
        ldr x3, [x4]

        mov x2, #0b11111111
        sub x1, x2, x1 

        and x3, x3, x1
        str x3, [x4]

    sev // wakeup our cpus

    mov x0, #1 
    epilogue
    ret

CoreExecuteFail:
    mov x0, #0
    epilogue
    ret
