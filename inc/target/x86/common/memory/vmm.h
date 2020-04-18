#ifndef __x86VMM_H_
#define __x86VMM_H_

#include "target/x86/x86.h"
#include "target/x86/common/memory/pmm.h"

#define MMAP_DEFAULT   0b00000000 /* Kernel space, read only, no exec */
#define MMAP_USER      0b00000001 /* Page belongs to user space */
#define MMAP_WRITE     0b00000010 /* Page is writtable */
#define MMAP_EXEC      0b00000100 /* Page is executable */
#define MMAP_REMAP     0b00001000 /* Remap if va is already taken */

#define MASK_MMAP_DEFAULT(x)   ((bool)(x & 0b00000000))
#define MASK_MMAP_USER(x)      ((bool)(x & 0b00000001))
#define MASK_MMAP_WRITE(x)     ((bool)(x & 0b00000010))
#define MASK_MMAP_EXEC(x)      ((bool)(x & 0b00000100))
#define MASK_MMAP_REMAP(x)     ((bool)(x & 0b00001000))

typedef uint mmap_attrib_t;

#define MUNMAP_DEFAULT     0b00000000  /* Free frames */
#define MUNMAP_DONTFREE    0b00000001  /* Do not free the corresponding frames */

#define MASK_MUNMAP_DEFAULT(x)     ((bool)(x & 0b00000000))
#define MASK_MUNMAP_DONTFREE(x)    ((bool)(x & 0b00000001))

typedef uint munmap_attrib_t;

void vmm_init(void);
virtaddr_t vmm_mmap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib);
void vmm_unmap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib);
bool vmm_is_mapped(virtaddr_t virt);

/*
** Arch-depend prototypes
*/

bool arch_vmm_is_mapped(virtaddr_t virt);
physaddr_t arch_vmm_get_mapped_frame(virtaddr_t virt);
bool arch_vmm_map_phys(virtaddr_t virt, physaddr_t phys, mmap_attrib_t attrib);
bool arch_vmm_map_virt(virtaddr_t virt, mmap_attrib_t attrib);
void arch_vmm_unmap(virtaddr_t virt, munmap_attrib_t attrib);

#endif