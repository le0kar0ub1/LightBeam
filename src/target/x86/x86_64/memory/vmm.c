#include "target/x86/i386/memory/vmm.h"
#include "target/x86/common/memory/kalloc.h"

/*
** If there is no recursive mapping all these functions will fucked up.
** Assuming that's not the case.
** This functions are usable only in this file.
*/

static inline get_pagepml4(void)
{
    return ((struct pml4_t *)0xff8000000000ul);
}

/*
** VMM can't be initcall()
** The PMM is handle by a boot_initcall() and is totaly shared
*/