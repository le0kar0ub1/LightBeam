.equ INT_BIT_FIQ,   0b0001
.equ INT_BIT_IRQ,   0b0010
.equ INT_BIT_ABORT, 0b0100
.equ INT_BIT_DEBUG, 0b1000

.section .text
.balign 4
.globl enable_interrupts
enable_interrupts:
    msr daifclr, #INT_BIT_IRQ
    ret

.balign 4
.globl disable_interrupts
disable_interrupts:
    msr daifset, #INT_BIT_IRQ
    ret

.balign 4
.globl enable_fiq
enable_fiq:
    msr daifclr, #INT_BIT_FIQ
    ret

.balign 4
.globl disable_fiq
disable_fiq:
    msr daifset, #INT_BIT_FIQ
    ret

.balign 4
.globl getIntFlags
getIntFlags:
    mrs x0, daif
    ret

.balign 4
.globl setIntFlags
setIntFlags:
    msr daif, x0
    ret
