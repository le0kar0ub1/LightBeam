.global __detect__

.equ RASPI1_MAGIC, 0xB76
.equ RASPI2_MAGIC, 0xC07
.equ RASPI3_MAGIC, 0xD03
.equ RASPI4_MAGIC, 0xD08

.equ RASPI1_MMIOBASE, 0x20000000
.equ RASPI2_MMIOBASE, 0x3F000000
.equ RASPI3_MMIOBASE, 0x3F000000
.equ RASPI4_MMIOBASE, 0xFE000000

.text

    mrs x9, midr_el1
.endif
    lsr x9, x9, 4
    and x9, x9, 0xFFF
    mov x0, 0 // MMIOBASE

    mov x0, RASPI1_MMIOBASE
    mov x1, RASPI1_NAME
    cmp x9, RASPI1_MAGIC
    beq _detected

    mov x0, RASPI2_MMIOBASE
    mov x1, RASPI1_NAME
    cmp x9, RASPI2_MAGIC
    beq _detected

    mov x0, RASPI3_MMIOBASE
    mov x1, RASPI1_NAME
    cmp x9, RASPI3_MAGIC
    beq _detected

    mov x0, RASPI4_MMIOBASE
    mov x1, RASPI1_NAME
    cmp x9, RASPI4_MAGIC
    beq _detected

_detected:
    ret

.data

RASPI1_NAME: .asciz "RASPI1"
RASPI2_NAME: .asciz "RASPI2"
RASPI3_NAME: .asciz "RASPI3"
RASPI4_NAME: .asciz "RASPI4"
