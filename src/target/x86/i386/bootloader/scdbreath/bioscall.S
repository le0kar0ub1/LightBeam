.section .bioscall, "ax"

.code16
    .globl  _bioscall
    .type   _bioscall, @function
_bioscall:
    pushl   %ebp
    movl    %esp, %ebp
    pushl   %eax
    pushl   %edx
    pushl   %ecx

    movl    0x10(%ebp), %ecx
    movl    0x0c(%ebp), %edx
    movl    0x08(%ebp), %eax

    /* Self-modify the INT instruction.  Ugly, but works. */
    cmpb    %al, 3f
    je  1f
    movb    %al, 3f
    jmp 1f      /* Synchronize pipeline */
1:
    /* Save state */
    pushfl
    pushw   %fs
    pushw   %gs
    pushal

    /* Copy input state to stack frame */
    subw    $44, %sp
    movw    %dx, %si
    movw    %sp, %di
    movw    $11, %cx
    rep; movsd

    /* Pop full state from the stack */
    popal
    popw    %gs
    popw    %fs
    popw    %es
    popw    %ds
    popfl

    /* Actual INT */
    .byte   0xcd        /* INT opcode */
3:  .byte   0

    /* Push full state to the stack */
    pushfl
    pushw   %ds
    pushw   %es
    pushw   %fs
    pushw   %gs
    pushal

    /* Re-establish C environment invariants */
    cld
    movzwl  %sp, %esp
    movw    %cs, %ax
    movw    %ax, %ds
    movw    %ax, %es

    /* Copy output state from stack frame */
    movw    68(%esp), %di   /* Original %cx == 3rd argument */
    andw    %di, %di
    jz  4f
    movw    %sp, %si
    movw    $11, %cx
    rep; movsd
4:  addw    $44, %sp

    /* Restore state and return */
    popal
    popw    %gs
    popw    %fs
    popfl

    popl    %ecx
    popl    %edx
    popl    %eax
    popl    %ebp
    retl
    .size   _bioscall, .-_bioscall
