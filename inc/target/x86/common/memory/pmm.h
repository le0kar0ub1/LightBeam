#ifndef __PMM_H_
#define __PMM_H_

#include "target/x86/x86.h"

#define PMM_TOTAL_FRAME (UINTPTR_MAX / KCONFIG_MMU_PAGESIZE)
#define PMM_BITMAP_SIZE (PMM_TOTAL_FRAME / 8)

#define PMM_FRAME_ADDR_SHIFT 0xC

#define PMM_BITMAP_ADDR2IDX(x)  ((x >> PMM_FRAME_ADDR_SHIFT) / 8)
#define PMM_BITMAP_ADDR2MASK(x) (1 << (((x) >> PMM_FRAME_ADDR_SHIFT) % 8))

bool pmm_is_frame_allocated(physaddr_t frame);
void pmm_mark_range_frame_as_allocated(physaddr_t srt, physaddr_t end);
void pmm_mark_range_frame_as_free(physaddr_t srt, physaddr_t end);

#endif