.include "arch/aarch64/context.inc"
.include "arch/aarch64/archutils.inc"

.extern __deadloop

.global irq_handler_stub

.section .text
.balign 4
irq_handler_stub:
    mrs     x3, SPSR_EL1
    mrs     x2, ELR_EL1
    stp     x2, x3, [sp, #-0x10]!

    // mov x1, sp                                          // Fetch sp
    // and x1, x1, #0xF                                    // Ensure 16-byte stack alignment
    // sub sp, sp, x1                                      // adjust stack as necessary
    // stp x1, xzr, [sp, #-16]!                            // Store adjustment

    bl arm64_irq_exception                                 // Timer tick ISR

    // ldp x1, xzr, [sp], #16                              // Reload adjustment
    // add sp, sp, x1                                      // Un-adjust stack

    ldp     x2, x3, [sp], #0x10  /* SPSR and ELR. */
    msr     SPSR_EL1, x3
    msr     ELR_EL1, x2
    ret

    /* should never come here */
    b __deadloop

.section .text
.global EL0_TimerIrqSetup
.balign 4
EL0_TimerIrqSetup:
    mov   x2, #0x40000000                 // QA7 start address
    mrs   x0, MPIDR_EL1                   // Fetch core ID
    and   x0, x0, #0x3                    // Create core id mask
    lsl   x0, x0, #2                      // Multiply x4 for pointer offset
    add   x3, x0, x2                      // x3 = QA7 register address 
    mov   w1, #0x1                 // x1 = divisor of 0x80000000
    lsl   w1, w1, #31
    str   w1, [x3, #8]                    // QA7 prescaler = 0x80000000
    ldr   w2, [x3, #60]                   // Read Core? timer Interrupt control 
    orr   w2, w2, #2                      // nCNTPNSIRQ IRQ enable on core
    str   w2, [x3, #60]                   // Write Core? timer Interrupt control

    mov   x0, #1                          // Return true
    msr   CNTP_CTL_EL0, x0                // Enable EL0 timer
    ret

.global enableEL0timer
enableEL0timer:
    //mov x0, #10000
    //lsl x0, x0, #20
    //msr CNTFRQ_EL0, x0
    mov x0, #1
    msr   CNTP_CTL_EL0, x0                // Enable EL0 timer
    ret

.global getTimerPhysicalFreq
getTimerPhysicalFreq:
    mrs x0, CNTFRQ_EL0
    ret
