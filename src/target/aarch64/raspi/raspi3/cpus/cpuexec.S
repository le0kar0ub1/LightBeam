.include "arch/aarch64/archutils.inc"
.include "target/aarch64/raspi/raspi3/cpus/cpus.inc"

.global cpuExecRoutine

.section .text

.extern _cpustate
.extern _cpuroutine

/* bool cpuExecRoutine(u8_t core, void (*func)(void)) */
.balign 4
cpuExecRoutine:
    prologue

    ldr x2, =_cpustate
    add x2, x2, x0
    
    ldr x2, [x2]
    and x2, x2, #1

    cmp x2, #CPU_IS_WORKING
    beq CoreExecuteFail

    ldr x3, =_cpuroutine
    mov x2, #8
    mul x2, x0, x2

    str x1, [x3, x2] // the function to call

    /* We must set the cpu as in work in the caller else if shit will happens */
    .setCpuIsWorking:
        ldr x2, =_cpustate
        add x2, x2, x0

        ldrb w3, [x2]
        and w3, w3, #0b11111111111111111111111111111110
        strb w3, [x2]

    sev // wakeup our cpus

    mov x0, #1 
    epilogue
    ret

CoreExecuteFail:
    mov x0, #0
    epilogue
    ret
