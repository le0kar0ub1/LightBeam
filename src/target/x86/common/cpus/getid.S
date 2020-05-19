.code32

.section .text

.global cpuGetId

cpuGetId:
    movl $0x0, %eax
    ret
