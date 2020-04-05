.section ".init", "ax"

.global boothello

boothello:
    mov $0x0002, %ax
    int $0x10

    mov $0x0700, %ax
    mov $0x0f, %bh
    mov $0x184f, %dx
    xor %cx, %cx
    int $0x10
    jmp print_message

    mov $0x02, %ah
    mov $0x00, %bh
    mov $0x0000, %dx
    int $0x10
print_message:
    mov $0x02, %ah
    mov $0x00, %bh
    mov $0x0000, %dx
    int $0x10 # set cursor position

    mov $_bmsg0, %si # loads the address of msg into si
    mov $0x0001, %cx
    mov $0xe, %ah # loads 0xe (function number for int 0x10) into ah
    jmp print_char

print_message_2:
    mov $0x02, %ah
    mov $0x00, %bh
    mov $0x0100, %dx
    int $0x10 # set cursor position

    mov $_bmsg1, %si # loads the address of msg into si
    mov $0x0002, %cx
    mov $0xe, %ah # loads 0xe (function number for int 0x10) into ah
    jmp print_char

print_message_3:
    mov $0x02, %ah
    mov $0x00, %bh
    mov $0x0200, %dx

    int $0x10 # set cursor position
    mov $_bmsg2, %si # loads the address of msg into si
    mov $0x0003, %cx
    mov $0xe, %ah # loads 0xe (function number for int 0x10) into ah
    jmp print_char

 print_char:
     mov $0x0e, %ah
     lodsb
     cmp $0, %al
     je done
     mov $0xc0, %bl
     int $0x10
     jmp print_char

 done:
     cmp $0x0001, %cx
     je print_message_2
    
     cmp $0x0002, %cx
     je print_message_3

__deadpoint:
    hlt

_bmsg0: .asciz "*******************************"
_bmsg1: .asciz "* Lightbeam legacy bootloader *"
_bmsg2: .asciz "*******************************"