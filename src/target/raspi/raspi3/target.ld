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
        PROVIDE(__initcall_start = .);
        KEEP(*(.initcall_0.text))
        KEEP(*(.initcall_1.text))
        KEEP(*(.initcall_2.text))
        KEEP(*(.initcall_3.text))
        KEEP(*(.initcall_4.text))
        KEEP(*(.initcall_5.text))
        KEEP(*(.initcall_6.text))
        KEEP(*(.initcall_7.text))
        KEEP(*(.initcall_8.text))
        KEEP(*(.initcall_9.text))
        PROVIDE(__initcall_end = .);
    }

    .exitcall ALIGN(8) :
    {
        PROVIDE(__exitcall_start = .);
        KEEP(*(.exitcall_9.text))
        KEEP(*(.exitcall_8.text))
        KEEP(*(.exitcall_7.text))
        KEEP(*(.exitcall_6.text))
        KEEP(*(.exitcall_5.text))
        KEEP(*(.exitcall_4.text))
        KEEP(*(.exitcall_3.text))
        KEEP(*(.exitcall_2.text))
        KEEP(*(.exitcall_1.text))
        KEEP(*(.exitcall_0.text))
        PROVIDE(__exitcall_end = .);
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