ENTRY(_bootsector)

SECTIONS {
	. = 0x7c00;
	.init.boot :
	{
		*(.bootsector)
		*(.krdata.desc)
		*(.bootmagic)
	}
	
	.init.scdbreath :
	{
		*(.text.boot)
		*(.bioscall)
		*(.data.boot)
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
	** Be clean with used sections in bootloader for now 
	** if non declared at top level -> DISCARDED
	*/
	/DISCARD/:
	{ 
		*(*)
	}
}