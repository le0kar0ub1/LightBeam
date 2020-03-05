.globl _start

.org 0x8000

/* Unused at time, we will change the linker */
.section .init
b _start

.section .text.boot

_start:
    // Shut off extra cores
    mrc p15, #0, r5, c0, c0, #5
    and r5, r5, #3
    cmp r5, #0
    bne halt
 
    // Setup the stack.
    ldr r5, =_start
    mov sp, r5
 
    // Clear out bss.
    ldr r4, =__bss_start
    ldr r9, =__bss_end
    mov r5, #0
    mov r6, #0
    mov r7, #0
    mov r8, #0
    b 2f
 
1:
    // store multiple at r4.
    stmia r4!, {r5-r8}
 
    // If we are still below bss_end, loop.
2:
    cmp r4, r9
    blo 1b
 
    ldr r3, =init_hook
    blx r3
 
 halt:
    wfe
    b halt
