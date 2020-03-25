.include "arch/aarch64/context.inc"

.extern __deadloop

.global irq_handler_stub

.section .text
.balign 4
irq_handler_stub:
    contextSave                                         // Save current task context

    mov x1, sp                                          // Fetch sp
    and x1, x1, #0xF                                    // Ensure 16-byte stack alignment
    sub sp, sp, x1                                      // adjust stack as necessary
    stp x1, xzr, [sp, #-16]!                            // Store adjustment

    bl handle_irq                                       // Timer tick ISR

    ldp x1, xzr, [sp], #16                              // Reload adjustment
    add sp, sp, x1                                      // Un-adjust stack

    contextRestore                                      // Restore new current task context and return

    b __deadloop
