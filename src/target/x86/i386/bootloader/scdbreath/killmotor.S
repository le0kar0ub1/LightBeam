.global kill_motor

.section .text.boot, "ax"
kill_motor:
    pushw %dx
    movw $0x3f2, %dx
    movb $0x0, %al
    outb %al, %dx
    popw %dx
    ret
