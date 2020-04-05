.code16

BOOTSEG  = 0x0
MAGICMBR = 0xAA55

.section ".bootsector", "ax"

.extern _scdbreath

.global _bootsector

_bootsector:
    ljmp $BOOTSEG, $._bootsector

._bootsector:
    movw %cs, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %ss
    movw %ax, %fs
    movw %ax, %gs
    xorw %sp, %sp
    cli
    cld

    movb %dl, drive_number

    mov $__BOOT_SECTOR_START, %sp 

    movw $_bootmsg, %si
    call msg_loop

.bootmsgdone:
    xorw %ax, %ax
    int  $0x16

    movl $8, %eax
    xorb %dh, %dh
    movb $0x02, %ah
    movw $0x0002, %cx
    movw $__BOOT_SCDBREATH_START, %bx
    int  $0x13

    mov $1, %ah
    mov drive_number, %dl
    int $0x13
    mov $_booterror_rd, %si
    jnz booterror

    jmp _scdbreath

booterror:
    call msg_loop
    mov $_booterror, %si
    call msg_loop
    xorw %ax, %ax
    int $0x16
    jmp bioskill

msg_loop:
    lodsb
    andb %al, %al
    jz   .msg_loop_end
    movb $0xe, %ah
    movw $7, %bx
    int  $0x10
    jmp  msg_loop
.msg_loop_end:
    ret

bioskill:
    int $0x19 # BIOS poweroff
    ljmp $0xf000,$0xfff0 # case error reset code

_bootmsg: .asciz " *\r\n* Lightbeam legacy bootloader\r\n *\r\n\nPress any key to boot..."

_booterror_rd: .asciz "\n\rRead disk sectors failed..."
_booterror:    .asciz " Press any key to reboot\n\r"

/* kernel informations */
.magic: 
    .long 0x10101010 /* LightBeam magic */
drive_number:
    .long 0x00000000 /* boot drive number */

.fill 510-(.-_bootsector), 1, 0

.section .bootmagic, "ax"
.word MAGICMBR


.global _scdbreath

.section ".text.boot", "ax"

_scdbreath:
    movw $_bootms, %si
.msg_loo:
    lodsb
    andb %al, %al
    jz   .msgdon
    movb $0xe, %ah
    movw $7, %bx
    int  $0x10
    jmp  .msg_loo

.msgdon:
    lgdt _bootgdt32Desc

    movl %cr0, %eax
    orb  $0x01, %al
    movl %eax, %cr0

    movw  $0x08, %ax
    movw  %ax, %ds
    movw  %ax, %es
    movw  %ax, %gs
    movw  %ax, %fs

    movl  %cr0, %eax
    andb  $0xFE, %al
    movl  %eax, %cr0

.hang:
    jmp .hang

.section ".data.boot", "awd"
_bootms: .asciz "\n\rwe are done"

.section .data.boot, "awd"
.balign 8
_bootgdt32Desc:
    .word   _bootgdt32_end - _bootgdt32 - 1
    .long   _bootgdt32
_bootgdt32:
    .quad   0x0000000000000000  /* Reserved */
    .quad   0x00cf9a000000ffff  /* __KERNEL_CS */
    .quad   0x00cf92000000ffff  /* __KERNEL_DS */
_bootgdt32_end:
