#include "target/x86/x86.h"
#include "target/x86/common/memory/pmm.h"
#include "target/x86/common/system/multiboot2.h"
#include "target/x86/common/schedule/spinlock.h"

/* Map the totality of the memory */
static u8_t bitmap[PMM_BITMAP_SIZE];

static spinlock_t lock = SPINLOCK_DEFAULT();

bool pmm_is_frame_allocated(physaddr_t frame)
{
    assert(IS_PAGE_ALIGNED(frame));
    return (bitmap[PMM_BITMAP_ADDR2IDX(frame)] & PMM_BITMAP_ADDR2MASK(frame));
}

void pmm_mark_range_frame_as_allocated(physaddr_t srt, physaddr_t end)
{
    assert(IS_PAGE_ALIGNED(srt));
    assert(IS_PAGE_ALIGNED(end));
    while (srt <= end)
    {
        bitmap[PMM_BITMAP_ADDR2IDX(srt)] |= PMM_BITMAP_ADDR2MASK(srt);
        srt += KCONFIG_MMU_PAGESIZE;
    }
}

void pmm_mark_range_frame_as_free(physaddr_t srt, physaddr_t end)
{
    assert(IS_PAGE_ALIGNED(srt));
    assert(IS_PAGE_ALIGNED(end));
    while (srt <= end)
    {
        bitmap[PMM_BITMAP_ADDR2IDX(srt)] &= ~PMM_BITMAP_ADDR2MASK(srt);
        srt += KCONFIG_MMU_PAGESIZE;
    }
}

physaddr_t pmm_alloc_frame(void)
{
    u32_t idx = 0x0;
    u8_t  sub;

    while (idx < PMM_BITMAP_SIZE)
    {
        if (bitmap[idx] != 0xFF)
        {
            sub = 0x0;
            while (bitmap[idx] & 1 << sub)
                sub++;
            bitmap[idx] |= 1 << sub;
            return ((idx * 8 + sub) * KCONFIG_MMU_PAGESIZE);
        }
        idx++;
    }
    PANIC("Running out of physical memory");
}

extern uintptr __KERNEL_PHYS_END;
extern uintptr __KERNEL_PHYS_LINK;

static void pmm_init(void)
{
    struct multiboot_mmap_entry const *mmap;

    /* 
    ** Mark all as reserved 
    */
    memset(bitmap, 0xFF, PMM_BITMAP_SIZE);

    /* 
    ** There is a problem on multiboot mmap entries provided
    ** This is the `type` and sometime `zero` field which host the segment size instead of `lenght`
    ** Here we are freeing the un-reserved segments
    */
    mmap = multiboot.mmap_start;
    while (mmap < multiboot.mmap_end) {
        if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE) {
            pmm_mark_range_frame_as_free(
            ROUND_DOWN(mmap->addr, KCONFIG_MMU_PAGESIZE),
            ALIGN(mmap->addr + mmap->len, KCONFIG_MMU_PAGESIZE));
        }
        mmap = ADD_TO_PTR(mmap, multiboot.mmap_entry_size);
    }
    /*
    ** Legitimately our kernel is in an available memory segment
    ** We must mark it as allocated
    */
    physaddr_t start = ROUND_DOWN(&__KERNEL_PHYS_LINK, KCONFIG_MMU_PAGESIZE);
    physaddr_t end   = ALIGN(&__KERNEL_PHYS_END, KCONFIG_MMU_PAGESIZE); 
    pmm_mark_range_frame_as_allocated(start, end);

    assert(pmm_is_frame_allocated(ROUND_DOWN(V2P(pmm_init), KCONFIG_MMU_PAGESIZE)));
    uint64 a = pmm_alloc_frame();
    uint64 b = pmm_alloc_frame();
    //serial_printf("ALLOCATD; %x %x\n", a, b);
}

boot_initcall(pmm_init);