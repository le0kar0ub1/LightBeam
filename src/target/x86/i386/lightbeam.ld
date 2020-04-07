ENTRY(_bootsector)

PROVIDE(__BOOT_SECTOR_START    = 0x7C00);
PROVIDE(__BOOT_SCDBREATH_START = 0x7E00);

PROVIDE(__KERNEL_VIRTUAL_START  = 0xC0010000);
PROVIDE(__KERNEL_PHYSICAL_START = 0xC0000000);

SECTIONS
{
	. = __BOOT_SECTOR_START;
	.init.boot :
	{
		*(.bootsector)
		*(.bootmagic)
	}
	. = __BOOT_SCDBREATH_START;
	.init.scdbreath :
	{
		*(.text.boot)
		*(.text.bootrdsector)
		*(.data.boot)
		*(.bioscall)
	}
	. = ALIGN(0x200);
	PROVIDE(__BOOT_SECTOR_END = .);

	. = 0xC0000000;

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
	
	/* 
	** Be clean with the used sections in bootloader for now 
	** if non declared at top level -> DISCARDED
	*/
	/DISCARD/:
	{ 
		*(*)
	}
}