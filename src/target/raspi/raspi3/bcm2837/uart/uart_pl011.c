#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/bcm2837/uart_pl011.h"
#include "target/raspi/raspi3/bcm2837/gpio.h"
#include "target/raspi/raspi3/cpus/semaphore.h"
#include "arch/overworld/overworld.h"

extern struct uart_pl011_regs_t *uartpl011regs;

/* 
** We will provide step by step the uart pl011 bcs it is really long
*/

void *bcm2837_uartpl011_get_entrypoint(void)
{
    return ((void *)UART_PL011_ENTRY);
}

/* Register ptr getter */
static struct uart_pl011_dr_t *_bcm2837_uartpl011_getptr_dr(void)
{
    return ((struct uart_pl011_dr_t *)&uartpl011regs->dr);
}

static struct uart_pl011_rsrecr_t *_bcm2837_uartpl011_getptr_rsrecr(void)
{
    return ((struct uart_pl011_rsrecr_t *)&uartpl011regs->rsrecr);
}

static struct uart_pl011_fr_t *_bcm2837_uartpl011_getptr_fr(void)
{
    return ((struct uart_pl011_fr_t *)&uartpl011regs->fr);
}

static struct uart_pl011_ibrd_t *_bcm2837_uartpl011_getptr_ibrd(void)
{
    return ((struct uart_pl011_ibrd_t *)&uartpl011regs->ibrd);
}

static struct uart_pl011_fbrd_t *_bcm2837_uartpl011_getptr_fbrd(void)
{
    return ((struct uart_pl011_fbrd_t *)&uartpl011regs->fbrd);
}

static struct uart_pl011_lcrh_t *_bcm2837_uartpl011_getptr_lcrh(void)
{
    return ((struct uart_pl011_lcrh_t *)&uartpl011regs->lcrh);
}

static struct uart_pl011_cr_t *_bcm2837_uartpl011_getptr_cr(void)
{
    return ((struct uart_pl011_cr_t *)&uartpl011regs->cr);
}

static struct uart_pl011_ifls_t *_bcm2837_uartpl011_getptr_ifls(void)
{
    return ((struct uart_pl011_ifls_t *)&uartpl011regs->ifls);
}

static struct uart_pl011_imsc_t *_bcm2837_uartpl011_getptr_imsc(void)
{
    return ((struct uart_pl011_imsc_t *)&uartpl011regs->imsc);
}

static struct uart_pl011_ris_t *_bcm2837_uartpl011_getptr_ris(void)
{
    return ((struct uart_pl011_ris_t *)&uartpl011regs->ris);
}

static struct uart_pl011_mis_t *_bcm2837_uartpl011_getptr_mis(void)
{
    return ((struct uart_pl011_mis_t *)&uartpl011regs->mis);
}

static struct uart_pl011_icr_t *_bcm2837_uartpl011_getptr_icr(void)
{
    return ((struct uart_pl011_icr_t *)&uartpl011regs->icr);
}

static struct uart_pl011_dmacr_t *_bcm2837_uartpl011_getptr_dmacr(void)
{
    return ((struct uart_pl011_dmacr_t *)&uartpl011regs->dmacr);
}

static struct uart_pl011_itcr_t *_bcm2837_uartpl011_getptr_itcr(void)
{
    return ((struct uart_pl011_itcr_t *)&uartpl011regs->itcr);
}

static struct uart_pl011_itip_t *_bcm2837_uartpl011_getptr_itip(void)
{
    return ((struct uart_pl011_itip_t *)&uartpl011regs->itip);
}

/*
** Data register & sub Data register
*/ 

char bcm2837_uartpl011_get_data_nonfifo(void)
{
    return (_bcm2837_uartpl011_getptr_dr()->data);
}

void bcm2837_uartpl011_send_data_nonfifo(char send)
{
    _bcm2837_uartpl011_getptr_dr()->data = send;
}

void bcm2837_uartpl011_send_data_fifo(char *send, size_t sz)
{
    for (u32_t i = 0x0; i < sz; i++)
        _bcm2837_uartpl011_getptr_dr()->data = send[i];
}

char bcm2837_uartpl011_safeget_data_nonfifo(void)
{
    while(bcm2837_uartpl011_isTransmiterFull());
    return (_bcm2837_uartpl011_getptr_dr()->data);
}

char const *bcm2837_uartpl011_safesend_data_nonfifo(char send)
{
    while(bcm2837_uartpl011_isTransmiterFull());
    _bcm2837_uartpl011_getptr_dr()->data = send;
    return (bcm2837_uartpl011_error_checkup());
}

char const *bcm2837_uartpl011_safesend_data_fifo(char *send, size_t sz)
{
    while(bcm2837_uartpl011_isTransmiterFull());
    for (u32_t i = 0x0; i < sz; i++)
        _bcm2837_uartpl011_getptr_dr()->data = send[i];
    return (bcm2837_uartpl011_error_checkup());
}

char const *bcm2837_uartpl011_error_checkup(void)
{
    struct uart_pl011_dr_t *dr = _bcm2837_uartpl011_getptr_dr();
    struct uart_pl011_rsrecr_t *rsrecr = _bcm2837_uartpl011_getptr_rsrecr();
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

void bcm2837_uartpl011_disable(void)
{
    _bcm2837_uartpl011_getptr_cr()->uarten = false;
}

void bcm2837_uartpl011_enable(void)
{
    _bcm2837_uartpl011_getptr_cr()->uarten = true;
}

void bcm2837_uartpl011_setstate(bool val)
{
    _bcm2837_uartpl011_getptr_cr()->uarten = val;
}

void bcm2837_uartpl011_set_transmit_state(bool val)
{
    _bcm2837_uartpl011_getptr_cr()->txe = val;
}

void bcm2837_uartpl011_set_receive_state(bool val)
{
    _bcm2837_uartpl011_getptr_cr()->rxe = val;
}

void bcm2837_uartpl011_set_loopback_state(bool val)
{
    _bcm2837_uartpl011_getptr_cr()->lbe = val;
}

/*
** Flag register
*/ 

bool bcm2837_uartpl011_isTransmiterEmpty(void)
{
    return (_bcm2837_uartpl011_getptr_fr()->txfe);
}

bool bcm2837_uartpl011_isReceiverEmpty(void)
{
    return (_bcm2837_uartpl011_getptr_fr()->rxfe);
}

bool bcm2837_uartpl011_isTransmiterFull(void)
{
    return (_bcm2837_uartpl011_getptr_fr()->txff);
}

bool bcm2837_uartpl011_isReceiverFull(void)
{
    return (_bcm2837_uartpl011_getptr_fr()->rxff);
}

/* 
** Pin Mapping
** Already [un]mapp conventionnal pins 
*/
void bcm2837_uartpl011_mappin(pin_t pin)
{
    switch (pin)
    {
        case 14:
            bcm2837_gpio_set_mode(14, GPIO_ALTFUNC0);
            bcm2837_gpio_set_pullClock(14, GGPPUD_PULLDOWN);
            break;
        case 15:
            bcm2837_gpio_set_mode(15, GPIO_ALTFUNC0);
            bcm2837_gpio_set_pullClock(16, GGPPUD_PULLDOWN);
            break;
        case 16:
            bcm2837_gpio_set_mode(16, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(16, GGPPUD_PULLDOWN);
            break;
        case 17:
            bcm2837_gpio_set_mode(17, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(17, GGPPUD_PULLDOWN);
            break;
        case 30:
            bcm2837_gpio_set_mode(30, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(30, GGPPUD_PULLDOWN);
            break;
        case 31:
            bcm2837_gpio_set_mode(31, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(31, GGPPUD_PULLDOWN);
            break;
        case 32:
            bcm2837_gpio_set_mode(32, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(32, GGPPUD_PULLDOWN);
            break;
        case 33:
            bcm2837_gpio_set_mode(33, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(33, GGPPUD_PULLDOWN);
            break;
        case 36:
            bcm2837_gpio_set_mode(36, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(36, GGPPUD_PULLUP);
            break;
        case 37:
            bcm2837_gpio_set_mode(37, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(37, GGPPUD_PULLDOWN);
            break;
        case 38:
            bcm2837_gpio_set_mode(38, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(38, GGPPUD_PULLDOWN);
            break;
        case 39:
            bcm2837_gpio_set_mode(39, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(39, GGPPUD_PULLDOWN);
            break;
        default:
            break;
    }
}

void bcm2837_uartpl011_unmappin(pin_t pin)
{
    switch (pin)
    {
        case 14:
            bcm2837_gpio_set_mode(14, GPIO_ALTFUNC0);
            bcm2837_gpio_set_pullClock(14, GGPPUD_OFF);
            break;
        case 15:
            bcm2837_gpio_set_mode(15, GPIO_ALTFUNC0);
            bcm2837_gpio_set_pullClock(16, GGPPUD_OFF);
            break;
        case 16:
            bcm2837_gpio_set_mode(16, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(16, GGPPUD_OFF);
            break;
        case 17:
            bcm2837_gpio_set_mode(17, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(17, GGPPUD_OFF);
            break;
        case 30:
            bcm2837_gpio_set_mode(30, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(30, GGPPUD_OFF);
            break;
        case 31:
            bcm2837_gpio_set_mode(31, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(31, GGPPUD_OFF);
            break;
        case 32:
            bcm2837_gpio_set_mode(32, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(32, GGPPUD_OFF);
            break;
        case 33:
            bcm2837_gpio_set_mode(33, GPIO_ALTFUNC3);
            bcm2837_gpio_set_pullClock(33, GGPPUD_OFF);
            break;
        case 36:
            bcm2837_gpio_set_mode(36, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(36, GGPPUD_OFF);
            break;
        case 37:
            bcm2837_gpio_set_mode(37, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(37, GGPPUD_OFF);
            break;
        case 38:
            bcm2837_gpio_set_mode(38, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(38, GGPPUD_OFF);
            break;
        case 39:
            bcm2837_gpio_set_mode(39, GPIO_ALTFUNC2);
            bcm2837_gpio_set_pullClock(39, GGPPUD_OFF);
            break;
        default:
            break;
    }
}


/*
** Interrupt clear register
*/

void bcm2837_uartpl011_clear_transmit_interrupt(void)
{
    _bcm2837_uartpl011_getptr_icr()->txic = true;
}

void bcm2837_uartpl011_clear_receive_interrupt(void)
{
    _bcm2837_uartpl011_getptr_icr()->rxic = true;
}

/*
** baud rate divisor register
*/

u32_t bcm2837_uartpl011_get_baudrate_divisor(void)
{
    return (_bcm2837_uartpl011_getptr_ibrd()->ibrd);
}

void bcm2837_uartpl011_set_baudrate_divisor(u32_t div)
{
    _bcm2837_uartpl011_getptr_ibrd()->ibrd = (u16_t)div;
}

/*
** fractionnal baud rate divisor register
*/

u32_t bcm2837_uartpl011_get_fractionnal_baudrate_divisor(void)
{
    return (_bcm2837_uartpl011_getptr_fbrd()->fbrd);
}

void bcm2837_uartpl011_set_fractionnal_baudrate_divisor(u32_t frctdiv)
{
    _bcm2837_uartpl011_getptr_ibrd()->ibrd = (u8_t)frctdiv;
}

/*
** Line control register
*/

void bcm2837_uartpl011_send_break(void)
{
    _bcm2837_uartpl011_getptr_lcrh()->brk = true;
}

void bcm2837_uartpl011_set_parity(bool state)
{
    _bcm2837_uartpl011_getptr_lcrh()->pen= state;
}

void bcm2837_uartpl011_set_fifo(bool state)
{
    _bcm2837_uartpl011_getptr_lcrh()->fen = state;
}

void bcm2837_uartpl011_set_wlen(enum WLEN state)
{
    _bcm2837_uartpl011_getptr_lcrh()->wlen = state;
}