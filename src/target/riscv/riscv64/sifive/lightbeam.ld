ENTRY(_start)

PROVIDE(__entry_point = 0x80000000);
PROVIDE(__ram_entry   = 0x80000000);

SECTIONS
{
    . = __entry_point;

    .init :
    {
        PROVIDE(__init_start = .);
        *(.init)
        *(.boot)
        *(.init.text)
        *(.init.data)
        PROVIDE(__init_end = .);
    }

    .text :
    {
        PROVIDE(__text_start = .);
        *(.text)
        *(.text.*)
        PROVIDE(__text_end = .);
    }

    /*
    ** RISCV relax au max
    */
    .sdata :
    {
        PROVIDE(__sdata_start = .);
        PROVIDE(__global_pointer = . + 0x800);
        *(.sdata)
        PROVIDE(__sdata_end = .);
    }

    .srodata :
    {
        PROVIDE(__sdata_start = .);
        *(.srodata)
        PROVIDE(__sdata_end = .);
    }


    .rodata ALIGN(8) :
    {
        PROVIDE(__rodata_start = .);
        *(.rodata)
        PROVIDE(__rodata_end = .);
    }
 
    .data ALIGN(8) :
    {
        PROVIDE(__data_start = .);
        *(.data)
        PROVIDE(__data_end = .);
    }
 
    .bss :
    {
        PROVIDE(__bss_start = .);
        bss = .;
        *(.bss)
        PROVIDE(__bss_end = .);
        PROVIDE(__bss_size = __bss_end - __bss_start);
    }

    .initcall ALIGN(8) :
    {
        PROVIDE(__initcall_start = .);

        PROVIDE(__initcall0_start = .);
        KEEP(*(.initcall_0.text))
        PROVIDE(__initcall0_end = .);

        PROVIDE(__initcall1_start = .);
        KEEP(*(.initcall_1.text))
        PROVIDE(__initcall1_end = .);

        PROVIDE(__initcall2_start = .);
        KEEP(*(.initcall_2.text))
        PROVIDE(__initcall2_end = .);

        PROVIDE(__initcall3_start = .);
        KEEP(*(.initcall_3.text))
        PROVIDE(__initcall3_end = .);

        PROVIDE(__initcall4_start = .);
        KEEP(*(.initcall_4.text))
        PROVIDE(__initcall4_end = .);

        PROVIDE(__initcall5_start = .);
        KEEP(*(.initcall_5.text))
        PROVIDE(__initcall5_end = .);

        PROVIDE(__initcall6_start = .);
        KEEP(*(.initcall_6.text))
        PROVIDE(__initcall6_end = .);

        PROVIDE(__initcall7_start = .);
        KEEP(*(.initcall_7.text))
        PROVIDE(__initcall7_end = .);

        PROVIDE(__initcall8_start = .);
        KEEP(*(.initcall_8.text))
        PROVIDE(__initcall8_end = .);

        PROVIDE(__initcall9_start = .);
        KEEP(*(.initcall_9.text))
        PROVIDE(__initcall9_end = .);

        PROVIDE(__initcall_end = .);
    }

    .inithook ALIGN(8) :
    {
        PROVIDE(__inithook_start = .);
        KEEP(*(.inithook_0.text));
        PROVIDE(__inithook0 = .);
        KEEP(*(.inithook_1.text));
        PROVIDE(__inithook1 = .);
        KEEP(*(.inithook_2.text));
        PROVIDE(__inithook2 = .);
        KEEP(*(.inithook_3.text));
        PROVIDE(__inithook3 = .);
        KEEP(*(.inithook_4.text));
        PROVIDE(__inithook4 = .);
        KEEP(*(.inithook_5.text));
        PROVIDE(__inithook5 = .);
        KEEP(*(.inithook_6.text));
        PROVIDE(__inithook6 = .);
        KEEP(*(.inithook_7.text));
        PROVIDE(__inithook7 = .);
        KEEP(*(.inithook_8.text));
        PROVIDE(__inithook8 = .);
        KEEP(*(.inithook_9.text));
        PROVIDE(__inithook9 = .);
        PROVIDE(__inithook_end = .);
    }

    /* CORES STACK PROVIDING */
    .providestack ALIGN(16):
    {
        . = ALIGN(16);
        PROVIDE(__stackcore__ = .);
        . += 0x4000 * 4;
    }

    .ksymtab ALIGN(16) :
    {
        PROVIDE(__ksymtab_start = .);
        KEEP(*(.ksymtab.text))
        PROVIDE(__ksymtab_end = .);
    }

    PROVIDE(__KEND = .);

    /DISCARD/ : { *(.comment) }
    /DISCARD/ : { *(.gnu*) }
    /DISCARD/ : { *(.note*) }
    /DISCARD/ : { *(.eh_frame*) }
    /DISCARD/ : { *(.interp*)}
}