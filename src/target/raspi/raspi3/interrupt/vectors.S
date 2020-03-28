.include "arch/aarch64/archutils.inc"

.equ INT_FRAME_SIZE, (8 * 36)

.macro kernel_entry, el
    sub sp, sp, #INT_FRAME_SIZE
    stp x0, x1, [sp, #16 * 0]
    stp x2, x3, [sp, #16 * 1]
    stp x4, x5, [sp, #16 * 2]
    stp x6, x7, [sp, #16 * 3]
    stp x8, x9, [sp, #16 * 4]
    stp x10, x11, [sp, #16 * 5]
    stp x12, x13, [sp, #16 * 6]
    stp x14, x15, [sp, #16 * 7]
    stp x16, x17, [sp, #16 * 8]
    stp x18, x19, [sp, #16 * 9]
    stp x20, x21, [sp, #16 * 10]
    stp x22, x23, [sp, #16 * 11]
    stp x24, x25, [sp, #16 * 12]
    stp x26, x27, [sp, #16 * 13]
    stp x28, x29, [sp, #16 * 14]
    .if \el == 0
        mrs x21, sp_el0
    .else
        add x21, sp, #INT_FRAME_SIZE
    .endif
    mrs x22, elr_el1
    mrs x23, spsr_el1
    stp x30, x21, [sp, #8 * 30]
    stp x22, x23, [sp, #8 * 32]
    .if \el == 0
        mvn x21, xzr
        str x21, [sp, #8 * 35]
    .endif
.endm

.macro kernel_exit, el
    ldp x21, x22, [sp, #8 * 32]
    .if \el == 0
        ldr x23, [sp, #8 * 31]
        msr sp_el0, x23
    .endif
    msr elr_el1, x21
    msr spsr_el1, x22
    ldp x0, x1, [sp, #16 * 0]
    ldp x2, x3, [sp, #16 * 1]
    ldp x4, x5, [sp, #16 * 2]
    ldp x6, x7, [sp, #16 * 3]
    ldp x8, x9, [sp, #16 * 4]
    ldp x10, x11, [sp, #16 * 5]
    ldp x12, x13, [sp, #16 * 6]
    ldp x14, x15, [sp, #16 * 7]
    ldp x16, x17, [sp, #16 * 8]
    ldp x18, x19, [sp, #16 * 9]
    ldp x20, x21, [sp, #16 * 10]
    ldp x22, x23, [sp, #16 * 11]
    ldp x24, x25, [sp, #16 * 12]
    ldp x26, x27, [sp, #16 * 13]
    ldp x28, x29, [sp, #16 * 14]
    ldr x30, [sp, #8 * 30]
    add sp, sp, #INT_FRAME_SIZE
    eret
.endm

.macro ventry entry
.balign 0x80
    b \entry
.endm

.globl _vectors
.balign 0x800
_vectors:
    ventry el1_sync_invalid
    ventry el1_irq_invalid
    ventry el1_fiq_invalid
    ventry el1_error_invalid

    ventry el1_sync
    ventry el1_irq
    ventry el1_fiq_invalid
    ventry el1_error_invalid

    ventry el0_sync_invalid
    ventry el0_irq_invalid
    ventry el0_fiq_invalid
    ventry el0_error_invalid

    ventry el0_sync_invalid
    ventry el0_irq_invalid
    ventry el0_fiq_invalid
    ventry el0_error_invalid

.align 6
el1_sync:
    kernel_entry 1
    mov x0, sp
    // bl arm64_sync_exception
    kernel_exit 1

.align 6
el1_irq:
    kernel_entry 1
    msr daifclr, #8
    mov x0, sp
    // bl arm64_irq_exception
    kernel_exit 1

.macro inv_entry, el, reason
    kernel_entry el
    mov x0, sp
    mov x1, #\reason
    mrs x2, esr_el1
    // bl arm64_invalid_exception
    kernel_exit el
.endm

el1_sync_invalid:
    inv_entry 1, 0

el1_irq_invalid:
    inv_entry 1, 1

el1_fiq_invalid:
    inv_entry 1, 2

el1_error_invalid:
    inv_entry 1, 3

el0_sync_invalid:
    inv_entry 0, 0

el0_irq_invalid:
    inv_entry 0, 1

el0_fiq_invalid:
    inv_entry 0, 2

el0_error_invalid:
    inv_entry 0, 3


.globl vectors_init
vectors_init:
    adr x0, _vectors
    msr vbar_el1, x0
    ret
