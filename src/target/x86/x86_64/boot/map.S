.code32

.include "target/x86/common/boot.inc"

.section .text

.global setup_paging

/*
** Paging Set up
*/

setup_paging:
    /* recursive mapping */
    LV2P $kernel_pml4, %eax
    orl $(MMU_PRESENT | MMU_WRITABLE), %eax
    SV2P %eax, .kernel_plm4_last_entry

    LV2P $kernel_page_directory_pointer, %eax
    orl $(MMU_PRESENT | MMU_WRITABLE), %eax
    SV2P %eax, .kernel_plm4_kernel_entry
    #SV2P %eax, kernel_pml4

    LV2P $kernel_page_directory, %eax
    orl $(MMU_PRESENT | MMU_WRITABLE), %eax
    LV2P $kernel_page_directory_pointer, %edi
    movl %eax, (KERNEL_PDP_INDEX_START * 8)(%edi)
    #movl %eax, (%edi)

    LV2P $kernel_page_directory, %edi
    xorl %edx, %edx
    orl $(MMU_PRESENT | MMU_WRITABLE | MMU_SZ_TWO_MB), %edx
    movl $PAGE_ENTRY_NBR, %ecx
    .loop_page:
        movl %edx, (%edi)
        addl $0x200000, %edx # 2MIB page
        addl $0x8, %edi
        loop .loop_page

    LV2P $kernel_pml4, %eax
    movl %eax, %cr3

    # Big page for now
    movl %cr4, %eax
    orl $((1 << 4) | (1 << 7)), %eax
    movl %eax, %cr4

    # long mode
    movl $0xC0000080, %eax
    rdmsr
    orl $((0x1 << 0x8) | (0x1 << 0xB)), %eax
    wrmsr

    # Paging & protected mode
    movl %cr0, %eax
    orl $0x80000001, %eax
    movl %eax, %cr0

    # flush TLB
    movl %cr3, %eax
    movl %eax, %cr3

    ret

/*
** Early Kernel paging data
*/

.section .data

.global kernel_pml4
    .global .kernel_plm4_first_entry
    .global .kernel_plm4_kernel_entry
    .global .kernel_plm4_last_entry

.align 4096
kernel_pml4:
    .kernel_plm4_first_entry:
        .8byte 0x0000083
        .rept (KERNEL_PML4_INDEX_START - 1)
            .8byte 0x0
        .endr
    .kernel_plm4_kernel_entry:
        .rept (PAGE_ENTRY_NBR - KERNEL_PML4_INDEX_START - 1)
            .8byte 0x0
        .endr
    .kernel_plm4_last_entry:
        .8byte 0x0

.global kernel_page_directory_pointer

.align 4096
kernel_page_directory_pointer:
    .rept PAGE_ENTRY_NBR
        .8byte 0x0
    .endr

.global kernel_page_directory

.align 4096
kernel_page_directory:
    .rept PAGE_ENTRY_NBR
        .8byte 0x0
    .endr
