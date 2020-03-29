#include "target/raspi/raspi3/cpus/cpus.h"
/driver/gpio.h"#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/system.h"

bool cpuARMmaxSpeed(void)
{
    u32_t Buffer[5] = { 0 };
    if (mailbox_tag_message(&Buffer[0], 5, MBOX_TAG_GET_MAX_CLOCK_RATE, 8, 8, 3, 0))
        if (mailbox_tag_message(&Buffer[0], 5, MBOX_TAG_SET_CLOCK_RATE, 8, 8, 3, Buffer[4]))
            return (true);
    return (false);
}
