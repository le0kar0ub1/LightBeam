.code16

.global pm32entry

.section .text.boot, "ax"

pm32entry:
    popl %ecx

    cli

    movl %cr0, %eax
    orb  $0x01, %al
    movl %eax, %cr0

    movw  $0x10, %ax
    movw  %ax, %ds
    movw  %ax, %es
    movw  %ax, %ss
    movw  %ax, %fs
    movw  %ax, %gs

    ljmpl $0x08, $pm_entry

    .code32
pm_entry:
    jmp *%ecx
