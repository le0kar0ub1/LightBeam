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

    call kernelmain

    hlt

/*
** BSS section clear
*/

clear_bss:
    movl $__BSS_START, %eax
    .bssclear:
        movb $0x0, (%eax)
        incl %eax
        cmpl $__BSS_END, %eax
        jne .bssclear
    ret


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

    ljmp $KERNEL_CODE_SELECTOR, $(.flush_codeselector - 0xC0000000)
.flush_codeselector:
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
** Our kernel stack
*/

.section .bss

.global stack_top

.align 1024
stack_bottom:
.lcomm stack, 0x1000 * 0xA
stack_top:


/*
** Early Error data
*/

.section .rodata

_err_multiboot: .asciz "Invalid multiboot"
_err_cpuid:     .asciz "CPUID not detected"
