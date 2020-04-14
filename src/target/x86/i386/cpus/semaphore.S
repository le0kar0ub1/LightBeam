.code32

.section .text

.global semaphore_inc

semaphore_inc:
    pushl %ebp
    movl  %esp, %ebp

    pushl %eax
    pushl %esi

    movl 0x8(%ebp), %esi

.lockit:
    movl (%esi), %eax
    cmpl $0x0, %eax
    jne .lockit

    incl (%esi)
    
    popl %esi
    popl %eax

    addl $0x4, %esp

    popl %ebp

    ret

.global semaphore_dec

semaphore_dec:
    pushl %ebp
    movl  %esp, %ebp

    pushl %esi

    movl 0x8(%ebp), %esi
    movl $0x0, (%esi)

    popl %esi

    addl $0x4, %esp

    popl %ebp

    ret
