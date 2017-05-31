#pragma once

#include <cstdint>

enum opcodes : uint32_t
{
	HALT = 0x00,	// Immediately stop execution
	RESTART,		// restart the VM instance
	PRINT,			// Operands: 2 bytes. Prints following N bytes of data to stdio
	READ,			// Operands: 2 bytes. Reads N bytes worth of data onto the stack as u8's

	PUSHI8,		PUSHU8,
	PUSHI16,	PUSHU16,
	PUSHI32,	PUSHU32,
	PUSHI64,	PUSHU64,
	PUSHF32,	PUSHF64,

	ADD, SUB, MUL,
	DIV, DIVF,
};