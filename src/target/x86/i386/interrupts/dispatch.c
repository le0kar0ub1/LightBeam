#include "target/x86/common/interrupts/interrupts.h"
#include "target/x86/x86.h"

void interrupt_dispatch(struct intframe *frame)
{
    exceptions_handler(frame);
}