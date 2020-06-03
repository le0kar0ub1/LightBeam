#include "target/x86/common/interrupts/interrupts.h"
#include "target/x86/x86.h"

/*
** Call by the ISR
** Dispatch the interrupts by type
*/
void interrupt_dispatch(struct intframe *frame)
{
    void (*handler)(struct intframe *) = interrupt_get_specific_handler(frame->int_num);

    if (handler)
        handler(frame);
    else
        exceptions_handler(frame);
}