.global _init_stacks

.section .text

_init_stacks:
    mrs x1, mpidr_el1
    and x1, x1, #0x3
    cmp x1, #0
    beq Core0StackPointers
    cmp x1, #1
    beq Core1StackPointers
    cmp x1, #2
    beq Core2StackPointers
    cmp x1, #3
    beq Core3StackPointers
    b   __hang

Core1StackPointers:
    ldr x1, =__EL0_stack_core1
    ldr x2, =__EL1_stack_core1
    ldr x3, =__EL2_stack_core1
    msr sp_el0, x1
    msr sp_el1, x2
    mov sp, x3
    b   cpus_el1back

Core2StackPointers:
    ldr x1, =__EL0_stack_core2
    ldr x2, =__EL1_stack_core2
    ldr x3, =__EL2_stack_core2
    msr sp_el0, x1
    msr sp_el1, x2
    mov sp, x3
    b   cpus_el1back

Core3StackPointers:
    ldr x1, =__EL0_stack_core3
    ldr x2, =__EL1_stack_core3
    ldr x3, =__EL2_stack_core3
    msr sp_el0, x1
    msr sp_el1, x2
    mov sp, x3
    b   cpus_el1back

Core0StackPointers:
    ldr x1, =__EL0_stack_core0
    ldr x2, =__EL1_stack_core0
    ldr x3, =__EL2_stack_core0
    msr sp_el0, x1
    msr sp_el1, x2
    mov sp, x3
    b   cpus_el1back

cpus_el1back:
    mov x0, #0x3c5          // EL1_SP1 | D | A | I | F
    msr spsr_el2, x0        // Set spsr_el2 with settings
    adr x0, cpus_hookpoint  // Address to exit EL2
    msr elr_el2, x0         // Set elevated return register
    eret                    // Call elevated return