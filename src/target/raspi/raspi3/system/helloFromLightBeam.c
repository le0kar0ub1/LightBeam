#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/system.h"

void helloFromLightBeam(void)
{
    char const *kernelname = "\
  _      _       _     ____  _                         \n\
 | |    (_)     | |   |  _ \\| |                       \n\
 | |     _  __ _| |__ | |_) | | ___  __ _ _ __ ___     \n\
 | |    | |/ _` | '_ \\|  _ <| |/ _ \\/ _` | '_ ` _ \\ \n\
 | |____| | (_| | | | | |_) | |  __/ (_| | | | | | |   \n\
 |______|_|\\__, |_| |_|____/|_|\\___|\\__,_|_| |_| |_|\n\
            __/ |                                      \n\
           |___/                                       \n\
";
    rpifb_kprint("\e[38;5;3m%s\e[38;5;3m\nKernel init routine...\n\n", kernelname);
}