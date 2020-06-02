#ifndef __SIFIVE_CLINT_
#define __SIFIVE_CLINT_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

#include "target/riscv/riscv64/sifive/soc/map.h"
#include "target/riscv/riscv64/sifive/cpus/cpus.h"

/*
Address Width Attr. Description Notes

0x200000 4B RW msip for hart 0
0x200004 4B RW msip for hart 1
0x200008 4B RW msip for hart 2
0x20000c 4B RW msip for hart 3
0x200010 4B RW msip for hart 4

0x204028 … 0x20bff7 Reserved

0x204000 8B RW mtimecmp for hart 0
0x204008 8B RW mtimecmp for hart 1
0x204010 8B RW mtimecmp for hart 2
0x204018 8B RW mtimecmp for hart 3
0x204020 8B RW mtimecmp for hart 4

0x204028 … 0x20bff7 Reserved

0x20bff8 8B RW mtime Timer Register

0x20c000 Reserved
*/

void clint_set_msip(cpuid_t core, u32_t val);
void clint_reset_msip(cpuid_t core);
u32_t clint_get_msip(cpuid_t core);
void clint_set_mtimecmp(cpuid_t core, u64_t val);
u64_t clint_get_mtimecmp(cpuid_t core);
void clint_set_mtime(u64_t val);
u64_t clint_get_mtime(void);

#define CLINT_RAISE_SOFT_INT(x) clint_set_msip(x, 1)
#define CLINT_ACQUIRE_SOFT_INT() clint_set_msip(cpuGetId(), 0)

#endif