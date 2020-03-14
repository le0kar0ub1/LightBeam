#include "target/raspi/raspi3/mbox.h"
#include "target/raspi/raspi3/driver/led.h"
#include "def/typedef.h"
#include <stdbool.h>

bool ledState = false;

void set_ACT_LED(bool set)
{
    mbox[0] = 8*4;
    mbox[7] = 0;
    mbox[1] = 0;
    mbox[2] = 0x00038041;
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = 130;
    mbox[6] = (uint32)set;
    mbox_call(0x8);
    ledState = set;
}

void inv_ACT_LED(void)
{
    ledState = !ledState;
    set_ACT_LED(ledState);
}