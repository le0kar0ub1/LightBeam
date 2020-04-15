#ifndef __I386_H_
#define __I386_H_

#include "target/x86/x86.h"

#define V2P(x) (x - __KERNEL_ADDR_TRNS)
#define P2V(x) (x + __KERNEL_ADDR_TRNS)

#endif