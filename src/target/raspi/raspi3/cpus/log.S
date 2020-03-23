.section .text

.include "arch/aarch64/archutils.inc"

.global uart_cpu_log
.global uart_cpu_wrn
.global uart_cpu_err

uart_cpu_log:
    prologue
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpulog
    bl uart_kprint
    epilogue
    ret

uart_cpu_wrn:
    prologue
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpuwrn
    bl uart_kprint
    epilogue
    ret

uart_cpu_err:
    prologue
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpuerr
    bl uart_kprint
    epilogue
    ret

.global lfb_cpu_log
.global lfb_cpu_wrn
.global lfb_cpu_err

lfb_cpu_log:
    prologue
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpulog
    bl lfb_kprint
    epilogue
    ret

lfb_cpu_wrn:
    prologue
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpuwrn
    bl lfb_kprint
    epilogue
    ret

lfb_cpu_err:
    prologue
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpuerr
    bl lfb_kprint
    epilogue
    ret

.section .data
_cpulog:   .string "[CPU %d] [LOG]: %s\n"
_cpuwrn:   .string "[CPU %d] [WRN]: %s\n"
_cpuerr:   .string "[CPU %d] [ERR]: %s\n"
