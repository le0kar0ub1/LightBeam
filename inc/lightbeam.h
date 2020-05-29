#ifndef _LIGHTBEAM_H_
#define _LIGHTBEAM_H_

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <stddef.h>

#include "kernel/def/typedef.h"
#include "kernel/def/keyword.h"
#include "kernel/def/assert.h"
#include "kernel/def/bitfield.h"
#include "kernel/def/operator.h"
#include "kernel/def/macro.h"

#include "kernel/init/inithooks.h"
#include "kernel/init/initcalls.h"

#include "kernel/io.h"
#include "kernel/ksymtab.h"
#include "kernel/mm/align.h"
#include "kernel/mm/memory.h"

#include "kernel/schedule/semaphore.h"
#include "kernel/cpus/vmulticore.h"

#include "kernel/lib/lib.h"
#include "kernel/lib/printf.h"

void helloFromLightBeam(void);

#endif