#include "target/x86/x86.h"
#include "target/x86/common/memory/pmm.h"
#include "target/x86/common/system/multiboot2.h"
#include "kernel/schedule/semaphore.h"

static u8_t bitmap[PMM_BITMAP_SIZE];

void pmm_mark_frame_as_allocated(physaddr_t srt, physaddr_t end)
{
    assert(IS_PAGE_ALIGNED(srt) | IS_PAGE_ALIGNED(end));
}

static void pmm_init(void)
{
    struct multiboot_mmap_entry const *mmap;

    memset(bitmap, 0xFF, PMM_BITMAP_SIZE);

    mmap = multiboot.mmap_start;
    while (mmap < multiboot.mmap_end)
    {
        if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE) {
            //mark_range_as_free(
            //    ROUND_DOWN(mmap->addr, KCONFIG_MMU_PAGESIZE),
            //    ALIGN(mmap->addr + mmap->len, KCONFIG_MMU_PAGESIZE)
            //);
        }
        mmap = ADD_TO_PTR(mmap, multiboot.mmap_entry_size);
    }
}

boot_initcall(pmm_init);