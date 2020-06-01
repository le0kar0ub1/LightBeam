#ifndef __SIFIVE_CLINT_
#define __SIFIVE_CLINT_

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"

#include "target/riscv/riscv64/sifive/soc/map.h"

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

void clint_set_msip(int core);
void clint_reset_msip(int core);
u32_t clint_get_msip(int core);
void clint_set_mtimecmp(int core, u64_t val);
u64_t clint_get_mtimecmp(int core);
void clint_set_mtime(u64_t val);
u64_t clint_get_mtime(void);

#define clint_generate_interrupt(x) clint_set_msip(x)

#endif