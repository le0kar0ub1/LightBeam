.section .text

.global cpuGetId

cpuGetId:
    csrr x2, mhartid
    ret
