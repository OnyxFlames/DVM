#pragma once

#include <cstdint>
/*

	DVM Objects are 64 bit wide unions containing the C++ datatype equivalents for the DVM to manipulate;

*/

enum Type : uint8_t {

	unknown = 0,

	type_c_str,
	type_i8,
	type_i8ptr,
	type_u8,
	type_u8ptr,
	type_i16,
	type_i16ptr,
	type_u16,
	type_u16ptr,
	type_i32,
	type_i32ptr,
	type_u32,
	type_u32ptr,
	type_i64,
	type_i64ptr,
	type_u64,
	type_u64ptr,
	type_f32,
	type_f32ptr,
	type_f64,
	type_f64ptr,
	type_dvmobject,		// Generic DVM object
	type_dvmfunction,	// DVM runtime function
};

struct Object
{
	Type curr_type;

	union Object_Type {
		//C-Strings
		char* c_str;

		//8 bit wide 
		int8_t i8;
		//int8_t* i8ptr;
		uint8_t u8;
		//uint8_t* u8ptr;

		//16 bit wide
		int16_t i16;
		//int16_t* i16ptr;
		uint16_t u16;
		//int16_t* u16ptr;

		//32 bit wide
		int32_t i32;
		//int32_t* i32ptr;
		uint32_t u32;
		//uint32_t* u32ptr;

		//64 bit wide -- pointers are potentially 64 bits anyway, might as well add support for 64 bit wide integers
		int64_t i64;
		//int64_t* i64ptr;
		uint64_t u64;
		//uint64_t* u64ptr;

		//32 and 64 bit floating point numbers.
		float f32;
		//float* f32ptr;
		double f64;
		//double* f64ptr;

		// index of the function map in which this function resides.
		uint32_t dvmfunc;
	} types;
	Object()
	{
		curr_type = unknown;
		types.u64 = 0;
	}
};