.global cpu_log
.global cpu_wrn
.global cpu_err

.section .text
cpu_log:
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpulog
    bl uart_kprint
    ret

cpu_wrn:
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpuwrn
    bl uart_kprint
    ret

cpu_err:
    mov x2, x0
    bl cpu_getid
    mov x1, x0
    ldr x0, =_cpuerr
    bl uart_kprint
    ret

.section .data
_cpulog:   .string "[CPU %d] [LOG]: %s"
_cpuwrn:   .string "[CPU %d] [WRN]: %s"
_cpuerr:   .string "[CPU %d] [ERR]: %s"
