#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include <stdarg.h>

#define ARM_MODE_USR 0x10    /* Normal User Mode                                       */
#define ARM_MODE_FIQ 0x11    /* FIQ Processing Fast Interrupts Mode                    */
#define ARM_MODE_IRQ 0x12    /* IRQ Processing Standard Interrupts Mode                */
#define ARM_MODE_SVC 0x13    /* Supervisor Processing Software Interrupts Mode         */
#define ARM_MODE_ABT 0x17    /* Abort Processing memory Faults Mode                    */
#define ARM_MODE_UND 0x1B    /* Undefined Processing Undefined Instructions Mode       */
#define ARM_MODE_SYS 0x1F    /* System Running Priviledged Operating System Tasks Mode */

void helloFromLightBleam(void);
void init_hook(void);
void start_setup_log(char const *);
void end_setup_log(char const *);

/* Classical kernel PANIC */
void PANIC(char const *, ...);

#endif