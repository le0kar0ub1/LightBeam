.include "arch/aarch64/archutils.inc"
.include "target/raspi/raspi3/cpus/cpus.inc"

.global multicore_init
.global multicoresX_start

.extern _cpustate

.equ SPIN_CPU0, 0xD8
.equ SPIN_CPU1, 0xE0
.equ SPIN_CPU2, 0xE8
.equ SPIN_CPU3, 0xF0

.section .text
/* CPU 0 come here and then check if other are alive */
multicore_init:
    prologue

    ldr x0, =_BRINGUPCORES
    bl uart_kprint

    mov x1, #SPIN_CPU1
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu1:
    ldr x3, =_cpustate
    ldr x1, [x3]
    and x1, x1, 0b10
    cmp x1, 0
    beq .hang_cpu1
    ldr x0, =CPU1_ACQUIRE_START
    bl uart_kprint

    mov x1, #SPIN_CPU2
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu2:
    ldr x3, =_cpustate
    ldr x1, [x3]
    and x1, x1, 0b100
    cmp x1, 0
    beq .hang_cpu2

    ldr x0, =CPU2_ACQUIRE_START
    bl uart_kprint

    mov x1, #SPIN_CPU3
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu3:
    ldr x3, =_cpustate
    ldr x1, [x3]
    and x1, x1, 0b1000
    cmp x1, 0
    beq .hang_cpu3

    ldr x0, =CPU3_ACQUIRE_START
    bl uart_kprint

    ldr x0, =_CHECKEDUP
    bl uart_kprint

    epilogue
    ret

.section .data
_BRINGUPCORES:      .string "CPU 0 checking if other are started...\n"
CPU1_ACQUIRE_START: .string "    - CPU 1 acquire start\n"
CPU2_ACQUIRE_START: .string "    - CPU 2 acquire start\n"
CPU3_ACQUIRE_START: .string "    - CPU 3 acquire start\n"
_CHECKEDUP:         .string "All CPUS acquired start.\n"


/* CoresX acquire their are alive here */
.section .text
multicoresX_start:
    bl cpuGetId
    mov x1, #CPU_IS_SLEEPING
    lsl x0, x1, x0
    ldr x1, =_cpustate
    ldr x3, [x1]
    orr x0, x0, x3
    str x0, [x1]

    b cpu_warbase
