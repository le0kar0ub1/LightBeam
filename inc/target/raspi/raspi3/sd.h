#ifndef __SD_H_
#define __SD_H_

#include "def/typedef.h"

#define SD_OK                0
#define SD_TIMEOUT          -1
#define SD_ERROR            -2

int sd_init(void);
int sd_readblock(uint, uchar *, uint);
int sd_writeblock(uchar *, uint, uint);

#endif