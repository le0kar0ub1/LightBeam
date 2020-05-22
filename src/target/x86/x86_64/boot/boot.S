.code32

.include "target/x86/common/boot.inc"

.global _start

.section .text

_start:
    cli
    cld
    LV2P $stack_top, %esp

    pushl %ebx # phys multiboot structure

    call sanity_multiboot
    call cpuid_detect
    call lm_ckeckup

    call setup_paging

    LV2P $gdtptr_phys, %eax
    lgdt (%eax)

    popl %ebx
    ljmp $KERNEL_CODE_SELECTOR, $(lmworld - __KERNEL_ADDR_TRNS)

    hlt

/*
** Our kernel stack
*/

.section .bss

.global stack_top

.align 1024
stack_bottom:
.lcomm stack, 0x1000 * 10
stack_top:
