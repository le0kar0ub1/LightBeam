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
    mrs x1, mpidr_el1
    and x1, x1, #0x3
    cmp x1, #0
    beq core0setupCall

/* NO RETURN FOR OTHER CORES EXCEPT FOR THE 0 */
coreXsetupJmp:
    b _init_cpus
    b __scratch

core0setupCall:
    bl _init_cpus

/* Only the core0 come here */
_bss_clear:
    adr x0, __bss_start
    adr x1, __bss_end
    sub x1, x1, x0
    bl  memzero

    bl  init_hook

/* UNREACHEABLE */
    b __hang
    b __scratch

/* wait for event loop */
.global __hang
__hang:
    wfe
    b __hang

/* Deadloop */
.global __deadloop
__deadloop:
    nop
    b __deadloop



/* generate fault from scratch */
.globl __scratch
__scratch:
