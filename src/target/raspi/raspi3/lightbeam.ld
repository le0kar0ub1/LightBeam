OUTPUT(aarch64)
ENTRY(_start)

PROVIDE(__entry_point = 0x80000);
PROVIDE(ram_entry  = 0x00080000);
PROVIDE(dma_entry  = 0x08000000);
PROVIDE(heap_entry = 0x10000000);


MEMORY
{
    ram  : org = 0x00080000, len = 128M - 512K
    dma  : org = 0x08000000, len = 128M
    heap : org = 0x10000000, len = 256M
}

SECTIONS
{
    .text :
    {
        PROVIDE(__text_start = .);
        KEEP(*(.text.boot))
        *(.text)
        *(.init.text)
        *(.exit.text)
        *(.iplt)
        *(.text.*)
        PROVIDE(__text_end = .);
    } > ram
    . = ALIGN(4096);
 
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
    } > ram

    .inithook ALIGN(8) :
    {
        PROVIDE(__inithook_start = .);

        PROVIDE(__inithook0_start = .);
        KEEP(*(.inithook_0.text))
        PROVIDE(__inithook0_end = .);

        PROVIDE(__inithook1_start = .);
        KEEP(*(.inithook_1.text))
        PROVIDE(__inithook1_end = .);

        PROVIDE(__inithook2_start = .);
        KEEP(*(.inithook_2.text))
        PROVIDE(__inithook2_end = .);

        PROVIDE(__inithook3_start = .);
        KEEP(*(.inithook_3.text))
        PROVIDE(__inithook3_end = .);

        PROVIDE(__inithook4_start = .);
        KEEP(*(.inithook_4.text))
        PROVIDE(__inithook4_end = .);

        PROVIDE(__inithook5_start = .);
        KEEP(*(.inithook_5.text))
        PROVIDE(__inithook5_end = .);

        PROVIDE(__inithook6_start = .);
        KEEP(*(.inithook_6.text))
        PROVIDE(__inithook6_end = .);

        PROVIDE(__inithook7_start = .);
        KEEP(*(.inithook_7.text))
        PROVIDE(__inithook7_end = .);

        PROVIDE(__inithook8_start = .);
        KEEP(*(.inithook_8.text))
        PROVIDE(__inithook8_end = .);

        PROVIDE(__inithook9_start = .);
        KEEP(*(.inithook_9.text))
        PROVIDE(__inithook9_end = .);

        PROVIDE(__inithook_end = .);
    } > ram

    .exithook ALIGN(8) :
    {
        PROVIDE(__exithook_start = .);

        PROVIDE(__exithook0_start = .);
        KEEP(*(.exithook_0.text))
        PROVIDE(__exithook0_end = .);

        PROVIDE(__exithook1_start = .);
        KEEP(*(.exithook_1.text))
        PROVIDE(__exithook1_end = .);

        PROVIDE(__exithook2_start = .);
        KEEP(*(.exithook_2.text))
        PROVIDE(__exithook2_end = .);

        PROVIDE(__exithook3_start = .);
        KEEP(*(.exithook_3.text))
        PROVIDE(__exithook3_end = .);

        PROVIDE(__exithook4_start = .);
        KEEP(*(.exithook_4.text))
        PROVIDE(__exithook4_end = .);

        PROVIDE(__exithook5_start = .);
        KEEP(*(.exithook_5.text))
        PROVIDE(__exithook5_end = .);

        PROVIDE(__exithook6_start = .);
        KEEP(*(.exithook_6.text))
        PROVIDE(__exithook6_end = .);

        PROVIDE(__exithook7_start = .);
        KEEP(*(.exithook_7.text))
        PROVIDE(__exithook7_end = .);

        PROVIDE(__exithook8_start = .);
        KEEP(*(.exithook_8.text))
        PROVIDE(__exithook8_end = .);

        PROVIDE(__exithook9_start = .);
        KEEP(*(.exithook_9.text))
        PROVIDE(__exithook9_end = .);

        PROVIDE(__exithook_end = .);
    } > ram

    .ksymtab ALIGN(16) :
    {
        PROVIDE(__ksymtab_start = .);
        KEEP(*(.ksymtab.text))
        PROVIDE(__ksymtab_end = .);
    } > ram

    .rodata ALIGN(8) :
    {
        PROVIDE(__rodata_start = .);
        *(.rodata)
        PROVIDE(__rodata_end = .);
    } > ram
    . = ALIGN(4096);
 
    .data ALIGN(8) :
    {
        PROVIDE(__data_start = .);
        *(.data)
        PROVIDE(__data_end = .);
    } > ram
    . = ALIGN(4096);
 
    .bss :
    {
        PROVIDE(__bss_start = .);
        bss = .;
        *(.bss)
        PROVIDE(__bss_end = .);
        PROVIDE(__bss_size = __bss_end - __bss_start);
    } > ram
    . = ALIGN(4096);


    /* CORES STACK PROVIDING */
    .stack_core0 ALIGN(16):
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
    } > ram

    .stack_core1 ALIGN(16):
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
    } > ram

    .stack_core2 ALIGN(16):
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
    } > ram

    .stack_core3 ALIGN(16):
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
    } > ram


    .heap ALIGN(8) (NOLOAD) :
    {
        PROVIDE(__heap_start = ORIGIN(heap));
        PROVIDE(__heap_end = ORIGIN(heap) + LENGTH(heap));
    } > heap

    .dma ALIGN(8) (NOLOAD) :
    {
        PROVIDE(__dma_start = ORIGIN(dma));
        PROVIDE(__dma_end = ORIGIN(dma) + LENGTH(dma));
    } > dma

    PROVIDE(__KEND = .);

    /DISCARD/ : { *(.comment) }
    /DISCARD/ : { *(.gnu*) }
    /DISCARD/ : { *(.note*) }
    /DISCARD/ : { *(.eh_frame*) }
    /DISCARD/ : { *(.interp*)}
}