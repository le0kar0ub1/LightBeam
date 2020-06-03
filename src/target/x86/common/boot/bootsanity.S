.code32

.include "target/x86/common/boot.inc"

.section .text

/*
** Sanity checks
*/

.extern early_crash
.extern early_vgaputs
.extern _err_multiboot

.global sanity_multiboot

/*
** multiboot checkup
*/
sanity_multiboot:
    LV2P $_err_multiboot, %esi
    cmp $0x36d76289, %eax
    jne early_crash
    ret

.global cpuid_detect

/*
** detect the cpuid
** Is a fatal feature
*/
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

/*
** Early Error data
*/

.section .rodata

_err_multiboot: .asciz "Invalid multiboot"
_err_cpuid:     .asciz "CPUID not detected"
