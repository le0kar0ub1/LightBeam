.code32

.section .text

.global arch_cpu_get_id

arch_cpu_get_id:
    movl $0x0, %eax
    ret
