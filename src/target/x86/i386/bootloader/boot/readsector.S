.code16

.global _rdsector
.global _rd_xsectors

.section .bootrdsector, "ax"

_rdsector:
    pushl %eax
    pushl %ebx
    pushl %ecx
    pushl %edx
    pushl %esi
    pushl %edi

    pushw %es
    popw .target_segment
    movw %bx, .target_offset
    movl %eax, .lba_address_low

    xor %esi, %esi
    mov .da_struct, %si
    mov $0x42, %ah

    clc
    int $0x13

  .done:
    popl %edi
    popl %esi
    popl %edx
    popl %ecx
    popl %ebx
    popl %eax
    ret

.balign 4
.da_struct:
    .packet_size:      .byte 16
    .unused:           .byte 0
    .count:            .word 1
    .target_offset:    .word 0
    .target_segment:   .word 0
    .lba_address_low:  .long 0
    .lba_address_high: .long 0

// ********************************************
//     Reads multiple LBA addressed sectors
// ********************************************

// IN:
// EAX = LBA starting sector
// DL = Drive number
// ES = Buffer segment
// EBX = Buffer offset
// ECX = Sectors count

// OUT:
// Carry if error

TEMP_BUFFER_SEG = 0x7000
BYTES_PER_SECT  = 512

_rd_xsectors:
    pushl %eax
    pushl %ebx
    pushl %ecx
    pushl %edx
    pushl %esi
    pushl %edi

  .loop:
    pushl %es
    pushl %ebx

    mov TEMP_BUFFER_SEG, %bx
    movw %bx, %es
    xorw %bx, %bx

    call _rdsector

    pop %ebx
    pop %es

    jc .donex

    push %ds

    mov TEMP_BUFFER_SEG, %si
    movw %si, %ds
    movl %ebx, %edi
    xorl %esi, %esi

    pushl %ecx
    mov BYTES_PER_SECT, %ecx
    rep movsb
    pop %ecx

    pop %ds

    inc %eax
    add BYTES_PER_SECT, %ebx

    loop .loop

  .donex:
    popl %edi
    popl %esi
    popl %edx
    popl %ecx
    popl %ebx
    popl %eax
    ret
