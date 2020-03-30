#include "target/raspi/raspi3/bcm2837/uart-pl011.h"
#include "target/raspi/raspi3/bcm2837/mbox.h"
#include "target/raspi/raspi3/cpus/semaphore.h"
#include "arch/overworld/overworld.h"

extern volatile struct uart_pl011_regs_t *uartpl011regs;

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

void *uartpl011_bcm2837_disable(void)
{
    _uartpl011_bcm2837_getptr_cr()->uarten = false;
}

void *uartpl011_bcm2837_enable(void)
{
    _uartpl011_bcm2837_getptr_cr()->uarten = true;
}