.code32

.section .text

.global initlm

initlm:
    hlt

    # popl %ebx
    # addl $__KERNEL_ADDR_TRNS, %ebx
    # mov $multiboot_virtaddr, %eax
    # mov %ebx, (%eax) # in our multiboot parser file
