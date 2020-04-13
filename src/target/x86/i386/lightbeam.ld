ENTRY(_start)

PROVIDE(__KERNEL_ADDR_TRNS = 0xC0000000);
PROVIDE(__KERNEL_VIRT_LINK = 0xC0010000);
PROVIDE(__KERNEL_PHYS_LINK = 0x00010000);

SECTIONS
{
    . = __KERNEL_VIRT_LINK;

    .multiboot ALIGN(0x1000) : AT(ADDR(.multiboot) - __KERNEL_ADDR_TRNS)
    {
        *(.multiboot)
    }

    .text ALIGN(0x1000) : AT(ADDR(.text) - __KERNEL_ADDR_TRNS)
    {
        PROVIDE(__start_text_ = .);
        *(.text)
        PROVIDE(__end_text_ = .);
    }

    .initcall ALIGN(8) : AT(ADDR(.initcall) - __KERNEL_ADDR_TRNS)
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

    .inithook ALIGN(8) : AT(ADDR(.inithook) - __KERNEL_ADDR_TRNS)
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
    }

    .exithook ALIGN(8) : AT(ADDR(.exithook) - __KERNEL_ADDR_TRNS)
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
    }

    .rodata ALIGN(0x1000) : AT(ADDR(.rodata) - __KERNEL_ADDR_TRNS)
    {
        PROVIDE(__start_rodata_ = .);
        *(.rodata)
        PROVIDE(__end_rodata_ = .);
    }

    .data ALIGN(0x1000) : AT(ADDR(.data) - __KERNEL_ADDR_TRNS)
    {
        PROVIDE(__start_data_ = .);
        *(.data)
        PROVIDE(__end_data_ = .);
    }

    PROVIDE(__BSS_START = .);
    .bss ALIGN(0x1000) : AT(ADDR(.bss) - __KERNEL_ADDR_TRNS)
    {
        PROVIDE(__start_bss_ = .);
        *(.bss)
        PROVIDE(__end_bss_ = .);
    }
    PROVIDE(__BSS_END = .);

    /*
    /DISCARD/ :
    { 
        *(*)
    }
    */
}