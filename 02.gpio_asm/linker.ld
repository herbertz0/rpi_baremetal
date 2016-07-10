/******************************************************************************
*	kernel.ld taken from Alex Chadwick
*
******************************************************************************/

SECTIONS {

	/* Reserved space for atags and stack */
	. = 0x8000;
	.text :
	{
		*(.boot)
		*(.text)
	}


	.data :
	{
		*(.data)
	}

	/*
	* Finally comes everything else. A fun trick here is to put all other
	* sections into this section, which will be discarded by default.
	*/
	/DISCARD/ : {
		*(*)
	}
}
