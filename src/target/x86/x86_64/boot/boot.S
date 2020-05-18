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

    # call load_gdt

    # call setup_paging

    # jmp kernelmain

    hlt

/*
** Our kernel stack
*/

.section .bss

.global stack_top

.align 1024
stack_bottom:
.lcomm stack, 0x1000 * 0x10
stack_top:
