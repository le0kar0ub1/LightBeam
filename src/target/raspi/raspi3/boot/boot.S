.globl _start

.include "target/raspi/raspi3/sysregs.inc"

/* unused at time */
.section .init
    b _start
/* NO LOADED */

.section .text.boot
.balign 4
.globl _start
_start:
    b _init_cpus
    b __scratch

/*
el1_entry:
    adr x0, __bss_start
    adr x1, __bss_end
    sub x1, x1, x0
    bl  memzero

    ldr x0, =_start
    mov sp, x0
*/
    bl  init_hook

/* UNREACHEABLE */
    b __hang


/* generate fault from scratch */
.globl __scratch
__scratch:

/* generate infinite */
.global __hang
__hang:
    b __hang
