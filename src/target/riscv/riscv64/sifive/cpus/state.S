.section .text

.global cpuGetState

# int cpuGetState(void);
cpuGetState:
    csrr a0, mhartid
    la a1, cpuStateData
    add a1, a1, a0
    lb a0, 0(a1)
    ret

.global cpuSetState

# void cpuSetState(int);
cpuSetState:
    csrr a2, mhartid
    la a1, cpuStateData
    add a1, a1, a2
    sb a0, 0(a1)
    ret

.section .data

cpuStateData:
.rept 5
    .byte 0x0
.endr
