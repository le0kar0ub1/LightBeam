#include "target/x86/x86.h"
#include "target/x86/common/memory/vmm.h"

static void __purehook(void)
{
    run_pure_initcalls();
}

pure_inithook(__purehook);