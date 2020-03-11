ENTRY(_start)
 
SECTIONS
{
    .init (NOLOAD):
    {
        *(.init)
    }

    . = 0x80000;
    __start = .;

    PROVIDE(__text_start = .);
    .text :
    {
        KEEP(*(.text.boot))
        *(.text .text.*)
    }
    . = ALIGN(4096);
    PROVIDE(__text_end = .);
 
    PROVIDE(__rodata_start = .);
    .rodata :
    {
        *(.rodata)
    }
    . = ALIGN(4096);
    PROVIDE(__rodata_end = .);
 
    PROVIDE(__data_start = .);
    .data :
    {
        *(.data)
    }
    . = ALIGN(4096);
    PROVIDE(__data_end = .);
 
    PROVIDE(__bss_start = .);
    .bss :
    {
        bss = .;
        *(.bss)
    }
    . = ALIGN(4096);
    PROVIDE(__bss_end = .);
    PROVIDE(__bss_size = __bss_end - __bss_start);




    .stack_core0 :
    {
        . = ALIGN(16);  /* Stack must always be aligned to 8 byte boundary AAPCS64 call standard */
        PROVIDE(__stack_start_core0__ = .);
        . = . + 512;    /* EL0 stack size */
        PROVIDE(__EL0_stack_core0 = .);
        . = . + 32768;  /* EL1 stack size */
        PROVIDE(__EL1_stack_core0 = .);
        . = . + 4096;   /* EL2 stack size (start-up) */
        PROVIDE(__EL2_stack_core0 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core0__ = .);
    }

    .stack_core1 :
    {
        . = ALIGN(16);  /* Stack must always be aligned to 8 byte boundary AAPCS64 call standard */
        PROVIDE(__stack_start_core1__ = .);
        . = . + 512;    /* EL0 stack size */
        PROVIDE(__EL0_stack_core1 = .);
        . = . + 32768;  /* EL1 stack size */
        PROVIDE(__EL1_stack_core1 = .);
        . = . + 4096;   /* EL2 stack size (start-up) */
        PROVIDE(__EL2_stack_core1 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core1__ = .);
    }

    .stack_core2 :
    {
        . = ALIGN(16);  /* Stack must always be aligned to 8 byte boundary AAPCS call standard */
        PROVIDE(__stack_start_core2__ = .);
        . = . + 512;    /* EL0 stack size */
        PROVIDE(__EL0_stack_core2 = .);
        . = . + 32768;  /* EL1 stack size */
        PROVIDE(__EL1_stack_core2 = .);
        . = . + 4096;   /* EL2 stack size (start-up) */
        PROVIDE(__EL2_stack_core2 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core2__ = .);
    }

    .stack_core3 :
    {
        . = ALIGN(16);  /* Stack must always be aligned to 8 byte boundary AAPCS call standard */
        PROVIDE(__stack_start_core3__ = .);
        . = . + 512;    /* EL0 stack size */
        PROVIDE(__EL0_stack_core3 = .);
        . = . + 32768;  /* EL1 stack size */
        PROVIDE(__EL1_stack_core3 = .);
        . = . + 4096;   /* EL2 stack size (start-up) */
        PROVIDE(__EL2_stack_core3 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core3__ = .);
    }



    PROVIDE(__end = .);

    /* /DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) } */
}