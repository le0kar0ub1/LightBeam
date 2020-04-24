#include "target/x86/x86.h"
#include "target/x86/common/memory/vmm.h"

/*
** Here we are running early drivers initcalls & PMM
** Then initalizing the VMM wich can not be initcalled()
** Finally print hello from LightBeam
*/

static void __boothook(void)
{
    run_boot_initcalls();
    arch_vmm_init();
    helloFromLightBeam();
}

boot_inithook(__boothook);