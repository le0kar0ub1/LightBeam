#ifndef __UART_H_
#define __UART_H_

#include "def/typedef.h"
#include "arch/aarch64/archutils.h"
#include <stdarg.h>

// https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2835/BCM2835-ARM-Peripherals.pdf (P180)

#define UART_PL011_ENTRY  ((volatile u32_t *)(ARCH_RASP_MMIOBASE + 0x00201000))

/* GPIO MAPPING *\
**
**  GPIO14: Pull-Low  TXD0  (ATL0)
**  GPIO15: Pull-Low  RXD0  (ATL0)
**  GPIO16: Pull-Low  CTS0  (ATL3)
**  GPIO17: Pull-Low  RTS0  (ATL3)
**  GPIO30: Pull-Low  CTS0  (ATL3)
**  GPIO31: Pull-Low  RTS0  (ATL3)
**  GPIO32: Pull-Low  TXD0  (ATL3)
**  GPIO33: Pull-Low  RXD0  (ATL3)
**  GPIO36: Pull-High TXD0  (ATL2)
**  GPIO37: Pull-Low  RXD0  (ATL2)
**  GPIO38: Pull-Low  RTS0  (ATL2)
**  GPIO39: Pull-Low  CTS0  (ATL2)
*/

enum WLEN
{
    UARTPLO11_WLEN_5 = 0b00,
    UARTPLO11_WLEN_6 = 0b01,
    UARTPLO11_WLEN_7 = 0b10,
    UARTPLO11_WLEN_8 = 0b11
};

enum FIFO_IO
{
    FIFOTX_12perc = 0b000,
    FIFOTX_25perc = 0b001,
    FIFOTX_50perc = 0b010,
    FIFOTX_75perc = 0b011,
    FIFOTX_88perc = 0b100
};

struct uart_pl011_dr_t
{
    s8_t data        : 8;
    u8_t err_framing : 1;
    u8_t err_parity  : 1;
    u8_t err_break   : 1;
    u8_t err_overrun : 1;
    u32_t _unused    : 20;
};

struct uart_pl011_rsrecr_t
{
    // Framing error. When set to 1, it indicates that the received character did not have a valid stop bit 
    u8_t err_framing : 1; 
    // Parity error. When set to 1, it indicates that the parity of the received data character does not match the parity that the EPS and SPS bits in the Line Control Register, UART_LCRH select
    u8_t err_parity  : 1;
    // Break error. This bit is set to 1 if a break condition was detected, indicating that the received data input was held LOW for longer than a full-word transmission time (defined as start, data, parity and stop bits). 
    u8_t err_break   : 1;
    // Overrun error. This bit is set to 1 if data is received and the receive FIFO is already full. 
    u8_t err_overrun : 1;
    u32_t _unused    : 28;
};

struct uart_pl011_fr_t
{
    u8_t  cts         : 1;
    u8_t  _unused_dsr : 1;
    u8_t  _unused_dcd : 1;
    u8_t  busy        : 1;
    u8_t  rxfe        : 1;
    u8_t  txff        : 1;
    u8_t  rxff        : 1;
    u8_t  txfe        : 1;
    u8_t  _unused_ri  : 1;
    u32_t _reserved   : 23;
};

struct uart_pl011_ibrd_t
{
    u32_t ibrd      : 16; // baud rate divisor
    u32_t _reserved : 16;
};

struct uart_pl011_fbrd_t
{
    u32_t fbrd      : 5; // fractionnal baud rate divisor
    u32_t _reserved : 27;
};

struct uart_pl011_lcrh_t
{
    u8_t      brk       : 1; // send break
    u8_t      pen       : 1; // parity enable
    u8_t      eps       : 1; // [if parity set] even parity select
    u8_t      stp2      : 1; // if set, two stop data bit
    u8_t      fen       : 1; // if set, enable FIFO
    enum WLEN wlen      : 2; // lenght data transmit
    u8_t      sps       : 1; // Stick parity select
    u32_t     _reserved : 24;
};

struct uart_pl011_cr_t
{
    u8_t  uarten        : 1; // Uart enable
    u8_t  _unused_siren : 1;
    u8_t  _unused_sirlp : 1;
    u8_t  reserved0     : 4;
    u8_t  lbe           : 1; // if set, enable loopback
    u8_t  txe           : 1; // if set, enable transmit 
    u8_t  rxe           : 1; // if set, enbale receive
    u8_t  _unused_dtr   : 1;
    u8_t  rts           : 1; // request to send
    u8_t  _unused_out1  : 1;
    u8_t  _unused_out2  : 1;
    u8_t  rtsen         : 1; // request to send Hardware flow control enable
    u8_t  ctsen         : 1; // transmit send Hardware flow control enable
    u32_t _reserved     : 16; 
};

struct uart_pl011_ifls_t
{
    enum  FIFO_IO rxiflsel : 3;
    enum  FIFO_IO txiflsel : 3;
    u8_t  _unused_rxifpsel : 2;
    u8_t  _unused_txifpsel : 2;
    u32_t _reserved        : 22;
};

struct uart_pl011_imsc_t
{
    u8_t _unused_rimim  : 1; 
    u8_t ctsmim         : 1;
    u8_t _unused_dcdmim : 1;
    u8_t _unused_dsrmim : 1;
    u8_t rxim           : 1;
    u8_t txim           : 1;
    u8_t rtim           : 1;
    u8_t err_framing    : 1;
    u8_t err_parity     : 1;
    u8_t err_break      : 1;
    u8_t err_overrun    : 1;
    u32_t _reserved     : 21;
};

struct uart_pl011_ris_t
{
    u8_t  rirmis          : 1; // Unsupported, write zero 
    u8_t  ctsmis          : 1; // nUARTCTS modem interrupt status.
    u8_t  _unused_DCDRMIS : 1; // Unsupported, write zero
    u8_t  _unused_DSRRMIS : 1; // Unsupported, write zero
    u8_t  rxris           : 1; // Receive interrupt status raw
    u8_t  txris           : 1; // Transmit interrupt status raw
    u8_t  rtris           : 1; // Receive timeout interrupt status
    u8_t  feris           : 1; // Framing error interrupt status
    u8_t  peris           : 1; // Parity error interrupt status
    u8_t  beris           : 1; // Break error interrupt status
    u8_t  oeris           : 1; // Overrun error interrupt status
    u32_t _reserved       : 21;
};

struct uart_pl011_mis_t
{
    u8_t  rimmis           : 1; // Unsupported, write zero 
    u8_t  ctsmmis          : 1; // nUARTCTS modem interrupt status.
    u8_t  _unused_DCDRmMIS : 1; // Unsupported, write zero
    u8_t  _unused_DSRRmMIS : 1; // Unsupported, write zero
    u8_t  rxmis            : 1; // Receive interrupt status raw
    u8_t  txmis            : 1; // Transmit interrupt status raw
    u8_t  rtmis            : 1; // Receive timeout interrupt status
    u8_t  femis            : 1; // Framing error interrupt status
    u8_t  pemis            : 1; // Parity error interrupt status
    u8_t  bemis            : 1; // Break error interrupt status
    u8_t  oemis            : 1; // Overrun error interrupt status
    u32_t _reserved        : 21;
};

struct uart_pl011_icr_t
{
    u8_t  rimmic           : 1; // Unsupported, write zero 
    u8_t  ctsmmic          : 1; // nUARTCTS modem interrupt status.
    u8_t  _unused_DCDRmMIc : 1; // Unsupported, write zero
    u8_t  _unused_DSRRmMIc : 1; // Unsupported, write zero
    u8_t  rxic             : 1; // Receive interrupt status raw
    u8_t  txic             : 1; // Transmit interrupt status raw
    u8_t  rtic             : 1; // Receive timeout interrupt status
    u8_t  feic             : 1; // Framing error interrupt status
    u8_t  peic             : 1; // Parity error interrupt status
    u8_t  beic             : 1; // Break error interrupt status
    u8_t  oeic             : 1; // Overrun error interrupt status
    u32_t _reserved        : 21;
};

struct uart_pl011_dmacr_t
{
    u8_t  _unused_rxdma    : 1;
    u8_t  _unused_txdma    : 1;
    u8_t  _unused_dmaonerr : 1;
    u32_t _reserved        : 29;
};

struct uart_pl011_itcr_t
{
    u8_t  icr0      : 1;
    u8_t  icr1      : 1;
    u32_t _reserved : 30;
};

struct uart_pl011_itip_t
{
    u8_t  itip0       : 1;
    u8_t  _reserved0  : 2;
    u8_t  itip3       : 1;
    u32_t _reserved1  : 30;
};

struct uart_pl011_regs_t
{
    u32_t dr;          // 0x0  // Data Register
    u32_t rsrecr;      // 0x4  // Data Register
    u32_t _unused0;    // 0x8  //
    u32_t _unused1;    // 0xC  //
    u32_t _unused2;    // 0x10 //
    u32_t _unused3;    // 0x14 //
    u32_t fr;          // 0x18 // Flag Register
    u32_t _unused4;    // 0x1c //
    u32_t ilpr;        // 0x20 // not in use 32
    u32_t ibrd;        // 0x24 // Integer Baud rate divisor 32
    u32_t fbrd;        // 0x28 // Fractional Baud rate divisor 32
    u32_t lcrh;        // 0x2c // Line Control register 32
    u32_t cr;          // 0x30 // Control register 32
    u32_t ifls;        // 0x34 // Interupt FIFO Level Select Register 32
    u32_t imsc;        // 0x38 // Interupt Mask Set Clear Register 32
    u32_t ris;         // 0x3c // Raw Interupt Status Register 32
    u32_t mis;         // 0x40 // Masked Interupt Status Register 32
    u32_t icr;         // 0x44 // Interupt Clear Register 32
    u32_t dmacr;       // 0x48 // DMA Control Register 32
    u32_t _unused5;    // 0x4c //
    u32_t _unused6;    // 0x50 //
    u32_t _unused7;    // 0x54 //
    u32_t _unused8;    // 0x58 //
    u32_t _unused9;    // 0x5c //
    u32_t _unused10;   // 0x60 //
    u32_t _unused11;   // 0x64 //
    u32_t _unused12;   // 0x68 //
    u32_t _unused13;   // 0x6c //
    u32_t _unused14;   // 0x70 //
    u32_t _unused15;   // 0x74 //
    u32_t _unused16;   // 0x78 //
    u32_t _unused17;   // 0x7c //
    u32_t itcr;        // 0x80 // Test Control register 32
    u32_t itip;        // 0x84 // Integration test input reg 32
    u32_t itop;        // 0x88 // Integration test output reg 32
    u32_t tdr;         // 0x8c // Test Data reg 32 
};

void bcm2837_uartpl011_init(void);
void *bcm2837_uartpl011_get_entrypoint(void);

/*
** Data register & sub Data register
*/ 
char bcm2837_uartpl011_get_data_nonfifo(void);
char bcm2837_uartpl011_safeget_data_nonfifo(void);
void bcm2837_uartpl011_send_data_nonfifo(char);
void bcm2837_uartpl011_send_data_fifo(char *, size_t);
char const *bcm2837_uartpl011_safesend_data_nonfifo(char);
char const *bcm2837_uartpl011_safesend_data_fifo(char *, size_t);
char const *bcm2837_uartpl011_error_checkup(void);


/*
** Control Register
*/
void bcm2837_uartpl011_disable(void);
void bcm2837_uartpl011_enable(void);
void bcm2837_uartpl011_setstate(bool);
void bcm2837_uartpl011_set_transmit_state(bool);
void bcm2837_uartpl011_set_receive_state(bool);
void bcm2837_uartpl011_set_loopback_state(bool);

/*
** Flag register
*/ 
bool bcm2837_uartpl011_isTransmiterEmpty(void);
bool bcm2837_uartpl011_isReceiverEmpty(void);
bool bcm2837_uartpl011_isTransmiterFull(void);
bool bcm2837_uartpl011_isReceiverFull(void);

/*
**  Clear interrupt register
*/
void bcm2837_uartpl011_clear_transmit_interrupt(void);
void bcm2837_uartpl011_clear_receive_interrupt(void);

/*
** Pin mapp/unmapp
*/
void bcm2837_uartpl011_mappin(u32_t);
void bcm2837_uartpl011_unmappin(u32_t);

/*
** baud rate divisor register
*/
u32_t bcm2837_uartpl011_get_baudrate_divisor(void);
void bcm2837_uartpl011_set_baudrate_divisor(u32_t);

/*
** fractionnal baud rate divisor register
*/
u32_t bcm2837_uartpl011_get_fractionnal_baudrate_divisor(void);
void bcm2837_uartpl011_set_fractionnal_baudrate_divisor(u32_t);

/*
** Line control register
*/
void bcm2837_uartpl011_send_break(void);
void bcm2837_uartpl011_set_parity(bool);
void bcm2837_uartpl011_set_fifo(bool);
void bcm2837_uartpl011_set_wlen(enum WLEN);

void uart_kprint(char const *, ...);

#endif