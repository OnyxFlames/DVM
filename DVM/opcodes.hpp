#pragma once

#include <cstdint>

enum opcodes : unsigned char
{
	HALT = 0x00,	// Immediately stop execution
	RESTART,		// restart the VM instance
	PRINT,			// Operands: 2 bytes. Prints following N bytes of data to stdio
	PRINTC,			// Operands: 2 bytes. Prints following N bytes of data to stdio casted as ascii characters
	READ,			// Operands: 2 bytes. Reads N bytes worth of data onto the stack as u8's

	JMP,			// Operands: 2 bytes. Sets to PC to N in the ROM. Stores the current location before jumping.
	RET,			// Set the PC to the last stored address in the jump stack + 2 (to skip the address from the jump call)

	PUSHI8,		PUSHU8,
	PUSHI16,	PUSHU16,
	PUSHI32,	PUSHU32,
	PUSHI64,	PUSHU64,
	PUSHF32,	PUSHF64,
	// F-variants are not yet implemented
	ADD, ADDF,
	SUB, SUBF,
	MUL, MULF,
	DIV, DIVF,
};