.include "arch/aarch64/archutils.inc"

.section .text

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

.section .data
.balign 4
_uart_cpulog:   .string "[CPU %d] [LOG]: %s\n"
_uart_cpuwrn:   .string "[CPU %d] [WRN]: %s\n"
_uart_cpuerr:   .string "[CPU %d] [ERR]: %s\n"


.section .text
.global rpifb_cpu_log
.global rpifb_cpu_wrn
.global rpifb_cpu_err

rpifb_cpu_log:
    prologue
    mov x3, x0
    bl cpuGetId
    mov x1, x0
    mov x2, #0xC0C
    lsl x2, x2, #12
    add x2, x2, #0x0C0
    ldr x0, =_rpifb_cpulog
    bl rpifb_kprint
    epilogue
    ret

rpifb_cpu_wrn:
    prologue
    mov x3, x0
    bl cpuGetId
    mov x1, x0
    mov x2, #0xFFA
    lsl x2, x2, #12
    add x2, x2, #0x500
    ldr x0, =_rpifb_cpuwrn
    bl rpifb_kprint
    epilogue
    ret

rpifb_cpu_err:
    prologue
    mov x3, x0
    bl cpuGetId
    mov x1, x0
    mov x2, #0xFF0000
    ldr x0, =_rpifb_cpuerr
    bl rpifb_kprint
    epilogue
    ret

.section .data
.balign 4
_rpifb_cpulog:   .string "[CPU %d] [%$ALOG%$R]: %s\n"
_rpifb_cpuwrn:   .string "[CPU %d] [%$AWRN%$R]: %s\n"
_rpifb_cpuerr:   .string "[CPU %d] [%$AERR%$R]: %s\n"
