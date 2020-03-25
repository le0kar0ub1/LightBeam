.include "arch/aarch64/context.inc"
.include "arch/aarch64/archutils.inc"

.extern __deadloop

.global irq_handler_stub

.section .text
.balign 4
irq_handler_stub:
    stp     x0, x1, [sp, #-0x10]!
    stp     x2, x3, [sp, #-0x10]!
    stp     x4, x5, [sp, #-0x10]!
    stp     x6, x7, [sp, #-0x10]!
    stp     x8, x9, [sp, #-0x10]!
    stp     x10, x11, [sp, #-0x10]!
    stp     x12, x13, [sp, #-0x10]!
    stp     x14, x15, [sp, #-0x10]!
    stp     x16, x17, [sp, #-0x10]!
    stp     x18, x19, [sp, #-0x10]!
    stp     x20, x21, [sp, #-0x10]!
    stp     x22, x23, [sp, #-0x10]!
    stp     x24, x25, [sp, #-0x10]!
    stp     x26, x27, [sp, #-0x10]!
    stp     x28, x29, [sp, #-0x10]!
    stp     x30, XZR, [sp, #-0x10]!

    mrs     x3, SPSR_EL1
    mrs     x2, ELR_EL1
    stp     x2, x3, [sp, #-0x10]!

    // mov x1, sp                                          // Fetch sp
    // and x1, x1, #0xF                                    // Ensure 16-byte stack alignment
    // sub sp, sp, x1                                      // adjust stack as necessary
    // stp x1, xzr, [sp, #-16]!                            // Store adjustment

    bl handle_irq                                       // Timer tick ISR

    // ldp x1, xzr, [sp], #16                              // Reload adjustment
    // add sp, sp, x1                                      // Un-adjust stack

    ldp     x2, x3, [sp], #0x10  /* SPSR and ELR. */
    msr     SPSR_EL1, x3
    msr     ELR_EL1, x2

    ldp     x30, XZR, [sp], #0x10
    ldp     x28, x29, [sp], #0x10
    ldp     x26, x27, [sp], #0x10
    ldp     x24, x25, [sp], #0x10
    ldp     x22, x23, [sp], #0x10
    ldp     x20, x21, [sp], #0x10
    ldp     x18, x19, [sp], #0x10
    ldp     x16, x17, [sp], #0x10
    ldp     x14, x15, [sp], #0x10
    ldp     x12, x13, [sp], #0x10
    ldp     x10, x11, [sp], #0x10
    ldp     x8, x9, [sp], #0x10
    ldp     x6, x7, [sp], #0x10
    ldp     x4, x5, [sp], #0x10
    ldp     x2, x3, [sp], #0x10
    ldp     x0, x1, [sp], #0x10

    ldr x0, =debug
    bl uart_kprint

    eret

    /* should never come here */
    b __deadloop

.section .data
debug: .string "out ma boy\n"

.section .text
.global EL0_TimerIrqSetup
.balign 4
EL0_TimerIrqSetup:
    mov   x2, #0x40000000                 // QA7 start address
    mrs   x0, MPIDR_EL1                   // Fetch core ID
    and   x0, x0, #0x3                    // Create core id mask
    lsl   x0, x0, #2                      // Multiply x4 for pointer offset
    add   x3, x0, x2                      // x3 = QA7 register address 
    mov   w1, #0x80000000                 // x1 = divisor of 0x80000000
    str   w1, [x3, #8]                    // QA7 prescaler = 0x80000000
    ldr   w2, [x3, #64]                   // Read Core? timer Interrupt control 
    orr   w2, w2, #2                      // nCNTPNSIRQ IRQ enable on core
    str   w2, [x3, #64]                   // Write Core? timer Interrupt control
    mov   x0, #1                          // Return true
    msr   CNTP_CTL_EL0, x0                // Enable EL0 timer
    ret
