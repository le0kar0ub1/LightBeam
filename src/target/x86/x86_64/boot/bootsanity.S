.code32

.include "target/x86/common/boot.inc"

.global lm_ckeckup

.section .text

/*
** Check if long mode is supported
** fatal feature
*/
lm_ckeckup:
    mov $0x80000000, %eax
    cpuid
    cmp $0x80000001, %eax
    jb noLongMode

    mov $0x80000001, %eax
    cpuid
    test $(1 << 29), %edx
    jz noLongMode
    ret
    noLongMode:
        LV2P $_err_nolm, %esi
        call early_crash

.section .rodata

_err_nolm: .asciz "long mode not supported"
