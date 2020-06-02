#include "target/aarch64/raspi/raspi3/interrupts/interrupt.h"
#include "target/aarch64/raspi/raspi3/cpus/cpus.h"
#include "target/aarch64/raspi/raspi3/drivers/fb.h"
#include "target/aarch64/raspi/raspi3/drivers/uart.h"
#include "arch/aarch64/archutils.h"

static const char * esr_class_str[] = 
{
    [0 ... 0x3f] = "UNRECOGNIZED EC", /* will be override */
    [0x00]  = "Unknown/Uncategorized",
    [0x01]  = "WFI/WFE",
    [0x03]  = "CP15 MCR/MRC",
    [0x04]  = "CP15 MCRR/MRRC",
    [0x05]  = "CP14 MCR/MRC",
    [0x06]  = "CP14 LDC/STC",
    [0x07]  = "ASIMD",
    [0x08]  = "CP10 MRC/VMRS",
    [0x0c]  = "CP14 MCRR/MRRC",
    [0x0e]  = "PSTATE.IL",
    [0x11]  = "SVC (AArch32)",
    [0x12]  = "HVC (AArch32)",
    [0x13]  = "SMC (AArch32)",
    [0x15]  = "SVC (AArch64)",
    [0x16]  = "HVC (AArch64)",
    [0x17]  = "SMC (AArch64)",
    [0x18]  = "MSR/MRS (AArch64)",
    [0x1f]  = "EL3 IMP DEF",
    [0x20]  = "IABT (lower EL)",
    [0x21]  = "IABT (current EL)",
    [0x22]  = "PC Alignment",
    [0x24]  = "DABT (lower EL)",
    [0x25]  = "DABT (current EL)",
    [0x26]  = "SP Alignment",
    [0x28]  = "FP (AArch32)",
    [0x2c]  = "FP (AArch64)",
    [0x2f]  = "SError",
    [0x30]  = "Breakpoint (lower EL)",
    [0x31]  = "Breakpoint (current EL)",
    [0x32]  = "Software Step (lower EL)",
    [0x33]  = "Software Step (current EL)",
    [0x34]  = "Watchpoint (lower EL)",
    [0x35]  = "Watchpoint (current EL)",
    [0x38]  = "BKPT (AArch32)",
    [0x3a]  = "Vector catch (AArch32)",
    [0x3c]  = "BRK (AArch64)",
};

void arm64_invalid_exception(struct rframe_t *regs, int reason, u32_t esr)
{
    const char * handler[] = 
    {
        "Synchronous Abort",
        "IRQ",
        "FIQ",
        "Error"
    };

    rpifb_kprint("Invalid exception in %s handler detected, code 0x%x -- %s\n", handler[reason], esr, esr_class_str[esr >> 26]);
    dump_regs(regs);
}

void arm64_sync_exception(struct rframe_t *regs)
{
    u64_t esr, far;
    u64_t ec, iss;

    esr = arm64_read_sysreg(esr_el1);
    far = arm64_read_sysreg(far_el1);
    ec = (esr >> 26) & 0x3f;
    iss = (esr >> 0) & 0x1ffffff;

    switch(ec)
    {
        case 0x3c:  /* BRK (AArch64) */
            if(iss == 0x401)
                regs->pc += 0x4;
            return;
        default:
            break;
    }
    rpifb_kprint("Synchronous exception detected, ec:0x%x iss:0x%x far:0x%x\n", ec, iss, far);
    dump_regs(regs);
    __deadloop();
}

void arm64_irq_exception(struct rframe_t *regs __unused)
{
    uart_kprint("IRQ triggered\n");
    // interrupt_handle_exception(regs);
}
