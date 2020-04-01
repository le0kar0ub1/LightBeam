.globl membarrier

.section .text

membarrier:
    mcr p15, #0, ip, c7, c5, #0    // invalidate I cache
    mcr p15, #0, ip, c7, c5, #6    // invalidate BTB
    mcr p15, #0, ip, c7, c10, #4   // drain write buffer
    mcr p15, #0, ip, c7, c5, #4    // prefetch flush
    mov pc, lr
