.global cpu_getid

.section .text

cpu_getid:
    mrs x1, mpidr_el1
    and x0, x1, #0x3
    ret
