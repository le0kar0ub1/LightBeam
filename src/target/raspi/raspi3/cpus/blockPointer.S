.globl cpuBlockPtr

.section .data
.balign 8
cpuBlockPtr: 
.8byte 0x0 // Core 0 Control Block pointer
.8byte 0x0 // Core 1 Control Block pointer	
.8byte 0x0 // Core 2 Control Block pointer
.8byte 0x0 // Core 3 Control Block pointer
