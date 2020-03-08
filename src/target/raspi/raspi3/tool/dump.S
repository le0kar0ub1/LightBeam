.global processor_dump

.section .data

processor_dump:
    ldr x0, =__sp_dump
    bl uart_puts
    mov x0, sp
    bl uart_hex

    ret


.section .rodata

retline:     .string "\n"

__sp_dump:   .string "    SP: "
