/*
 *  linker_script.ld
 *
 *  Created on: Jun 16, 2022
 *      Author: momen amr
 */

MEMORY
{
	Flash(rx) : ORIGIN = 0x00000000, LENGTH = 128K
	Sram(rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
	*(.vectors*)
	*(.text*)
	*(.rodata)
	. = ALIGN(4);
	_E_text = .;
	}> Flash

	.data :
	{
	_S_data = .;
	*(.data)
	. = ALIGN(4);
	_E_data = .;
	}> Sram AT> Flash

	.bss :
	{
	_S_bss = .;
	*(.bss)
	*(COMMON)
	. = ALIGN(4);
	_E_bss = .;
	}> Sram

}