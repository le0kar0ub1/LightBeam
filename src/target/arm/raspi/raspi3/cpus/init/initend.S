/* branching cores on their hookpoints */

.global cpus_hookpoint

.section .text

cpus_hookpoint:
    mrs x1, mpidr_el1
    and x1, x1, #0x3
    cbz x1, hookcore0
    b hookcoreX

/* Return at bootcode */
hookcore0:
    ret
    b hookcore0

/* Waiting for instruction */
hookcoreX:
    b multicoresX_start
    b __hang
