#ifndef __x86VMM_H_
#define __x86VMM_H_

#include "target/x86/x86.h"

#define MMAP_DEFAULT   0b00000000 /* Kernel space, read only, no exec */
#define MMAP_USER      0b00000001 /* Page belongs to user space */
#define MMAP_WRITE     0b00000010 /* Page is writtable */
#define MMAP_EXEC      0b00000100 /* Page is executable */
#define MMAP_REMAP     0b00001000 /* Remap if va is already taken */
#define MMAP_MASK      0b00001111 /* Mask to preserve all flag values */

typedef uint mmap_attrib_t;

#define MUNMAP_DEFAULT     0b00000000  /* Free frames */
#define MUNMAP_DONTFREE    0b00000001  /* Do not free the corresponding frames */

typedef uint munmap_attrib_t;

virtaddr_t vmm_mmap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib);
void vmm_ummap(virtaddr_t virt, size_t sz, mmap_attrib_t attrib);
physaddr_t vmm_get_mapped_frame(virtaddr_t virt);

#endif