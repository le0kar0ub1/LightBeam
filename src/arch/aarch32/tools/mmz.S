.globl mmz

mmz:
    mov r2, #0
    str r2, [r0], #8
    subs r1, r1, #8
    bgt mmz
    bx lr