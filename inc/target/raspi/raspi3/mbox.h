#ifndef __MBOX_H_
#define __MBOX_H_

#include "def/typedef.h"

/* a properly aligned buffer */
extern volatile unsigned int mbox[36];

#define MBOX_REQUEST   0x0

/* channels */
#define MBOX_CH_POWER  0x0
#define MBOX_CH_FB     0x1
#define MBOX_CH_VUART  0x2
#define MBOX_CH_VCHIQ  0x3
#define MBOX_CH_LEDS   0x4
#define MBOX_CH_BTNS   0x5
#define MBOX_CH_TOUCH  0x6
#define MBOX_CH_COUNT  0x7
#define MBOX_CH_PROP   0x8

/* tags */
#define MBOX_TAG_SETPOWER   0x28001
#define MBOX_TAG_SETCLKRATE 0x38002
#define MBOX_TAG_LAST       0x0

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