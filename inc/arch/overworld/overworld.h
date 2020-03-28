#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include "def/typedef.h"
#include <stdbool.h>
#include <stdarg.h>

u32_t strlen(char const *);

/* Memory instrument */
void *memcpy(void *, const void *, size_t);
void *memcpyv(void *, const void *, size_t, u8_t);
bool memcmp(const void *, const void *, size_t);
void *memset(void *, int, size_t);

/* String instrument */
bool strcmp(char const *, char const *);
bool strncmp(char const *, char const *, size_t);

/* Str to Nbr */
u8_t fromPrefixToBase(char const **);
s32_t atoi(char const *);
s32_t atoib(char const *, u8_t);
s64_t atol(char const *);
s64_t atolb(char const *, u8_t);

/* Generic printf with assigned printer */
void generic_printf(void (*)(char), char const *, ...);
void __generic_printf(char const *, __builtin_va_list);
void generic_printf_switch_type(char const **, __builtin_va_list *);
void generic_base_longput(long, int);
void generic_base_intput(int, int);
void generic_puts(char const *);

#endif