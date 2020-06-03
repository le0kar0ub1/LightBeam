.global arch_cpu_get_id

.include "arch/aarch64/archutils.inc"

.section .text

arch_cpu_get_id:
    prologue
    mrs x1, mpidr_el1
    and x0, x1, #0x3
    epilogue
    ret
