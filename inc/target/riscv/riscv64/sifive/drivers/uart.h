#ifndef __RISCV_UART_
#define __RISCV_UART_

#include "target/riscv/riscv64/sifive/sifive.h"

struct uart_txdata_t
{
    uint32 data      : 8;
    uint32 _reserved : 23;
    uint32 status    : 1; // read -> if 0, can write
};

struct uart_rxdata_t
{
    uint32 data      : 8;
    uint32 _reserved : 23;
    uint32 status    : 1; // read -> if 0, can read
};

struct uart_txctrl_t
{
    uint32 txen       : 1; // transmit enable
    uint32 nstop      : 1; // stop bit number
    uint32 _reserved1 : 14;
    uint32 txcnt      : 3; // watermark level
    uint32 _reserved2 : 13;
};

struct uart_rxctrl_t
{
    uint32 rxen       : 1; // receive enable
    uint32 _reserved1 : 15;
    uint32 rxcnt      : 3; // watermark level
    uint32 _reserved2 : 13;
};

struct uart_ie_t
{
    uint32 txwm      : 1; // transmit int enable
    uint32 rxwm      : 1; // receive int enable
    uint32 _reserved : 30;
};

struct uart_ip_t
{
    uint32 txwm      : 1; // transmit int pending
    uint32 rxwm      : 1; // receive int pending
    uint32 _reserved : 30;
};

struct uart_div_t
{
    uint32 div       : 16; // divisor
    uint32 _reserved : 16;
};


struct sifive_uart_t
{
    struct uart_txdata_t txdata;
    struct uart_rxdata_t rxdata;
    struct uart_txctrl_t txctrl;
    struct uart_rxctrl_t txctrl;
    struct uart_ie_t     ie;
    struct uart_ip_t     ip;
    struct uart_div_t    div;
};

#endif