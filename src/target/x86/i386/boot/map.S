.code32

.include "target/x86/shared/boot.inc"

.section .text

.global setup_paging
.global enable_paging

/*
** Paging Set up
*/

setup_paging:
    ret

enable_paging:
    LV2P $kernel_pagedir, %eax
    mov %eax, %cr3

    # Big page for now
    mov %cr4, %eax
    or $0b10000, %eax
    mov %eax, %cr4

    # Paging & protected mode
    mov %cr0, %eax
    or $0x80000001, %eax
    mov %eax, %cr0
    
    ret
