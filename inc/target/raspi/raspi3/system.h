#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include <stdarg.h>

void helloFromLightBleam(void);
void init_hook(void);
void start_setup_log(char const *);
void end_setup_log(char const *);

void PANIC(char const *, ...);

#endif