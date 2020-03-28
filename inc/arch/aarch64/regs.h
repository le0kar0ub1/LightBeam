#ifndef __FRAME_REGISTER_H_
#define __FRAME_REGISTER_H_

#include "def/typedef.h"

struct rframe_t
{
    uint64 x30;
    uint64 x29;
    uint64 x28;
    uint64 x27;
    uint64 x26;
    uint64 x25;
    uint64 x24;
    uint64 x23;
    uint64 x22;
    uint64 x21;
    uint64 x20;
    uint64 x19;
    uint64 x18;
    uint64 x17;
    uint64 x16;
    uint64 x15;
    uint64 x14;
    uint64 x13;
    uint64 x12;
    uint64 x11;
    uint64 x10;
    uint64 x9;
    uint64 x8;
    uint64 x7;
    uint64 x6;
    uint64 x5;
    uint64 x4;
    uint64 x3;
    uint64 x2;
    uint64 x1;
    uint64 x0;

    uint64 sp;
    uint64 pc;
    uint64 pstate;
    uint64 origin;
    uint64 syscall;
};

#endif