.section .text

.globl put32
put32:
    str w1,[x0]
    ret

.globl get32
get32:
    ldr w0,[x0]
    ret

.globl cycle_delay
cycle_delay:
    cmp x0, #0
    bne cycle_delay
    subs x0, x0, #1
    nop
    ret

.globl get_el
get_el:
    mrs x0, CurrentEL
    lsr x0, x0, #2
    ret
