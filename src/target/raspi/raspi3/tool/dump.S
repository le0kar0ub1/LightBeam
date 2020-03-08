.global processor_dump
.global processor_push
.global processor_pop

.section .data

/* Push (alias) all X register */
processor_push:
    str x0,  [sp, #-8]!
    str x1,  [sp, #-8]!
    str x2,  [sp, #-8]!
    str x3,  [sp, #-8]!
    str x4,  [sp, #-8]!
    str x5,  [sp, #-8]!
    str x6,  [sp, #-8]!
    str x7,  [sp, #-8]!
    str x8,  [sp, #-8]!
    str x9,  [sp, #-8]!
    str x10, [sp, #-8]!
    str x11, [sp, #-8]!
    str x12, [sp, #-8]!
    str x13, [sp, #-8]!
    str x14, [sp, #-8]!
    str x15, [sp, #-8]!
    str x16, [sp, #-8]!
    str x17, [sp, #-8]!
    str x18, [sp, #-8]!
    str x19, [sp, #-8]!
    str x20, [sp, #-8]!
    str x21, [sp, #-8]!
    str x22, [sp, #-8]!
    str x23, [sp, #-8]!
    str x24, [sp, #-8]!
    str x25, [sp, #-8]!
    str x26, [sp, #-8]!
    str x27, [sp, #-8]!
    str x28, [sp, #-8]!
    str x29, [sp, #-8]!
    str x30, [sp, #-8]!
    ret

/* Pop (alias) and display all X register */
processor_dump:
    ldr x0, =__procdump
    bl uart_puts

    ldr x0, =__dump_x30
    bl uart_puts
    ldr x30, [sp], #8
    mov x0, x30
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x29
    bl uart_puts
    ldr x29, [sp], #8
    mov x0, x29
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x28
    bl uart_puts
    ldr x28, [sp], #8
    mov x0, x28
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x27
    bl uart_puts
    ldr x27, [sp], #8
    mov x0, x27
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x26
    bl uart_puts
    ldr x26, [sp], #8
    mov x0, x26
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x25
    bl uart_puts
    ldr x25, [sp], #8
    mov x0, x25
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x24
    bl uart_puts
    ldr x24, [sp], #8
    mov x0, x24
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x23
    bl uart_puts
    ldr x23, [sp], #8
    mov x0, x23
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x22
    bl uart_puts
    ldr x22, [sp], #8
    mov x0, x22
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x21
    bl uart_puts
    ldr x21, [sp], #8
    mov x0, x21
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x20
    bl uart_puts
    ldr x20, [sp], #8
    mov x0, x20
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x19
    bl uart_puts
    ldr x19, [sp], #8
    mov x0, x19
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x18
    bl uart_puts
    ldr x18, [sp], #8
    mov x0, x18
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x17
    bl uart_puts
    ldr x17, [sp], #8
    mov x0, x17
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x16
    bl uart_puts
    ldr x16, [sp], #8
    mov x0, x16
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x15
    bl uart_puts
    ldr x15, [sp], #8
    mov x0, x15
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x14
    bl uart_puts
    ldr x14, [sp], #8
    mov x0, x14
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x13
    bl uart_puts
    ldr x13, [sp], #8
    mov x0, x13
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x12
    bl uart_puts
    ldr x12, [sp], #8
    mov x0, x12
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x11
    bl uart_puts
    ldr x11, [sp], #8
    mov x0, x11
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x10
    bl uart_puts
    ldr x10, [sp], #8
    mov x0, x10
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x9
    bl uart_puts
    ldr x9, [sp], #8
    mov x0, x9
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x8
    bl uart_puts
    ldr x8, [sp], #8
    mov x0, x8
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x7
    bl uart_puts
    ldr x7, [sp], #8
    mov x0, x7
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x6
    bl uart_puts
    ldr x6, [sp], #8
    mov x0, x6
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x5
    bl uart_puts
    ldr x5, [sp], #8
    mov x0, x5
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x4
    bl uart_puts
    ldr x4, [sp], #8
    mov x0, x4
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x3
    bl uart_puts
    ldr x3, [sp], #8
    mov x0, x3
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x2
    bl uart_puts
    ldr x2, [sp], #8
    mov x0, x2
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x1
    bl uart_puts
    ldr x1, [sp], #8
    mov x0, x1
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ldr x0, =__dump_x0
    bl uart_puts
    ldr x0, [sp], #8
    mov x0, x0
    bl uart_hex
    ldr x0, =__retline
    bl uart_puts

    ret

/* Pop (alias) all X register */
processor_pop:
    ldr x30, [sp], #8
    ldr x29, [sp], #8
    ldr x28, [sp], #8
    ldr x27, [sp], #8
    ldr x26, [sp], #8
    ldr x25, [sp], #8
    ldr x24, [sp], #8
    ldr x23, [sp], #8
    ldr x22, [sp], #8
    ldr x21, [sp], #8
    ldr x20, [sp], #8
    ldr x19, [sp], #8
    ldr x18, [sp], #8
    ldr x17, [sp], #8
    ldr x16, [sp], #8
    ldr x15, [sp], #8
    ldr x14, [sp], #8
    ldr x13, [sp], #8
    ldr x12, [sp], #8
    ldr x11, [sp], #8
    ldr x10, [sp], #8
    ldr x9,  [sp], #8
    ldr x8,  [sp], #8
    ldr x7,  [sp], #8
    ldr x6,  [sp], #8
    ldr x5,  [sp], #8
    ldr x4,  [sp], #8
    ldr x3,  [sp], #8
    ldr x2,  [sp], #8
    ldr x1,  [sp], #8
    ldr x0,  [sp], #8
    ret

.section .rodata

__procdump: .string "Processor:\n"

__retline:    .string "\n"

__dump_sp:  .string "    SP: "

__dump_x30: .string "    x30: "
__dump_x29: .string "    x29: "
__dump_x28: .string "    x28: "
__dump_x27: .string "    x27: "
__dump_x26: .string "    x26: "
__dump_x25: .string "    x25: "
__dump_x24: .string "    x24: "
__dump_x23: .string "    x23: "
__dump_x22: .string "    x22: "
__dump_x21: .string "    x21: "
__dump_x20: .string "    x20: "
__dump_x19: .string "    x19: "
__dump_x18: .string "    x18: "
__dump_x17: .string "    x17: "
__dump_x16: .string "    x16: "
__dump_x15: .string "    x15: "
__dump_x14: .string "    x14: "
__dump_x13: .string "    x13: "
__dump_x12: .string "    x12: "
__dump_x11: .string "    x11: "
__dump_x10: .string "    x10: "
__dump_x9:  .string "     x9: "
__dump_x8:  .string "     x8: "
__dump_x7:  .string "     x7: "
__dump_x6:  .string "     x6: "
__dump_x5:  .string "     x5: "
__dump_x4:  .string "     x4: "
__dump_x3:  .string "     x3: "
__dump_x2:  .string "     x2: "
__dump_x1:  .string "     x1: "
__dump_x0:  .string "     x0: "