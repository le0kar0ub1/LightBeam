#include "def/typedef.h"
#include "def/keyword.h"
#include "target/raspi/raspi3/driver/fb.h"
#include "target/raspi/raspi3/semaphore.h"
#include "arch/overworld/generic_printf.h"
#include <stdarg.h>

static bool iserasing;

void lfb_printfhandler_modcolor(u64_t color)
{
    lfb_set_color(RGB_Black, (u32_t)color);
}

void lfb_printfhandler_bckcolor(void)
{
    lfb_set_color(RGB_Black, RGB_White);
}

void lfb_printfhandler_noerasing(void)
{
    iserasing = false;
}

static struct printfhandlers_t lfb_printfhandlers[] =
{
    {"$A", NULL, lfb_printfhandler_modcolor},
    {"$R", lfb_printfhandler_bckcolor, NULL},
    {"\r", lfb_printfhandler_noerasing, NULL},
    {NULL, NULL, NULL}
};

static inline void lfb_endprint(int posx, int posy)
{
    if (!iserasing)
        lfb_set_pos(posx, posy);
}

smplock_t lock = SMPLOCK_INIT;

void lfb_kprint(char const *fmt, ...)
{
    int posx = lfb_get_posx();
    int posy = lfb_get_posy();
    semaphore_inc(&lock);
    iserasing = true;
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    generic_vprintf(lfb_putchar, &(*lfb_printfhandlers), fmt, ap);
    __builtin_va_end(ap);
    lfb_endprint(posx, posy);
    semaphore_dec(&lock);
}