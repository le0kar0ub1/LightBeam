OUTPUT(aarch64)
ENTRY(_start)

PROVIDE(__entry_point = 0x80000);

SECTIONS
{
    .init (NOLOAD):
    {
        *(.init)
    }

    . = __entry_point;
    __start = .;

    PROVIDE(__text_start = .);
    .text :
    {
        KEEP(*(.text.boot))
        *(.text)
        *(.init.text)
        *(.exit.text)
        *(.iplt)
        *(.text.*)
    }
    . = ALIGN(4096);
    PROVIDE(__text_end = .);
 
    .initcall ALIGN(8) :
    {
        PROVIDE(__inithook_start = .);
        KEEP(*(.inithook_0.text))
        KEEP(*(.inithook_1.text))
        KEEP(*(.inithook_2.text))
        KEEP(*(.inithook_3.text))
        KEEP(*(.inithook_4.text))
        KEEP(*(.inithook_5.text))
        KEEP(*(.inithook_6.text))
        KEEP(*(.inithook_7.text))
        KEEP(*(.inithook_8.text))
        KEEP(*(.inithook_9.text))
        PROVIDE(__inithook_end = .);
    }

    .exitcall ALIGN(8) :
    {
        PROVIDE(__exithook_start = .);
        KEEP(*(.exithook_9.text))
        KEEP(*(.exithook_8.text))
        KEEP(*(.exithook_7.text))
        KEEP(*(.exithook_6.text))
        KEEP(*(.exithook_5.text))
        KEEP(*(.exithook_4.text))
        KEEP(*(.exithook_3.text))
        KEEP(*(.exithook_2.text))
        KEEP(*(.exithook_1.text))
        KEEP(*(.exithook_0.text))
        PROVIDE(__exithook_end = .);
    }

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


    /* CORES STACK PROVIDING */
    .stack_core0 :
    {
        . = ALIGN(16);
        PROVIDE(__stack_start_core0__ = .);
        . = . + 512;
        PROVIDE(__EL0_stack_core0 = .);
        . = . + 32768;
        PROVIDE(__EL1_stack_core0 = .);
        . = . + 4096;
        PROVIDE(__EL2_stack_core0 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core0__ = .);
    }

    .stack_core1 :
    {
        . = ALIGN(16);
        PROVIDE(__stack_start_core1__ = .);
        . = . + 512;
        PROVIDE(__EL0_stack_core1 = .);
        . = . + 32768;
        PROVIDE(__EL1_stack_core1 = .);
        . = . + 4096;
        PROVIDE(__EL2_stack_core1 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core1__ = .);
    }

    .stack_core2 :
    {
        . = ALIGN(16);
        PROVIDE(__stack_start_core2__ = .);
        . = . + 512;
        PROVIDE(__EL0_stack_core2 = .);
        . = . + 32768;
        PROVIDE(__EL1_stack_core2 = .);
        . = . + 4096;
        PROVIDE(__EL2_stack_core2 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core2__ = .);
    }

    .stack_core3 :
    {
        . = ALIGN(16);
        PROVIDE(__stack_start_core3__ = .);
        . = . + 512;
        PROVIDE(__EL0_stack_core3 = .);
        . = . + 32768;
        PROVIDE(__EL1_stack_core3 = .);
        . = . + 4096;
        PROVIDE(__EL2_stack_core3 = .);
        . = ALIGN(16);
        PROVIDE(__stack_end_core3__ = .);
    }

    PROVIDE(__KEND = .);

    /DISCARD/ : { *(.comment) }
    /DISCARD/ : { *(.gnu*) }
    /DISCARD/ : { *(.note*) }
    /DISCARD/ : { *(.eh_frame*) }
    /DISCARD/ : { *(.interp*)}
}