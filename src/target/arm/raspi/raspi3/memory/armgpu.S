.section .text

.global ARMToGPU
.global GPUToARM

.balign 4
ARMToGPU:
    mov x1, #0xC0000000
    orr x0, x0, x1
    ret

.balign 4
GPUToARM:
    mov x1, ~0xC0000000
    and x0, x0, x1
    ret
