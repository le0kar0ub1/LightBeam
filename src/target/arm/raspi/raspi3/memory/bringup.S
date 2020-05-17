.global mmu_enable

.section .text

mmu_enable:
    MSR TTBR0_EL1, X0    // Set TTBR0
    MSR TTBR1_EL1, X1    // Set TTBR1
    MSR TCR_EL1, X2      // Set TCR
    ISB                  // The ISB forces these changes to be seen before the MMU is enabled.

    MRS X0, SCTLR_EL1    // Read System Control Register configuration data
    ORR X0, X0, #1       // Set [M] bit and enable the MMU.
    MSR SCTLR_EL1, X0    // Write System Control Register configuration data
    ISB                  // The ISB forces these changes
    RET
