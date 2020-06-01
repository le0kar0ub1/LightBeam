.section .text

.global cpuGetId

cpuGetId:
    csrr a0, mhartid
    ret
