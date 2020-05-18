.code32

.section .text

.global early_vgaputs

early_vgaputs:
    push %edi
    push %eax
    mov $0xb8000, %edi

    .vgaputs_loop:
        movb (%esi), %al
        cmp $0x0, %al
        je end_vgaputs
        movb $0x4F, 1(%edi)
        movb %al, (%edi)
        inc %esi
        add $0x2, %edi
        jmp .vgaputs_loop
    end_vgaputs:

    pop %eax
    pop %edi
    ret
