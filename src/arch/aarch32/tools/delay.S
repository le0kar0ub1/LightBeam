.global delay

.equ DELAY, 0x80000

.section .text

delay:
        ldr r2, =DELAY

.delay:
        subs r2, r2, #1
        bne .delay
        bx lr
