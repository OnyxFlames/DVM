#pragma once

#include <cstdint>

enum opcodes : uint32_t
{
	HALT = 0x00000000,	// stops execution
	LOAD,				// LOAD <4-byte value>
	ADD,				// ADD - adds top and top - 1 values
	SUB,				// SUB - subtracts top and top - 1 values
	MUL,				// MUL - Multiplies top and top - 1
	DIV,				// DIV - Divides top by top - 1
	FDIV,				// FDIV - Divides top by top - 1, casts as float

	FUNC,				// FUNC - Sets a stack from and executes code within the stackframe (start + offset)
	RET,				// RET - Zeros out all values in current stackframe and moves SP back to the FUNC + 1


	WRITED,				// WRITED - Writes the first 4 byte values as a decimal
	WRITEF,				// WRITEF - Writes the first 4 byte values as a floating point number
	WRITE,				// WRITE <4-byte value> - Takes address and prints all characters from address until reaching NULL (\0)
	READC,				// READC - Reads one character value and places it onto the top of the stack.
	READBUFF,			// READBUFF <4-byte value> - Reads X amount of characters and places them onto the stack.

	SYSCALL,			// SYSCALL - Used for 'system' specific, non-opcode functions.

};