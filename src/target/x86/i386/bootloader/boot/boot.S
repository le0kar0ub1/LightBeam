.code16

BOOTSEG = 0x0

MAGICMBR = 0xAA55

.section ".bootsector", "ax"

.global _bootsector
_bootsector:
    ljmp $BOOTSEG, $._bootsector

._bootsector:
    movw %cs, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %ss
    xorw %sp, %sp
    cli
    cld

    movw $_bootmsg, %si
.msg_loop:
    lodsb
    andb %al, %al
    jz   .msgdone
    movb $0xe, %ah
    movw $7, %bx
    int  $0x10
    jmp  .msg_loop

.msgdone:
    xorw %ax, %ax
    int  $0x16

bioskill:
    int $0x19 # BIOS poweroff
    ljmp $0xf000,$0xfff0 # case error reset code

_bootmsg: .asciz " *\r\n* Lightbeam legacy bootloader\r\n *\r\n\nPress any key to boot..."

.magic: .long 0x10101010

.fill 510-(.-_bootsector), 1, 0

.section .bootmagic, "ax"
.word MAGICMBR
