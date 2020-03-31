#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/system.h"

void helloFromLightBleam(void)
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
    rpifb_set_color(RGB_Black, RGB_Yellow);
    rpifb_puts(kernelname);
    rpifb_set_color(RGB_Black, RGB_White);
    rpifb_puts("\nKernel init routine...\n\n");
}