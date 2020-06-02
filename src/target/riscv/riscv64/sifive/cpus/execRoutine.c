#include "target/riscv/riscv64/sifive/cpus/cpus.h"

bool cpuExecRoutine(int core, void (*routine), int argc, char **argv)
{
    if (core > KCONFIG_MAXCPUS - 1)
        return (false);
    if (!routine)
        return (false);
    cpuSetRoutine(core, routine, argc, argv);
}