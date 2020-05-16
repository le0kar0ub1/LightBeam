.global _start

.section .text

.org 0x0

boot_vector:
    j _start

_start:
    j _start
