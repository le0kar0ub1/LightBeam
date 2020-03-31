#include "def/typedef.h"
#include "def/keyword.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/semaphore.h"
#include "arch/overworld/generic_printf.h"
#include <stdarg.h>

static bool iserasing;

void rpifb_printfhandler_modcolor(u64_t color)
{
    rpifb_set_color(RGB_Black, (u32_t)color);
}

void rpifb_printfhandler_bckcolor(void)
{
    rpifb_set_color(RGB_Black, RGB_White);
}

void rpifb_printfhandler_noerasing(void)
{
    iserasing = false;
}

static struct printfhandlers_t rpifb_printfhandlers[] =
{
    {"$A", NULL, rpifb_printfhandler_modcolor},
    {"$R", rpifb_printfhandler_bckcolor, NULL},
    {"\r", rpifb_printfhandler_noerasing, NULL},
    {NULL, NULL, NULL}
};

static inline void rpifb_endprint(int posx, int posy)
{
    if (!iserasing)
        rpifb_set_pos(posx, posy);
}

smplock_t lock = SMPLOCK_INIT;

void rpifb_kprint(char const *fmt, ...)
{
    int posx = rpifb_get_posx();
    int posy = rpifb_get_posy();
    semaphore_inc(&lock);
    iserasing = true;
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(rpifb_putc, &(*rpifb_printfhandlers), fmt, ap);
    __builtin_va_end(ap);
    rpifb_endprint(posx, posy);
    semaphore_dec(&lock);
}