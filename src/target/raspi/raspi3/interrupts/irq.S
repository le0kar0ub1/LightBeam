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
