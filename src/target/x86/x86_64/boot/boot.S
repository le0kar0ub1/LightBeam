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