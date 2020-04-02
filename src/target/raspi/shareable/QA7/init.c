#include "lightbeam.h"
#include "target/raspi/shareable/QA7/QA7.h"

volatile struct bcm_qa7_regs_t *bcmQA7regs = NULL;

static void bcm_qa7_init(void)
{
    bcmQA7regs = (struct bcm_qa7_regs_t *)BCM_QA7_ENTRY;
}

boot_initcall(bcm_qa7_init);