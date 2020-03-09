.equ SCTLR_RESERVED,           (3 << 28) | (3 << 22) | (1 << 20) | (1 << 11)
.equ SCTLR_EE_LITTLE_ENDIAN,   (0 << 25)
.equ SCTLR_EOE_LITTLE_ENDIAN,  (0 << 24)
.equ SCTLR_I_CACHE_DISABLED,   (0 << 12)
.equ SCTLR_D_CACHE_DISABLED,   (0 << 2)
.equ SCTLR_MMU_DISABLED,       (0 << 0)
.equ SCTLR_MMU_ENABLED,        (1 << 0)

.equ SCTLR_VALUE_MMU_DISABLED, (SCTLR_RESERVED | SCTLR_EE_LITTLE_ENDIAN | SCTLR_I_CACHE_DISABLED | SCTLR_D_CACHE_DISABLED | SCTLR_MMU_DISABLED)

.equ HCR_RW,        (1 << 31)
.equ HCR_VALUE,     HCR_RW

.equ SCR_RESERVED,      (3 << 4)
.equ SCR_RW,            (1 << 10)
.equ SCR_NS,            (1 << 0)
.equ SCR_VALUE,         (SCR_RESERVED | SCR_RW | SCR_NS)

.equ SPSR_MASK_ALL,     (7 << 6)
.equ SPSR_EL1h,         (5 << 0)
.equ SPSR_VALUE,        (SPSR_MASK_ALL | SPSR_EL1h)
