#include "target/riscv/riscv64/sifive/soc/clint.h"

/*
** Generate Software Interrupt to core X
*/
void clint_set_msip(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    u32_t *ptr = (u32_t *)(SOC_MMAP_START_RWA_CLINT);
    *(ptr + core) = 0b1;
}

/*
** Reset msip to core X
*/
void clint_reset_msip(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    u32_t *ptr = (u32_t *)(SOC_MMAP_START_RWA_CLINT);
    *(ptr + core) = 0b0;
}

/*
** Get MSIP state core X
*/
u32_t clint_get_msip(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (0);
    u32_t *ptr = (u32_t *)(SOC_MMAP_START_RWA_CLINT);
    return (*(ptr + core));
}

/*
** Setup mtimecmp core X
*/
void clint_set_mtimecmp(int core, u64_t val)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return;
    u64_t *ptr = (u64_t *)(SOC_MMAP_START_RWA_CLINT + 0x4000);
    *(ptr + core) = val;
}

/*
** Get mtimecmp core X
*/
u64_t clint_get_mtimecmp(int core)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (0);
    u64_t *ptr = (u64_t *)(SOC_MMAP_START_RWA_CLINT + 0x4000);
    return (*(ptr + core));
}

void clint_set_mtime(u64_t val)
{
    u64_t *ptr = (u64_t *)(SOC_MMAP_START_RWA_CLINT + 0xBFF8);
    *ptr = val;
}

u64_t clint_get_mtime(void)
{
    u64_t *ptr = (u64_t *)(SOC_MMAP_START_RWA_CLINT + 0xBFF8);
    return (*ptr);
}
