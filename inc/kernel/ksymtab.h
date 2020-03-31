#ifndef __KSYMTAB_H__
#define __KSYMTAB_H__

#include "kernel/def/typedef.h"

struct symbol_t
{
    void *addr;
    const char *name;
};

#define EXPORT_SYMBOL(symbol) \
    extern typeof(symbol) symbol; \
    static const char __ksym_name_##symbol[] = #symbol; \
    static const struct symbol_t __ksymtab_##symbol \
    __attribute__((__used__, section(".ksymtab.text"))) = { (void *)&symbol, __ksym_name_##symbol }

#define symbol_get_name(x) ((typeof(&x))(__symbol_get_name(#x)))
#define symbol_get_addr(x) ((typeof(&x))(__symbol_get_addr(#x)))

char const *__symbol_get_name(void *);
void *__symbol_get_addr(const char *);

#endif
