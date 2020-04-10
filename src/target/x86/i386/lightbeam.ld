ENTRY(_start)

PROVIDE(__KERNEL_ADDR_TRNS = 0xC0000000);
PROVIDE(__KERNEL_VIRT_LINK = 0xC0010000);
PROVIDE(__KERNEL_PHYS_LINK = 0x10000);

SECTIONS
{
	.text :
	{
		*(.text)
	}

	.rodata :
	{
		*(.rodata)
	}

	.data :
	{
		*(.data)
	}

	.bss :
	{
		*(.bss)
	}
	
	/DISCARD/:
	{ 
		*(*)
	}
}