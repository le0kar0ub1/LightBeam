/* branching cores on their hookpoints */

.global cpus_hookpoint

.section .text

cpus_hookpoint:
    nop
    b cpus_hookpoint
