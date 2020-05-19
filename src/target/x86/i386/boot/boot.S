.code32

.include "target/x86/common/boot.inc"

.global _start

.section .text

_start:
    cli
    LV2P $stack_top, %esp

    pushl %ebx # phys multiboot structure

    call sanity_multiboot
    call cpuid_detect

    call load_gdt

    call setup_paging

    popl %ebx
    addl $__KERNEL_ADDR_TRNS, %ebx
    mov $multiboot_virtaddr, %eax
    mov %ebx, (%eax) # in our multiboot parser file

    jmp kernelmain

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

    ljmp $KERNEL_CODE_SELECTOR, $(.flush_codeselector - 0xC0000000)
.flush_codeselector:
    ret


/*
** Our kernel stack
*/

.section .bss

.global stack_top

.align 1024
stack_bottom:
.lcomm stack, 0x1000 * 10
stack_top:
