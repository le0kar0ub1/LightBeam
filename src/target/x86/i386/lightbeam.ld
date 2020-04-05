/*ENTRY(_scdbreath)*/

PROVIDE(__BOOT_SECTOR_START    = 0x7C00);
PROVIDE(__BOOT_SCDBREATH_START = 0x7E00);

PROVIDE(__KERNEL_VIRTUAL_START  = 0xFFFFFFFF80100000);
PROVIDE(__KERNEL_PHYSICAL_START = 0x0000000000100000);

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
		*(.text.rdsector)
		*(.data.boot)
		*(.bioscall)
	}

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