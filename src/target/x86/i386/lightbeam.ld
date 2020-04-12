ENTRY(_start)

PROVIDE(__KERNEL_ADDR_TRNS = 0xC0000000);
PROVIDE(__KERNEL_VIRT_LINK = 0xC0010000);
PROVIDE(__KERNEL_PHYS_LINK = 0x00010000);

SECTIONS
{
	. = __KERNEL_VIRT_LINK;

	.multiboot . : AT(ADDR(.multiboot) - __KERNEL_ADDR_TRNS)
	{
		*(.multiboot)
	}

	.text . : AT(ADDR(.text) - __KERNEL_ADDR_TRNS)
	{
		*(.text)
	}

	.rodata . : AT(ADDR(.rodata) - __KERNEL_ADDR_TRNS)
	{
		*(.rodata)
	}

	.data . : AT(ADDR(.data) - __KERNEL_ADDR_TRNS)
	{
		*(.data)
	}

	PROVIDE(__BSS_START = .);
	.bss . : AT(ADDR(.bss) - __KERNEL_ADDR_TRNS)
	{
		*(.bss)
	}
	PROVIDE(__BSS_END = .);

	/DISCARD/ :
	{ 
		*(*)
	}
}