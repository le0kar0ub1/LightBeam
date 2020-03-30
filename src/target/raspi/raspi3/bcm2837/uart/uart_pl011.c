#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/bcm2837/uart_pl011.h"
#include "target/raspi/raspi3/bcm2837/gpio.h"
#include "target/raspi/raspi3/cpus/semaphore.h"
#include "arch/overworld/overworld.h"

extern struct uart_pl011_regs_t *uartpl011regs;

/* 
** We will provide step by step the uart pl011 bcs it is really long
*/

void *uartpl011_bcm2837_get_entrypoint(void)
{
    return ((void *)UART_PL011_ENTRY);
}

/* Register ptr getter */
static struct uart_pl011_dr_t *_uartpl011_bcm2837_getptr_dr(void)
{
    return ((struct uart_pl011_dr_t *)&uartpl011regs->dr);
}

static struct uart_pl011_rsrecr_t *_uartpl011_bcm2837_getptr_rsrecr(void)
{
    return ((struct uart_pl011_rsrecr_t *)&uartpl011regs->rsrecr);
}

static struct uart_pl011_fr_t *_uartpl011_bcm2837_getptr_fr(void)
{
    return ((struct uart_pl011_fr_t *)&uartpl011regs->fr);
}

static struct uart_pl011_ibrd_t *_uartpl011_bcm2837_getptr_ibrd(void)
{
    return ((struct uart_pl011_ibrd_t *)&uartpl011regs->ibrd);
}

static struct uart_pl011_fbrd_t *_uartpl011_bcm2837_getptr_fbrd(void)
{
    return ((struct uart_pl011_fbrd_t *)&uartpl011regs->fbrd);
}

static struct uart_pl011_lcrh_t *_uartpl011_bcm2837_getptr_lcrh(void)
{
    return ((struct uart_pl011_lcrh_t *)&uartpl011regs->lcrh);
}

static struct uart_pl011_cr_t *_uartpl011_bcm2837_getptr_cr(void)
{
    return ((struct uart_pl011_cr_t *)&uartpl011regs->cr);
}

static struct uart_pl011_ifls_t *_uartpl011_bcm2837_getptr_ifls(void)
{
    return ((struct uart_pl011_ifls_t *)&uartpl011regs->ifls);
}

static struct uart_pl011_imsc_t *_uartpl011_bcm2837_getptr_imsc(void)
{
    return ((struct uart_pl011_imsc_t *)&uartpl011regs->imsc);
}

static struct uart_pl011_ris_t *_uartpl011_bcm2837_getptr_ris(void)
{
    return ((struct uart_pl011_ris_t *)&uartpl011regs->ris);
}

static struct uart_pl011_mis_t *_uartpl011_bcm2837_getptr_mis(void)
{
    return ((struct uart_pl011_mis_t *)&uartpl011regs->mis);
}

static struct uart_pl011_icr_t *_uartpl011_bcm2837_getptr_icr(void)
{
    return ((struct uart_pl011_icr_t *)&uartpl011regs->icr);
}

static struct uart_pl011_dmacr_t *_uartpl011_bcm2837_getptr_dmacr(void)
{
    return ((struct uart_pl011_dmacr_t *)&uartpl011regs->dmacr);
}

static struct uart_pl011_itcr_t *_uartpl011_bcm2837_getptr_itcr(void)
{
    return ((struct uart_pl011_itcr_t *)&uartpl011regs->itcr);
}

static struct uart_pl011_itip_t *_uartpl011_bcm2837_getptr_itip(void)
{
    return ((struct uart_pl011_itip_t *)&uartpl011regs->itip);
}

/*
** Data register & sub Data register
*/ 

void uartpl011_bcm2837_send_data_nonfifo(char send)
{
    _uartpl011_bcm2837_getptr_dr()->data = send;
}

void uartpl011_bcm2837_send_data_fifo(char *send, size_t sz)
{
    for (u32_t i = 0x0; i < sz; i++)
        _uartpl011_bcm2837_getptr_dr()->data = send[i];
}

char const *uartpl011_bcm2837_safesend_data_nonfifo(char send)
{
    while(uartpl011_bcm2837_isTransmiterFull());
    _uartpl011_bcm2837_getptr_dr()->data = send;
    return (uartpl011_bcm2837_error_checkup());
}

char const *uartpl011_bcm2837_safesend_data_fifo(char *send, size_t sz)
{
    while(uartpl011_bcm2837_isTransmiterFull());
    for (u32_t i = 0x0; i < sz; i++)
        _uartpl011_bcm2837_getptr_dr()->data = send[i];
    return (uartpl011_bcm2837_error_checkup());
}

char const *uartpl011_bcm2837_error_checkup(void)
{
    struct uart_pl011_dr_t *dr = _uartpl011_bcm2837_getptr_dr();
    struct uart_pl011_rsrecr_t *rsrecr = _uartpl011_bcm2837_getptr_rsrecr();
    if (dr->err_framing || rsrecr->err_framing)
        return ("framing");
    if (dr->err_parity || rsrecr->err_parity)
        return ("parity");
    if (dr->err_break || rsrecr->err_break)
        return ("break");
    if (dr->err_overrun || rsrecr->err_overrun)
        return ("overrun");
    return (NULL);
}

/*
** Control Register
*/

void uartpl011_bcm2837_disable(void)
{
    _uartpl011_bcm2837_getptr_cr()->uarten = false;
}

void uartpl011_bcm2837_enable(void)
{
    _uartpl011_bcm2837_getptr_cr()->uarten = true;
}

void uartpl011_bcm2837_setstate(bool val)
{
    _uartpl011_bcm2837_getptr_cr()->uarten = val;
}

void uartpl011_bcm2837_set_transmit_state(bool val)
{
    _uartpl011_bcm2837_getptr_cr()->txe = val;
}

void uartpl011_bcm2837_set_receive_state(bool val)
{
    _uartpl011_bcm2837_getptr_cr()->rxe = val;
}

void uartpl011_bcm2837_set_loopback_state(bool val)
{
    _uartpl011_bcm2837_getptr_cr()->lbe = val;
}

/*
** Flag register
*/ 

bool uartpl011_bcm2837_isTransmiterEmpty(void)
{
    return (_uartpl011_bcm2837_getptr_fr()->txfe);
}

bool uartpl011_bcm2837_isReceiverEmpty(void)
{
    return (_uartpl011_bcm2837_getptr_fr()->rxfe);
}

bool uartpl011_bcm2837_isTransmiterFull(void)
{
    return (_uartpl011_bcm2837_getptr_fr()->txff);
}

bool uartpl011_bcm2837_isReceiverFull(void)
{
    return (_uartpl011_bcm2837_getptr_fr()->rxff);
}

/* 
** Pin Mapping
** Already [un]mapp conventionnal pins 
*/
void uartpl011_bcm2837_mappin(pin_t pin)
{
    switch (pin)
    {
        case 14:
            gpio_bcm2837_set_mode(14, GPIO_ALTFUNC0);
            gpio_bcm2837_set_pullClock(14, GGPPUD_OFF);
            break;
        case 15:
            gpio_bcm2837_set_mode(14, GPIO_ALTFUNC0);
            gpio_bcm2837_set_pullClock(14, GGPPUD_OFF);
            break;
        case 16:
            
            break;
        case 17:
            
            break;
        case 30:
            
            break;
        case 31:
            
            break;
        case 32:
            
            break;
        case 33:
            
            break;
        case 36:
            
            break;
        case 37:
            
            break;
        case 38:
            
            break;
        case 39:
            
            break;
        default:
            break;
    }
}


/*
** Interrupt clear register
*/

void uartpl011_bcm2837_clear_transmit_interrupt(void)
{
    _uartpl011_bcm2837_getptr_icr()->txic = true;
}

void uartpl011_bcm2837_clear_receive_interrupt(void)
{
    _uartpl011_bcm2837_getptr_icr()->rxic = true;
}

/*
** baud rate divisor register
*/

u32_t uartpl011_bcm2837_get_baudrate_divisor(void)
{
    return (_uartpl011_bcm2837_getptr_ibrd()->ibrd);
}

void uartpl011_bcm2837_set_baudrate_divisor(u32_t div)
{
    _uartpl011_bcm2837_getptr_ibrd()->ibrd = (u16_t)div;
}

/*
** fractionnal baud rate divisor register
*/

u32_t uartpl011_bcm2837_get_fractionnal_baudrate_divisor(void)
{
    return (_uartpl011_bcm2837_getptr_fbrd()->fbrd);
}

void uartpl011_bcm2837_set_fractionnal_baudrate_divisor(u32_t frctdiv)
{
    _uartpl011_bcm2837_getptr_ibrd()->ibrd = (u8_t)frctdiv;
}

/*
** Line control register
*/

void uartpl011_bcm2837_send_break(void)
{
    _uartpl011_bcm2837_getptr_lcrh()->brk = true;
}

void uartpl011_bcm2837_set_parity(bool state)
{
    _uartpl011_bcm2837_getptr_lcrh()->pen= state;
}

void uartpl011_bcm2837_set_fifo(bool state)
{
    _uartpl011_bcm2837_getptr_lcrh()->fen = state;
}

void uartpl011_bcm2837_set_wlen(enum WLEN state)
{
    _uartpl011_bcm2837_getptr_lcrh()->wlen = state;
}