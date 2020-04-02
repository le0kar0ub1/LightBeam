#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "lightbeam.h"

void helloFromLightBeam(void);
void setup_level(void);
void system_charging(u32_t);

/* Classical kernel PANIC */
void PANIC(char const *, ...);

#endif