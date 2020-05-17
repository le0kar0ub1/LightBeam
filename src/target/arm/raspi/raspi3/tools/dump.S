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
    bl uart_kprint

    ldr x0, =__dump_x30
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x29
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x28
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x27
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x26
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x25
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x24
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x23
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x22
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x21
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x20
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x19
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x18
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x17
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x16
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x15
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x14
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x13
    ldr x11, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x12
    ldr x11, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x11
    ldr x11, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x10
    ldr x11, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x9
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x8
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x7
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x6
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x5
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x4
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x3
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x2
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x1
    ldr x1, [sp], #8
    bl uart_kprint

    ldr x0, =__dump_x0
    ldr x1, [sp], #8
    bl uart_kprint

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

__dump_sp:  .string "     SP: %X\n"

__dump_x30: .string "    x30: %X\n"
__dump_x29: .string "    x29: %X\n"
__dump_x28: .string "    x28: %X\n"
__dump_x27: .string "    x27: %X\n"
__dump_x26: .string "    x26: %X\n"
__dump_x25: .string "    x25: %X\n"
__dump_x24: .string "    x24: %X\n"
__dump_x23: .string "    x23: %X\n"
__dump_x22: .string "    x22: %X\n"
__dump_x21: .string "    x21: %X\n"
__dump_x20: .string "    x20: %X\n"
__dump_x19: .string "    x19: %X\n"
__dump_x18: .string "    x18: %X\n"
__dump_x17: .string "    x17: %X\n"
__dump_x16: .string "    x16: %X\n"
__dump_x15: .string "    x15: %X\n"
__dump_x14: .string "    x14: %X\n"
__dump_x13: .string "    x13: %X\n"
__dump_x12: .string "    x12: %X\n"
__dump_x11: .string "    x11: %X\n"
__dump_x10: .string "    x10: %X\n"
__dump_x9:  .string "     x9: %X\n"
__dump_x8:  .string "     x8: %X\n"
__dump_x7:  .string "     x7: %X\n"
__dump_x6:  .string "     x6: %X\n"
__dump_x5:  .string "     x5: %X\n"
__dump_x4:  .string "     x4: %X\n"
__dump_x3:  .string "     x3: %X\n"
__dump_x2:  .string "     x2: %X\n"
__dump_x1:  .string "     x1: %X\n"
__dump_x0:  .string "     x0: %X\n"
