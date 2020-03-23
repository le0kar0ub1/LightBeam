#ifndef __ARCHUTILS_INC_
#define __ARCHUTILS_INC_

.macro prologue
    sub sp, sp, #8
    str x30, [sp, #8]
.endm

.macro epilogue
    ldr x30, [sp, #8]
    add sp, sp, #8
.endm

.macro cpusWakeUp
    sev
.endm

.macro cpuSleep
    wfe
.endm

#endif
