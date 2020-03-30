#include "def/typedef.h"
#include "arch/overworld/overworld.h"
#include "arch/overworld/generic_printf.h"
#include "target/raspi/raspi3/cpus/semaphore.h"
#include <stdarg.h>

/* Caller printer */
static void (*caller_putc)(char) = NULL;
/* Caller handlers */
static struct printfhandlers_t *callerhandlers = NULL;

/* formatter */
static u32_t align  = false;
static bool  hshtag = false;

#ifdef PRINTF_BUFFERED
/* Printf buffer */
#define PRINTF_BUFFER_LENGHT 0x400
    static uint incbuf;
    static char prbuffer[PRINTF_BUFFER_LENGHT];

    static void printf_writeBuffer(char c)
    {
        if (incbuf >= PRINTF_BUFFER_LENGHT)
            return;
        prbuffer[incbuf] = c;
        incbuf += 0x1;
    }

    static void printf_dumpBuffer(void)
    {
        for (u32_t i = 0; i < incbuf; i++)
            caller_putc(prbuffer[i]);
        incbuf = 0x0;
    }
#endif

static void printf_handleWrite(char c)
{
#ifdef PRINTF_BUFFERED
    printf_writeBuffer(c);
#else
    caller_putc(c);
#endif
}

void multibase_put32(int n, u8_t base)
{
    if (n < 0) {
        printf_handleWrite('-');
        n = n * -1;
    }
    if (n >= base)
        multibase_put32(n / base, base);
    printf_handleWrite((n % base) + 0x30);
}

void multibase_put64(long n, u8_t base)
{
    if (n < 0) {
        printf_handleWrite('-');
        n = n * -1;
    }
    if (n >= base)
        multibase_put64(n / base, base);
    printf_handleWrite((n % base) + 0x30);
}

void multibase_uput32(unsigned int n, u8_t base)
{
    if (n >= base)
        multibase_put32(n / base, base);
    printf_handleWrite((n % base) + 0x30);
}

void multibase_uput64(unsigned long n, u8_t base)
{
    if (n >= base)
        multibase_put64(n / base, base);
    printf_handleWrite((n % base) + 0x30);
}

void generic_puts(char const *s)
{
    for (int i = 0; s[i]; i++)
        printf_handleWrite(s[i]);
}

static bool handle_caller_flg(char const **fmt, __builtin_va_list *ap)
{
    for (u32_t i = 0; callerhandlers[i].flg; i++)
        if (strncmp(callerhandlers[i].flg, *fmt, strlen(callerhandlers[i].flg))) {
            if (callerhandlers[i].handler0)
                callerhandlers[i].handler0();
            else if (callerhandlers[i].handler1)
                callerhandlers[i].handler1(__builtin_va_arg(*ap, long));
            else
                return (false);
            *fmt += strlen(callerhandlers[i].flg) - 1;
            return (true);
        }
    return (false);
}

static inline int printf_getAlignement(char const **fmt)
{
    #define MAX_HANDLED_ALIGNEMENT 4
    char tmp[0x5];
    u32_t i = 0x0;

    while ((*fmt)[i] && (*fmt)[i] <= 0x39 && (*fmt)[i] >= 0x30) {
        if (i > MAX_HANDLED_ALIGNEMENT)
            return (0x0);
        tmp[i] = (*fmt)[i];
        i++;
    }
    tmp[i] = 0x0;
    *fmt += i;
    return (atoib(tmp, 10));
}

static inline void printf_AlignFormat(u32_t len)
{
    if (len > align)
        return;
    len = align - len;
    while (len > 1) {
        printf_handleWrite(0x30);
        len--;
    }
}

static void printf_handleIntegerFormatter(u64_t n, u8_t base)
{
    if (align) {
        u32_t len = numberlen(n, base);
        printf_AlignFormat(len);
    }
}

static void printf_handleStringFormatter(char const *s)
{
    if (align) { 
        u32_t len = strlen(s);
        printf_AlignFormat(len);
    }
}

static void printf_handleHashTag(u8_t base)
{
    if (!hshtag)
        return;
    switch (base) {
        case 16:
            generic_puts("0x");
            break;
        case 8:
            generic_puts("0o");
            break;
        case 2:
            generic_puts("0b");
            break;
        default:
            break;
    }
}

static void generic_printf_hdlflg(char const **fmt, __builtin_va_list *ap)
{
    /* Caller flag wich can override the next one */
    if (callerhandlers && handle_caller_flg(fmt, ap))
        return;
    align  = false;
    hshtag = false;
    /* Formatter */
    bool flag = true;
    while (flag) {
        switch (**fmt) {
            case '0':
                *fmt += 0x1;
                align = printf_getAlignement(fmt);
                break;
            case '#':
                *fmt += 0x1;
                hshtag = true;
                break;
            default:
                flag = false;
                break;
        }
    }
    /* Init handled variable */
    static int vint;
    static uint vuint;
    static long vlong;
    static unsigned long vulong;
    static char const *vcchar;
    /* flag handled by this generic printf */
    switch (**fmt) {
        case 's':
            vcchar = __builtin_va_arg(*ap, char const *);
            printf_handleStringFormatter(vcchar);
            generic_puts(vcchar);
            break;
        case 'u':
            vuint = __builtin_va_arg(*ap, unsigned int);
            printf_handleIntegerFormatter((u64_t)vuint, 10);
            multibase_uput32(vuint, 10);
            break;
        case 'U':
            vulong = __builtin_va_arg(*ap, unsigned long);
            printf_handleIntegerFormatter((u64_t)vulong, 10);
            multibase_uput32(vulong, 10);
            break;
        case 'h':
        case 'd':
        case 'i':
            vint = __builtin_va_arg(*ap, int);
            printf_handleIntegerFormatter((u64_t)vint, 10);
            multibase_put32(vint, 10);
            break;
        case 'x':
            vint = __builtin_va_arg(*ap, int);
            printf_handleHashTag(16);
            printf_handleIntegerFormatter((u64_t)vint, 16);
            multibase_put32(vint, 16);
            break;
        case 'o':
            vint = __builtin_va_arg(*ap, int);
            printf_handleHashTag(8);
            printf_handleIntegerFormatter((u64_t)vint, 8);
            multibase_put32(vint, 8);
            break;
        case 'b':
            vint = __builtin_va_arg(*ap, int);
            printf_handleHashTag(2);
            printf_handleIntegerFormatter((u64_t)vint, 2);
            multibase_put32(vint, 2);
            break;
        case 'l':
            vlong = __builtin_va_arg(*ap, long);
            printf_handleIntegerFormatter((u64_t)vlong, 10);
            multibase_put64(vlong, 10);
            break;
        case 'X':
            vlong = __builtin_va_arg(*ap, long);
            printf_handleHashTag(16);
            printf_handleIntegerFormatter((u64_t)vlong, 16);
            multibase_put64(vlong, 16);
            break;
        case 'O':
            vlong = __builtin_va_arg(*ap, long);
            printf_handleHashTag(8);
            printf_handleIntegerFormatter((u64_t)vlong, 8);
            multibase_put64(vlong, 8);
            break;
        case 'B':
            vlong = __builtin_va_arg(*ap, long);
            printf_handleHashTag(2);
            printf_handleIntegerFormatter((u64_t)vlong, 2);
            multibase_put64(vlong, 2);
            break;
        case 'c':
            printf_handleWrite((char)__builtin_va_arg(*ap, int));
            break;
        case 'p':
            vulong = __builtin_va_arg(*ap, unsigned long);
            printf_handleHashTag(16);
            printf_handleIntegerFormatter((u64_t)vulong, 16);
            multibase_uput64((uintptr_t)__builtin_va_arg(*ap, void *), 16);
            break;
        #ifdef DEADLOCK_IS_SOFUNNY
            case 'F': /* take care of DEADLOCK if the function called use this printf its' over */
                __builtin_va_arg(*ap, void (*)(void))();
                break;
        #endif
        case '%':
            printf_handleWrite('%');
            break;
        default: // unknow flag => print this
            printf_handleWrite('%');
            printf_handleWrite(**fmt);
    }
}

void __generic_printf(char const *fmt, __builtin_va_list ap)
{
    while (*fmt) {
        if (*fmt != '%') {
            printf_handleWrite(*fmt);
        } else {
            fmt++;
            generic_printf_hdlflg(&fmt, &ap);
        }
        fmt++;
    }
}

static smplock_t lock = SMPLOCK_INIT;

#define GENERIC_PRINTF_INIT()   \
    semaphore_inc(&lock);       \
    if (!putc) {                \
        semaphore_dec(&lock);   \
        return;                 \
    } else                      \
        caller_putc = putc;     \
    callerhandlers = handlers;  \
    align = false;

#ifdef PRINTF_BUFFERED
    #define GENERIC_PRINTF_EXIT()    \
        printf_dumpBuffer();         \
        semaphore_dec(&lock);
#else
    #define GENERIC_PRINTF_EXIT()    \
        semaphore_dec(&lock);
#endif

void generic_vprintf(void (*putc)(char), struct printfhandlers_t *handlers, 
char const *fmt, __builtin_va_list ap)
{
    GENERIC_PRINTF_INIT();
    __generic_printf(fmt, ap);
    GENERIC_PRINTF_EXIT();
}

void generic_printf(void (*putc)(char), struct printfhandlers_t *handlers, 
char const *fmt, ...)
{
    GENERIC_PRINTF_INIT();
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    __generic_printf(fmt, ap);
    __builtin_va_end(ap);
    GENERIC_PRINTF_EXIT();
}