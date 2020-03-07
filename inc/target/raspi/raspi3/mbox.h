#ifndef __MBOX_H_
#define __MBOX_H_

#include "def/typedef.h"

/* a properly aligned buffer */
extern volatile unsigned int mbox[36];

#define MBOX_REQUEST    0

/* channels */
#define MBOX_CH_POWER   0
#define MBOX_CH_FB      1
#define MBOX_CH_VUART   2
#define MBOX_CH_VCHIQ   3
#define MBOX_CH_LEDS    4
#define MBOX_CH_BTNS    5
#define MBOX_CH_TOUCH   6
#define MBOX_CH_COUNT   7
#define MBOX_CH_PROP    8

/* tags */
#define MBOX_TAG_SETPOWER       0x28001
#define MBOX_TAG_SETCLKRATE     0x38002
#define MBOX_TAG_LAST           0

int mbox_call(uchar);

struct MMIO_IO
{
    uint channel : 4;
    uint data    : 28; 
};

struct MMIO_STATUS
{
    uint _unused : 30;
    uint empty   : 1;
    uint full    : 1; 
};

#endif