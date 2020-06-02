#include "target/riscv/riscv64/sifive/cpus/cpus.h"
#include "target/riscv/riscv64/sifive/soc/clint.h"

bool cpuExecRoutine(cpuid_t core, int (*routine)(int, char **), int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (false);
    if (!routine)
        return (false);
    cpuSetRoutine(core, routine, argc, argv);
    CLINT_RAISE_SOFT_INT(core);
    return (true);
}