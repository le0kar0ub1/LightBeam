.global cpu_getid

.include "arch/aarch64/archutils.inc"

.section .text

cpu_getid:
    prologue
    mrs x1, mpidr_el1
    and x0, x1, #0x3
    epilogue
    ret
