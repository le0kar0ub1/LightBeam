#ifndef _x86KALLOC_H_
#define _x86KALLOC_H_

#include "target/x86/x86.h"
#include "target/x86/common/memory/vmm.h"
#include "target/x86/common/memory/pmm.h"

#define KHEAP_START ((uintptr)(&__KERNEL_VIRT_END) + KCONFIG_MMU_PAGESIZE)

#define KHEAP_DEFAULT_ALIGN sizeof(void *)
#define KHEAP_ALIGN(x)      ALIGN(x, KHEAP_DEFAULT_ALIGN)

typedef enum
{
    KALLOC_DEFAULT     = 0b0,
    KALLOC_FORCE_ALLOC = 0b1,
} kallocattrib_t;

/*
** An allocator control block
** Attrib handle the size & the usage
*/
struct heapblock
{
    int attrib;
};
typedef struct heapblock block_t;


#define BLK_GETSZ(x)  (x->attrib >= 0 ? x->attrib : x->attrib * -1)
#define BLK_ISUSED(x) (x->attrib >  0 ? 1 : 0)
#define BLK_NEXT(x)   ((block_t *)((uintptr)(x + 1) + BLK_GETSZ(x)))
#define ADDR2BLK(x)   ((block_t  *)SUB_TO_PTR(x, sizeof(block_t)))
#define BLK2ADDR(x)   ((virtaddr_t)ADD_TO_PTR(x, sizeof(block_t)))

void kalloc_init(void);
void kalloc_dump(void);
virtaddr_t kalloc_aligned(size_t size, u32_t align);
#define kalloc_page_aligned(x) kalloc_aligned(x, KCONFIG_MMU_PAGESIZE)
virtaddr_t kalloc(size_t size);
virtaddr_t kalloc_force_alloc(size_t size);
void kfree(virtaddr_t virt);

#endif