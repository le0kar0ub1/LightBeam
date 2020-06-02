.section .text

.global arch_cpu_get_id

arch_cpu_get_id:
    csrr a0, mhartid
    ret
