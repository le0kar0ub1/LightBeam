.section .text

.equ INT_BIT_FIQ,   0b0001
.equ INT_BIT_IRQ,   0b0010
.equ INT_BIT_ABORT, 0b0100
.equ INT_BIT_DEBUG, 0b1000

.globl irq_vector_init

irq_vector_init:
    adr x0, _vectors
    msr vbar_el1, x0
    ret

.globl enable_irq

enable_irq:
    msr daifclr, #INT_BIT_IRQ
    ret

.globl disable_irq

disable_irq:
    msr daifset, #INT_BIT_IRQ
    ret
