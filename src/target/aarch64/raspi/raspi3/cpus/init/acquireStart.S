.include "arch/aarch64/archutils.inc"

.global multicore_init

.equ SPIN_CPU0, 0xD8
.equ SPIN_CPU1, 0xE0
.equ SPIN_CPU2, 0xE8
.equ SPIN_CPU3, 0xF0

.section .text
multicore_init:
    prologue

    mov x1, #SPIN_CPU1
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu1:
    mov x0, #1
    bl cpu_get_state
    cmp x0, 0x0
    beq .hang_cpu1

    ldr x0, =CPU_ACQUIRE_START
    mov x1, #1
    bl rpifb_kprint

    mov x1, #SPIN_CPU2
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu2:
    mov x0, #2
    bl cpu_get_state
    cmp x0, 0x0
    beq .hang_cpu2

    ldr x0, =CPU_ACQUIRE_START
    mov x1, #2
    bl rpifb_kprint

    mov x1, #SPIN_CPU3
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu3:
    mov x0, #3
    bl cpu_get_state
    cmp x0, 0x0
    beq .hang_cpu3

    ldr x0, =CPU_ACQUIRE_START
    mov x1, #3
    bl rpifb_kprint

    epilogue
    ret

.section .data
CPU_ACQUIRE_START: .string "[CPU %d][LOG]: acquired start\n"
