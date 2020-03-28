#ifndef __ARCHUTILS_INC_
#define __ARCHUTILS_INC_

.macro prologue
    str x30, [sp, #-16]!
.endm

.macro epilogue
    ldr x30, [sp], #16
.endm

/* Stack ptr must be 16 Bytes aligned */
.macro push reg
    str \reg, [sp, #-16]!
.endm

.macro pop reg
    ldr \reg, [sp], #16
.endm

.macro alignstack reg
    mov \reg, sp
    and \reg, \reg, #0xF
    sub sp, sp, \reg
.endm

.macro cpusWakeUp
    sev
.endm

.macro cpuSleep
    wfe
.endm

#endif
