.global _start

.org 0x0

.section .hellboot, "ax"

boot_vector:
    j _start

.section .init.text, "ax", @progbits

_start:
    j _start
    xor a0, a0, a0
    addi a0, a0, 10
    j _start
