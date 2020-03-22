.global semaphore_inc
.global semaphore_dec
.global unfatal_smp_lock

/*
** http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0489c/CIHGHHIE.html 
*/

.section .text

/* FATAL LOCK */
.align 4
semaphore_inc:
    mov w2, 1
.lockit:
    ldaxr w1, [x0]
    stxr  w3, w2, [x0]
    cbnz  w3, .lockit
    cbnz  w1, .lockit
    dmb   ish
    ret

/* UNFATAL LOCK */
.align 4
unfatal_smp_lock:
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
.align 4
semaphore_dec:
    stlrb wzr, [x0]
    dmb   ish
    ret
