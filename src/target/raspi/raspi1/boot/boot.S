.globl _start

.org 0x8000

.section .text.boot

_start:
	mov sp, #0x100000

	ldr r3, =kernel
	blx r3
 
halt:
	wfe
	b halt
