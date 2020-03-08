.globl _start

/* unused at time */
.section .init
b _start

.section .text.boot

_start:
    // read cpu id, stop slave cores
    mrs     x1, mpidr_el1
    and     x1, x1, #3
    cbz     x1, 2f

1:
    wfe
    b       1b

2:
    // set stack before our code (then we got from 0 to ENTRYPOINT stack size)
    ldr     x1, =_start
    mov     sp, x1

    bl _setup

    // clear bss
    ldr     x1, =__bss_start
    ldr     w2, =__bss_size
3:
    cbz     w2, 4f
    str     xzr, [x1], #8
    sub     w2, w2, #1
    cbnz    w2, 3b

4:
    bl      init_hook

    /* UNREACHEABLE */
    b       1b


/* generate fault from scratch (u can do it?) */
.globl fault
fault: