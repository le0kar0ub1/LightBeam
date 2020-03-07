.globl _start

.section .init
b _start

.globl _start
_start:
    mrs x0, mpidr_el1
    and x0, x0, #0xFF    // Check processor id
    cbz x0, master       // Hang for all non-primary CPU
    b   proc_hang


master:
    adr x0, __bss_start
    adr x1, __bss_end
    sub x1, x1, x0
    bl  memzero

    ldr x5, =stack
    mov sp, x5
    bl  init_hook
    b   proc_hang

proc_hang: 
    b proc_hang

.section .bss
.lcomm stack, 0x10000
