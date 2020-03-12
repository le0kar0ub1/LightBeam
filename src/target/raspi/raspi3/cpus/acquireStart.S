.global multicore_init
.global multicoresX_start

.equ COM_CPU1, 0xE0
.equ COM_CPU2, 0xE8
.equ COM_CPU3, 0xF0

.section .text
/* CPU 0 come here and then chek if other are alive */
multicore_init:
    ldr x0, =_BRINGUPCORES
    bl uart_kprint

    mov x1, #COM_CPU1
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu1:
    ldr x3, =cpustate
    ldr x1, [x3]
    and x1, x1, 0b10
    cmp x1, 0
    beq .hang_cpu1
    ldr x0, =CPU1_ACQUIRE_START
    bl uart_kprint

    mov x1, #COM_CPU2
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu2:
    ldr x3, =cpustate
    ldr x1, [x3]
    and x1, x1, 0b100
    cmp x1, 0
    beq .hang_cpu2

    ldr x0, =CPU2_ACQUIRE_START
    bl uart_kprint

    mov x1, #COM_CPU3
    mov x2, #0x80000
    str x2, [x1]
    dc civac, x1
    ic ivau, x1
    sev
.hang_cpu3:
    ldr x3, =cpustate
    ldr x1, [x3]
    and x1, x1, 0b1000
    cmp x1, 0
    beq .hang_cpu3

    ldr x0, =CPU3_ACQUIRE_START
    bl uart_kprint

    ldr x0, =_CHECKEDUP
    bl uart_kprint

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
    bl cpu_getid
    mov x1, 1
    lsl x0, x1, x0
    ldr x1, =cpustate
    ldr x3, [x1]
    orr x0, x0, x3
    str x0, [x1]

    b cpu_warbase

.section .data
cpustate: .int 0
