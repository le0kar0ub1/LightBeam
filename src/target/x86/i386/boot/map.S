.code32

.include "target/x86/shared/boot.inc"

.section .text

.global setup_paging

/*
** Paging Set up
*/

setup_paging:
    /* recursive mapping */
    LV2P $kernel_pagedir, %eax
    orl $0x3, %eax
    SV2P %eax, .kpage_last_entry

    LV2P $kernel_pagetable, %eax
    orl $0x3, %eax
    SV2P %eax, .kpage_kernel_entry

    LV2P $kernel_pagetable, %edi
    xorl %edx, %edx
    movl $0x400, %ecx
.loop_page:
    movl %edx, %eax
    orl $0x3, %eax
    movl %eax, (%edi)
    addl $0x1000, %edx
    addl $0x4, %edi
    loop .loop_page

    LV2P $kernel_pagedir, %eax
    movl %eax, %cr3

    # Big page for now
    movl %cr4, %eax
    orl $0b10000, %eax
    movl %eax, %cr4

    # Paging & protected mode
    movl %cr0, %eax
    orl $0x80000001, %eax
    movl %eax, %cr0

    lea .higher_half, %eax
    jmp *%eax
    .higher_half:

    movl $0x0, .kpage_first_entry

    # flush TLB
    movl %cr3, %eax
    movl %eax, %cr3

    # disable big page
    movl %cr4, %eax
    andl $~0b10000, %eax
    movl %eax, %cr4

    lgdt gdtptr

    # Reload Boot Values
    movl $stack_top, %esp
    subl $0x8, %esp # multiboot structure & caller address pushed

    # reload caller
    popl %eax
    addl $__KERNEL_ADDR_TRNS, %eax
    pushl %eax

    ret

/*
** Early Kernel paging data
*/

.section .data

.global kernel_pagedir
    .global .kpage_first_entry
    .global .kpage_kernel_entry
    .global .kpage_last_entry

kernel_pagedir:
.align 4096
    .kpage_first_entry:
        .4byte 0x00000083 # First entry to avoid crash
        .rept (KERNEL_PAGE_INDEX_START - 1)
            .4byte 0x0
        .endr
    .kpage_kernel_entry:
        .rept (1024 - KERNEL_PAGE_INDEX_START - 1)
            .4byte 0x0
        .endr
    .kpage_last_entry:
        .4byte 0x0

.global kernel_pagetable

kernel_pagetable:
    .rept 0x400
        .4byte 0x0
    .endr
