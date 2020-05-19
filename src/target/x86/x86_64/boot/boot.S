.code32

.include "target/x86/common/boot.inc"

.global _start

.section .text

_start:
    cli
    cld
    LV2P $stack_top, %esp

    #pushl %ebx # phys multiboot structure

    call sanity_multiboot
    call cpuid_detect
    call lm_ckeckup


    call setup_paging

    LV2P $gdtptr_phys, %eax
    lgdt (%eax)

    #popl %ebx
    ljmp $KERNEL_CODE_SELECTOR, $(lmworld - __KERNEL_ADDR_TRNS)

    hlt

/*
** Load our GDT & then the kernel selector
*/

#load_gdt:
#    LV2P $gdtptr_phys, %eax
#    lgdt (%eax)
#
#    mov $KERNEL_DATA_SELECTOR, %ax
#    mov %ax, %ds
#    mov %ax, %es
#    mov %ax, %fs
#    mov %ax, %gs
#    mov %ax, %ss
#
#    ljmp $KERNEL_CODE_SELECTOR, $(.flush_codeselector - __KERNEL_ADDR_TRNS)
#.flush_codeselector:
#    ret


/*
** Our kernel stack
*/

.section .bss

.global stack_top

.align 1024
stack_bottom:
.lcomm stack, 0x1000 * 10
stack_top:
