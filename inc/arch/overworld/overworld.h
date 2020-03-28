#ifndef __OVERWORLD_H_
#define __OVERWORLD_H_

#include "def/typedef.h"
#include <stdbool.h>
#include <stdarg.h>

uint32 strlen(char const *);

/* Memory instrument */
void *memcpy(void *, const void *, size_t);
void *memcpyv(void *, const void *, size_t, uint8);
bool memcmp(const void *, const void *, size_t);
void *memset(void *, int, size_t);

/* Str to Nbr */
uint8 fromPrefixToBase(char const **);
int32 atoi(char const *);
int32 atoib(char const *, uint8);
int64 atol(char const *);
int64 atolb(char const *, uint8);

/* Generic printf with assigned printer */
void generic_printf(void (*)(char), char const *, ...);
void __generic_printf(char const *, __builtin_va_list);
void generic_printf_switch_type(char const **, __builtin_va_list *);
void generic_base_longput(long, int);
void generic_base_intput(int, int);
void generic_puts(char const *);

#endif