#include "kernel/ksymtab.h"
#include "kernel/lib/lib.h"

extern struct symbol_t __ksymtab_start[];
extern struct symbol_t __ksymtab_end[];

/*
** Search symbol in ksymtab by name
*/
static struct symbol_t *lookup_symbols_from_name(struct symbol_t *from, struct symbol_t *to, const char *name)
{
    struct symbol_t *next;

    if (!from || !to || !name)
        return (NULL);

    next = from;
    while (next < to) {
        if (strcmp(next->name, name))
            return (next);
        next++;
    }
    return (NULL);
}

/*
** Search symbol in ksymtab by addr
*/
static struct symbol_t *lookup_symbols_from_addr(struct symbol_t *from, struct symbol_t *to, void *addr)
{
    struct symbol_t *next;

    if (!from || !to || !addr)
        return (NULL);

    next = from;
    while (next < to) {
        if (next->addr == addr)
            return (next);
        next++;
    }
    return (NULL);
}

/*
** Get symbol addr in ksymtab from name
*/
void *__symbol_get_addr(const char * name)
{
    struct symbol_t * sym;

    if (!name)
        return (NULL);
    sym = lookup_symbols_from_name(&(*__ksymtab_start), &(*__ksymtab_end), name);
    return sym ? (void *)sym->addr : NULL;
}
EXPORT_SYMBOL(__symbol_get_addr);

/*
** Get symbol name in ksymtab from addr
*/
char const *__symbol_get_name(void *addr)
{
    struct symbol_t * sym;

    if (!addr)
        return (NULL);
    sym = lookup_symbols_from_addr(&(*__ksymtab_start), &(*__ksymtab_end), addr);
    return sym ? (char const *)sym->name : NULL;
}
EXPORT_SYMBOL(__symbol_get_name);