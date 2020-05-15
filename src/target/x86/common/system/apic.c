#include "target/x86/x86.h"
#include "target/x86/common/system/apic.h"
#include "target/x86/common/memory/kalloc.h"

static void *apic = NULL;

//u32_t apic_get_id(void)
//{
//    return (apic_read(APIC_ID) >> 24);
//}

void apic_init(void)
{
    apic = kalloc_dev(APIC_REG_BASE_ADDR, KCONFIG_MMU_PAGESIZE);
    assert(apic);
}