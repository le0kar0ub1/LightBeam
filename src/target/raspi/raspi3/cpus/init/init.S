.global _init_cpus

.section .text

_init_cpus:
    mrs x0, midr_el1
    mrs x1, mpidr_el1
    msr vpidr_el2, x0
    msr vmpidr_el2, x1

/* Disable coprocessor traps for all Cores */
    mov x0, #0x33ff
    msr cptr_el2, x0
    msr hstr_el2, xzr
    mov x0, #3 << 20
    msr cpacr_el1, x0

/* Enable CNTP for EL1 */
    mrs x0, cnthctl_el2
    orr x0, x0, #0x3
    msr cnthctl_el2, x0
    msr cntvoff_el2, xzr
/* the for el0 (util?) */
    mrs x0, cntkctl_el1
    orr x0, x0, #0x3
    msr cntkctl_el1, x0

/*  Initialize HCR_EL2 so EL1 is 64 bits for all Cores */
    mrs x0, hcr_el2
    orr x0, x0, #(1 << 31)  /* Set el1 to 64bit */
    orr x0, x0, #(1 << 1)   /* Hardwired swio */
    msr hcr_el2, x0

/* Enable instruction cache */
    mrs x0, sctlr_el1
    orr x0, x0, #(1 << 12)
    msr sctlr_el1, x0

/* Initialize SCTLR_EL1 for all Cores */
    mov  x0, #0x0800
    movk x0, #0x30d0, lsl #16
    orr  x0, x0, #(0x1 << 2)
    orr  x0, x0, #(0x1 << 12)
    msr  sctlr_el1, x0

/* Set up exception handlers */
    ldr x0, =_vectors
    msr vbar_el1, x0

    b _init_stacks
