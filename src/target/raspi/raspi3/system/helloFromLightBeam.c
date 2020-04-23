#include "target/raspi/raspi3/drivers/fb.h"
#include "target/raspi/raspi3/system.h"

extern char const *LightBeamNameArt;

void helloFromLightBeam(void)
{
    rpifb_kprint(
        "%s%s%s\nKernel init routine...\n\n",
        RGB256toESCFRT(Yellow),
        LightBeamNameArt,
        RGB256toESCFRT(White)
    );
}