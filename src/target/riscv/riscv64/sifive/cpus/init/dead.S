.global __deadloop
.global __hang
.global __scratch

.section .text

__deadloop:
    wfi
    j __deadloop

__hang:
    j __hang

__scratch:
    .4byte 0
