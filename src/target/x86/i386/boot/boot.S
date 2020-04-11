.code32

.include "target/x86/i386/boot.inc"

.global _start

.section .text

_start:
    cli
    LV2P $stack_top, %esp

    push %ebx # multiboot structure

    call sanity_multiboot
    call cpuid_detect

    hlt


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


.section .bss

.balign 1024

stack_bottom:
.lcomm stack, 0x10000
stack_top:

.section .rodata
_err_multiboot: .asciz "Invalid multiboot"
_err_cpuid:     .asciz "CPUID not detected"