.code16
.section .text.boot, "ax"

.global memcpy
.type memcpy, @function
memcpy:
    pushl   %ebp
    movl    %esp, %ebp

    pushl   %esi
    pushl   %edi
    pushl   %ecx

    movl    0x10(%ebp), %ecx
    movl    0x0c(%ebp), %esi
    movl    0x08(%ebp), %edi

    cld

    .byte 0xf3, 0x67, 0xa4

    popl    %ecx
    popl    %edi
    popl    %esi

    popl    %ebp
    retl
.size memcpy, .-memcpy


.global memset
.type memset, @function
memset:
    pushl   %ebp
    movl    %esp, %ebp

    pushl   %eax
    pushl   %edi
    pushl   %ecx

    movl    0x10(%ebp), %ecx
    movl    0x0c(%ebp), %eax
    movl    0x08(%ebp), %edi

    cld

    .byte 0xf3, 0x67, 0xaa # Clang support

    popl    %ecx
    popl    %edi
    popl    %eax

    popl    %ebp
    retl
.size memset, .-memset
