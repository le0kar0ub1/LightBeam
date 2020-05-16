.global _start

.org 0x0

boot_vector:
    j _start

.section .text

_start:
    j _start
