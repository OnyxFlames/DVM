#pragma once

#include <cstdint>
/*

	DVM Objects are 32 bit wide unions containing the C++ datatype equivalents for the DVM to manipulate;


*/
union Object {
	//C-Strings
	char* c_str;

	//8 bit wide 
	int8_t i8;
	int8_t* i8ptr;
	uint8_t u8;
	uint8_t* u8ptr;

	//16 bit wide
	int16_t i16;
	int16_t* i16ptr;

	uint16_t u16;
	int16_t* u16ptr;
	//32 bit wide
	int32_t i32;
	int32_t* i32ptr;

	uint32_t u32;
	uint32_t* u32ptr;

	//64 bit wide -- pointers are potentially 64 bits anyway, might as well add support for 64 bit wide integers
	int64_t i64;
	int64_t* i64ptr;

	uint64_t u64;
	uint64_t* u64ptr;

};