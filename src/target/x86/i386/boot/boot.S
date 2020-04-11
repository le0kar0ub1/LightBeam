.code32

.include "target/x86/shared/boot.inc"

.global _start

.section .text

_start:
    cli
    LV2P $stack_top, %esp

    push %ebx # multiboot structure

    call sanity_multiboot
    call cpuid_detect

    call load_gdt

    call setup_paging
    call enable_paging

okay:
    movl $0x2f4b2f4f, 0xB8000
    movl $0x2f592f41, 0xB8004
    hlt

/*
** Load our GDT & then the kernel selectors
*/

load_gdt:
    LV2P $gdtptr_phys, %eax
    lgdt (%eax)

    mov $KERNEL_DATA_SELECTOR, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss

    ljmp $KERNEL_CODE_SELECTOR, $(flush_codeselector - 0xC0000000)
flush_codeselector:
    ret


/*
** Sanity checks
*/

sanity_multiboot:
    LV2P $_err_multiboot, %esi
    cmp $0x36d76289, %eax
    jne early_crash
    ret

cpuid_detect:
    pushf
    pop %eax
    mov %eax, %ecx

    xor $(1 << 21), %eax
    push %eax
    popf
    pushf
    pop %eax
    push %ecx
    popf
    cmp %ecx, %eax
    jne cpuid_detected

    LV2P $_err_cpuid, %esi
    call early_crash
cpuid_detected:
    ret

early_crash:
    call early_vgaputs
    hlt


/*
** Early Kernel paging data
*/

.section .data

.global kernel_pagedir

kernel_pagedir:
    .first_entry:
    .long 0x00000083 # First entry to avoid crash
    .rept (KERNEL_PAGE_INDEX_START - 1)
        .long   0
    .endr
    .kernel_entry:
    .rept (1024 - KERNEL_PAGE_INDEX_START - 1)
        .long 0x0
    .endr
    .last_entry:
    .long 0x0


/*
** Our kernel stack
*/

.section .bss

.global stack_top

.balign 1024
stack_bottom:
.lcomm stack, 0x10000
stack_top:


/*
** Early Error data
*/

.section .rodata

_err_multiboot: .asciz "Invalid multiboot"
_err_cpuid:     .asciz "CPUID not detected"
