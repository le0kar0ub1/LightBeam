.global semaphore_inc
.global semaphore_dec
.global semaphore_unfatal_inc

/*
** http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0489c/CIHGHHIE.html 
*/

.section .text

/* FATAL LOCK */
.balign 4
semaphore_inc:
    // mrs x2, mpidr_el1
    // and x2, x2, #0x3
    // add x2, x2, #1 // else core0 acquire always well :)
    // ldaxr w1, [x0]
    // cmp w1, w2
    // beq .deadlock
    mov w2, 1
.lockit:
    ldaxr w1, [x0]
    stxr  w3, w2, [x0]
    cbnz  w3, .lockit
    cbnz  w1, .lockit
    dmb   ish
    ret

/* UNFATAL LOCK */
.balign 4
semaphore_unfatal_inc:
    mov   w2, 1
    ldaxr w1, [x0]
    stxr  w3, w2, [x0]
    dmb   ish
    cbnz  w3, .errlock
    cbnz  w1, .errlock
    mov x0, 1
    ret
.errlock:
    mov x0, 0
    ret

/* UNLOCK */
.balign 4
semaphore_dec:
    stlrb wzr, [x0]
    dmb   ish
    ret


/* DEADLOCK */
.align 4
.deadlock:
    ldr x0, =dataDeadlock
    b PANIC
    b __deadloop

.section .data
dataDeadlock: .string "Physical Deadlock occured, throw your cpu in the trash."
