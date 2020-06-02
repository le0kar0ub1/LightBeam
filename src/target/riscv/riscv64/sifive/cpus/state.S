.section .text

.global cpuGetState

cpuGetState:
    csrr a0, mhartid
    la a1, cpuStateData
    add a1, a1, a0
    lb a0, a1
    ret

.global cpuSetState
    csrr a0, mhartid
    la a1, cpuStateData
    add a1, a1, a0
    sb a0, a1
    ret

.section .data

.global cpuStateData

cpuStateData:
.rept 5
    .byte 0x0
.endr
