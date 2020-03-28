.include "arch/aarch64/context.inc"

.extern __deadloop

.global fiq_handler_stub

.section .text
.balign 4
fiq_handler_stub:   
    stp x29, x30, [sp, #-16]!                           // Store frame pointer and Link register
    stp x18, x19,  [sp, #-16]!                          // Save register x18, as C will trash it.. 19 just there as a pair
    stp x16, x17,  [sp, #-16]!                          // Save register x16, x17 as C will trash them
    stp x14, x15,  [sp, #-16]!                          // Save register x14, x15 as C will trash them
    stp x12, x13,  [sp, #-16]!                          // Save register x12, x13 as C will trash them
    stp x10, x11,  [sp, #-16]!                          // Save register x10, x11 as C will trash them
    stp x8, x9,  [sp, #-16]!                            // Save register x8, x9 as C will trash them
    stp x6, x7,  [sp, #-16]!                            // Save register x6, x7 as C will trash them
    stp x4, x5,  [sp, #-16]!                            // Save register x4, x5 as C will trash them
    stp x2, x3,  [sp, #-16]!                            // Save register x2, x3 as C will trash them
    stp x0, x1,  [sp, #-16]!                            // Save register x0, x1 as C will trash them

    mov x1, sp
    and x1, x1, #0xF                                    // Ensure 16-byte stack alignment
    sub sp, sp, x1                                      // adjust stack as necessary
    stp x1, xzr, [sp, #-16]!                            // Store adjustment

    ldr x0, =fiqHandlerAddr                            // Address to FiqFuncAddr
    ldr x0, [x0]                                        // Load FiqFuncAddr value
    cbz x0, no_fiqset                                   // If zero no fiq function set so ignore 
    blr x0                                              // Call Irqhandler that has been set
no_fiqset:

    ldp x1, xzr,  [sp], #16                             // Reload adjustment
    add sp, sp, x1                                      // Un-adjust stack

    ldp x0, x1,  [sp], #16                              // Restore register x0, x1
    ldp x2, x3,  [sp], #16                              // Restore register x2, x3
    ldp x4, x5,  [sp], #16                              // Restore register x4, x5
    ldp x6, x7,  [sp], #16                              // Restore register x6, x7
    ldp x8, x9,  [sp], #16                              // Restore register x8, x9
    ldp x10, x11, [sp], #16                             // Restore register x10, x11
    ldp x12, x13, [sp], #16                             // Restore register x12, x13
    ldp x14, x15, [sp], #16                             // Restore register x14, x15
    ldp x16, x17, [sp], #16                             // Restore register x16, x17
    ldp x18, x19, [sp], #16                             // Restore register x18, x19 
    ldp x29, x30, [sp], #16                             // Restore frame pointer and Link register
    eret

.section .text
.balign 4
.globl setFiqFuncAddress;
setFiqFuncAddress:
    msr daifset, #0x1                       // Disable fiq interrupts as we are clearly changing call
    ldr x1, =fiqHandlerAddr                 // Load address of function to call on interrupt 
    ldr x2, [x1]                            // Load current fiq call address
    str x0, [x1]                            // Store the new function pointer address we were given
    mov x0, x2                              // return the old call function
    ret                                     // Return

.section .data
.balign 8
fiqHandlerAddr : .8byte 0x0
