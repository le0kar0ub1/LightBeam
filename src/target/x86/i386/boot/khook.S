.global khook

.section .text

khook:
    mov $please, %esi
    call vgadirect

.hang:
    jmp .hang

vgadirect:
    pushl %edi
    pushl %eax
    mov $0xb8000, %edi
    .ploop:
        lodsb
        andb %al, %al
        jz   .endploop
        movw $0x4F, 1(%edi)
        movb %al, (%edi)
        add $0x2, %edi
        jmp .ploop
    .endploop:
        popl %eax
        popl %edi
    ret

__fault:
    mov $0, %ax
    divw %ax, %ax

.section .data
please: .asciz "boot functionnal <3"
