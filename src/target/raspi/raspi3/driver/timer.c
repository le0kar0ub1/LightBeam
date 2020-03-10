#include "arch/aarch64/aarchutils.h"
#include "target/raspi/raspi3/interrupt.h"
#include "target/raspi/raspi3/gpio.h"
#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/timer.h"

const uint interval = 200000;
uint curVal = 0;

void timer_init(void)
{
    curVal = get32(TIMER_CLO);
    curVal += interval;
    put32(TIMER_C1, curVal);
}

void handle_timer_irq(void) 
{
    curVal += interval;
    put32(TIMER_C1, curVal);
    put32(TIMER_CS, TIMER_CS_M1);
    uart_puts("Timer interrupt received\n\r");
}
