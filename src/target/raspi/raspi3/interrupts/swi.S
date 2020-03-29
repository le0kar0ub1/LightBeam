.include "arch/aarch64/context.inc"

.extern __deadloop

.global swi_handler_stub

.section .text
.balign 4
swi_handler_stub:
    contextSave                                    // Save current task context

    mov X1, SP                                      // Fetch SP
    and X1, X1, #0xF                                // Ensure 16-byte stack alignment
    sub SP, SP, X1                                  // adjust stack as necessary
    stp X1, XZR, [SP, #-16]!                        // Store adjustment 

    mrs X0, MPIDR_EL1                                   // Fetch core ID
    and X0, X0, #0x3                                    // Create core id mask
    // bl  xSchedule                                       // Reschedule .. aka pick new pxCurrentTask

    ldp X1, XZR,  [SP], #16                             // Reload adjustment
    add SP, SP, X1                                      // Un-adjust stack

    contextRestore                                 // Restore new current task context and return

    B __deadloop
