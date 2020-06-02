.include "arch/aarch64/archutils.inc"

.section .text

.global uart_cpu_log
.global uart_cpu_wrn
.global uart_cpu_err

uart_cpu_log:
    prologue
    mov x2, x0
    bl arch_cpu_get_id
    mov x1, x0
    ldr x0, =_uart_cpulog
    bl uart_kprint
    epilogue
    ret

uart_cpu_wrn:
    prologue
    mov x2, x0
    bl arch_cpu_get_id
    mov x1, x0
    ldr x0, =_uart_cpuwrn
    bl uart_kprint
    epilogue
    ret

uart_cpu_err:
    prologue
    mov x2, x0
    bl arch_cpu_get_id
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
    mov x2, x0
    bl arch_cpu_get_id
    mov x1, x0
    ldr x0, =_rpifb_cpulog
    bl rpifb_kprint
    epilogue
    ret

rpifb_cpu_wrn:
    prologue
    mov x2, x0
    bl arch_cpu_get_id
    mov x1, x0
    ldr x0, =_rpifb_cpuwrn
    bl rpifb_kprint
    epilogue
    ret

rpifb_cpu_err:
    prologue
    mov x2, x0
    bl arch_cpu_get_id
    ldr x0, =_rpifb_cpuerr
    bl rpifb_kprint
    epilogue
    ret

.section .data
.balign 4
_rpifb_cpulog:   .string "[CPU %d] [LOG]: %s\n"
_rpifb_cpuwrn:   .string "[CPU %d] [WRN]: %s\n"
_rpifb_cpuerr:   .string "[CPU %d] [ERR]: %s\n"
