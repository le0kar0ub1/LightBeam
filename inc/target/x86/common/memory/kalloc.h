#ifndef _x86KALLOC_H_
#define _x86KALLOC_H_

#include "target/x86/x86.h"
#include "target/x86/common/memory/vmm.h"
#include "target/x86/common/memory/pmm.h"

#define KHEAP_START ((uintptr)(&__KERNEL_VIRT_END) + KCONFIG_MMU_PAGESIZE)

#define KHEAP_DEFAULT_ALIGN sizeof(void *)
#define KHEAP_ALIGN(x)      ALIGN(x, KHEAP_DEFAULT_ALIGN)

/*
** An allocator control block
** Attrib handle the size & the usage
*/

struct heapblock
{
    int attrib;
} __packed;

typedef struct heapblock block_t;


#define BLK_GETSZ(x)  (x->attrib > 0 ? x->attrib : x->attrib * -1)
#define BLK_ISUSED(x) (x->attrib > 0 ? 1 : 0)
#define BLK_NEXT(x)   ((lstblk + 1) + BLK_GETSZ(lstblk))

void kalloc_init(void);
virtaddr_t kalloc_aligned(size_t size, u32_t align);
#define kalloc_page_aligned(x) kalloc_aligned(x, KCONFIG_MMU_PAGESIZE)
virtaddr_t kalloc(size_t size);
virtaddr_t kfree(size_t size);

#endif