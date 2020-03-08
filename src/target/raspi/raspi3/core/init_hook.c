#include "target/raspi/raspi3/uart.h"
#include "target/raspi/raspi3/driver/lfb.h"

extern uchar __end;

#define COUNTER_SECTOR 1

void init_hook(void)
{
    // use the last 4 bytes on the second sector as a boot counter
    // uint *counter = (uint*)(&__end + 508);
    uart_init();

    uart_puts("HELLO WORLD!\n");

    lfb_init();

    lfb_print(10, 5, "Hello World!");
    // initialize EMMC and detect SD card type
    // if(sd_init() == SD_OK) {
    //     // read the second sector after our bss segment
    //     if(sd_readblock(COUNTER_SECTOR,&__end,1)) {
    //         // increase boot counter
    //         (*counter)++;
    //         // save the sector
    //         if(sd_writeblock(&__end,COUNTER_SECTOR,1)) {
    //             uart_puts("Boot counter ");
    //             uart_hex(*counter);
    //             uart_puts(" written to SD card.\n");
    //         }
    //     }
    // }
    while(1)
        uart_send(uart_getc());
}