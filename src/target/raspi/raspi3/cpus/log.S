.section .text

.include "arch/aarch64/archutils.inc"

.global uart_cpu_log
.global uart_cpu_wrn
.global uart_cpu_err

uart_cpu_log:
    prologue
    mov x2, x0
    bl cpuGetId
    mov x1, x0
    ldr x0, =_uart_cpulog
    bl uart_kprint
    epilogue
    ret

uart_cpu_wrn:
    prologue
    mov x2, x0
    bl cpuGetId
    mov x1, x0
    ldr x0, =_uart_cpuwrn
    bl uart_kprint
    epilogue
    ret

uart_cpu_err:
    prologue
    mov x2, x0
    bl cpuGetId
    mov x1, x0
    ldr x0, =_uart_cpuerr
    bl uart_kprint
    epilogue
    ret

.global lfb_cpu_log
.global lfb_cpu_wrn
.global lfb_cpu_err

lfb_cpu_log:
    prologue
    mov x3, x0
    bl cpuGetId
    mov x1, x0
    mov x2, #0x808
    lsl x2, x2, #12
    add x2, x2, #0x080
    ldr x0, =_lfb_cpulog
    bl lfb_kprint
    epilogue
    ret

lfb_cpu_wrn:
    prologue
    mov x3, x0
    bl cpuGetId
    mov x1, x0
    mov x2, #0xFFA
    lsl x2, x2, #12
    add x2, x2, #0x500
    ldr x0, =_lfb_cpuwrn
    bl lfb_kprint
    epilogue
    ret

lfb_cpu_err:
    prologue
    mov x3, x0
    bl cpuGetId
    mov x1, x0
    mov x2, #0xFF0000
    ldr x0, =_lfb_cpuerr
    bl lfb_kprint
    epilogue
    ret

.section .data
_lfb_cpulog:   .string "[CPU %d] [%$ALOG%$R]: %s\n"
_lfb_cpuwrn:   .string "[CPU %d] [%$AWRN%$R]: %s\n"
_lfb_cpuerr:   .string "[CPU %d] [%$AERR%$R]: %s\n"
_uart_cpulog:   .string "[CPU %d] [LOG]: %s\n"
_uart_cpuwrn:   .string "[CPU %d] [WRN]: %s\n"
_uart_cpuerr:   .string "[CPU %d] [ERR]: %s\n"
