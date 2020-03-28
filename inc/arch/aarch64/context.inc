#ifndef __CONTEXT_INC_
#define __CONTEXT_INC_

.macro contextSave
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

    // /* Save the SPSR. */
    // mrs     x3, SPSR_EL1
    // mrs     x2, ELR_EL1
    // stp     x2, x3, [sp, #-0x10]!
    // /* Fetch core Id and multiply x8 as an offset */
    // mrs     x1, MPIDR_EL1
    // and     x1, x1, #0x3
    // lsl     x1, x1, #3
    // /* Fetch current task stack top and add core id offset */
    // ldr     x0, =cpuBlockPtr
    // add     x0, x0, x1
    // ldr     x1, [X0]
    // ldr     x1, [X1]
    // /* Save FPU registers if task has FPU use flag set in pxflags */
    // ldr     x3, [x1, #8]            // Load pxFlags
    // cmp     x3, #0x0
    // bge     contextSaveNoFpu
    // stp     q0, q1, [sp,#-0x20]!
    // stp     q2, q3, [sp,#-0x20]!
    // stp     q4, q5, [sp,#-0x20]!
    // stp     q6, q7, [sp,#-0x20]!
    // stp     q8, q9, [sp,#-0x20]!
    // stp     q10, q11, [sp,#-0x20]!
    // stp     q12, q13, [sp,#-0x20]!
    // stp     q14, q15, [sp,#-0x20]!
    // stp     q16, q17, [sp,#-0x20]!
    // stp     q18, q19, [sp,#-0x20]!
    // stp     q20, q21, [sp,#-0x20]!
    // stp     q22, q23, [sp,#-0x20]!
    // stp     q24, q25, [sp,#-0x20]!
    // stp     q26, q27, [sp,#-0x20]!
    // stp     q28, q29, [sp,#-0x20]!
    // stp     q30, q31, [sp,#-0x20]!
contextSaveNoFpu:
    // /* Now save the new sp value as core RPi_CurrentTaskStackTop */
    // mov     x0, sp   /* Move sp into x0 for saving. */
    // str     x0, [X1]
.endm

.macro contextRestore
    // /* Fetch core Id and multiply x8 as an offset */
    // mrs     x1, MPIDR_EL1
    // and     x1, x1, #0x3
    // lsl     x1, x1, #0x3
    // /* Set the sp to point to the stack of the task being restored. */
    // ldr     x0, =cpuBlockPtr
    // add     x0, x0, x1
    // ldr     x1, [X0]
    // ldr     x1, [X1]
    // ldr     x0, [X1]
    // mov     sp, x0
    // /* Restore FPU registers if task has FPU use flag set in pxflags */
    // ldr     x3, [X1, #8]            // Load pxFlags
    // cmp     x3, 0
    // bge     contextRestoreNoFpu
    // ldp     q30, q31, [sp], #0x20
    // ldp     q28, q29, [sp], #0x20
    // ldp     q26, q27, [sp], #0x20
    // ldp     q24, q25, [sp], #0x20
    // ldp     q22, q23, [sp], #0x20
    // ldp     q20, q21, [sp], #0x20
    // ldp     q18, q19, [sp], #0x20
    // ldp     q16, q17, [sp], #0x20
    // ldp     q14, q15, [sp], #0x20
    // ldp     q12, q13, [sp], #0x20
    // ldp     q10, q11, [sp], #0x20
    // ldp     q8, q9, [sp], #0x20
    // ldp     q6, q7, [sp], #0x20
    // ldp     q4, q5, [sp], #0x20
    // ldp     q2, q3, [sp], #0x20
    // ldp     q0, q1, [sp], #0x20
contextRestoreNoFpu:
    // ldp     x2, x3, [sp], #0x10  /* SPSR and ELR. */
    // /* Restore the SPSR. */
    // msr     SPSR_EL1, x3
    // /* Restore the ELR. */
    // msr     ELR_EL1, x2

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

    eret
.endm

#endif
