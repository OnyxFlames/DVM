#include "DVM.hpp"
#include "Object.hpp"

// These functions will do type casting to the largest data type given


// Type weight, 6 is the largest.
// When determining the weight of a data type for conversion, larger number is priority.
unsigned char get_type_weight(Object &obj)
{
	switch (obj.curr_type)
	{
	case Type::type_f64:
		return 6; break;
	case Type::type_f32:
		return 5; break;
	case Type::type_i64:
	case Type::type_u64:
		return 4; break;
	case Type::type_i32:
	case Type::type_u32:
		return 3; break;
	case Type::type_i16:
	case Type::type_u16:
		return 2; break;
	case Type::type_i8:
	case Type::type_u8:
		return 1; break;
	default:
		std::cerr << "Invalid type. (Not implemented?)\n";
		return 0;
		break;
	}
}

Object add(Object &first, Object &second)
{
	if (first.curr_type != second.curr_type)
	{
		std::cout << "[VM] Error: Type casting is not yet supported. Type mismatch in ADD opcode.\n";
		std::cout << "\t\t\t\t\t\t(TypeID: " << first.curr_type << " != TypeID: " << second.curr_type << ")\n";
		return Object();
	}
	else
	{
		Object ret;
		switch (first.curr_type)
		{
		case Type::type_f64:
			ret.curr_type = Type::type_f64;
			ret.types.f64 = (first.types.f64 + second.types.f64);
			return ret;
			break;
		case Type::type_f32:
			ret.curr_type = Type::type_f32;
			ret.types.f32 = (first.types.f32 + second.types.f32);
			return ret;
			break;
		case Type::type_i64:
			ret.curr_type = Type::type_i64;
			ret.types.i64 = (first.types.i64 + second.types.i64);
			return ret;
			break;
		case Type::type_u64:
			ret.curr_type = Type::type_u64;
			ret.types.u64 = (first.types.u64 + second.types.u64);
			return ret;
			break;
		case Type::type_i32:
			ret.curr_type = Type::type_i32;
			ret.types.i32 = (first.types.i32 + second.types.i32);
			return ret;
			break;
		case Type::type_u32:
			ret.curr_type = Type::type_u32;
			ret.types.u32 = (first.types.u32 + second.types.u32);
			return ret;
			break;
		case Type::type_i16:
			ret.curr_type = Type::type_i16;
			ret.types.i16 = (first.types.i16 + second.types.i16);
			return ret;
			break;
		case Type::type_u16:
			ret.curr_type = Type::type_u16;
			ret.types.u16 = (first.types.u16 + second.types.u16);
			return ret;
			break;
		case Type::type_i8:
			ret.curr_type = Type::type_i8;
			ret.types.i8 = (first.types.i8 + second.types.i8);
			return ret;
			break;
		case Type::type_u8:
			ret.curr_type = Type::type_u8;
			ret.types.u8 = (first.types.u8 + second.types.u8);
			return ret;
			break;
		default:
			std::cerr << "Invalid type. (Not implemented?)\n";
			return Object();
			break;
		}
	}
}

Object sub(Object &first, Object &second)
{
	if (first.curr_type != second.curr_type)
	{
		std::cout << "[VM] Error: Type casting is not yet supported. Type mismatch in SUB opcode.\n";
		std::cout << "(TypeID: " << first.curr_type << " != TypeID: " << second.curr_type << ")\n"; 
		return Object();
	}
	else
	{
		Object ret;
		switch (first.curr_type)
		{
		case Type::type_f64:
			ret.curr_type = Type::type_f64;
			ret.types.f64 = (first.types.f64 - second.types.f64);
			return ret;
			break;
		case Type::type_f32:
			ret.curr_type = Type::type_f32;
			ret.types.f32 = (first.types.f32 - second.types.f32);
			return ret;
			break;
		case Type::type_i64:
			ret.curr_type = Type::type_i64;
			ret.types.i64 = (first.types.i64 - second.types.i64);
			return ret;
			break;
		case Type::type_u64:
			ret.curr_type = Type::type_u64;
			ret.types.u64 = (first.types.u64 - second.types.u64);
			return ret;
			break;
		case Type::type_i32:
			ret.curr_type = Type::type_i32;
			ret.types.i32 = (first.types.i32 - second.types.i32);
			return ret;
			break;
		case Type::type_u32:
			ret.curr_type = Type::type_u32;
			ret.types.u32 = (first.types.u32 - second.types.u32);
			return ret;
			break;
		case Type::type_i16:
			ret.curr_type = Type::type_i16;
			ret.types.i16 = (first.types.i16 - second.types.i16);
			return ret;
			break;
		case Type::type_u16:
			ret.curr_type = Type::type_u16;
			ret.types.u16 = (first.types.u16 - second.types.u16);
			return ret;
			break;
		case Type::type_i8:
			ret.curr_type = Type::type_i8;
			ret.types.i8 = (first.types.i8 - second.types.i8);
			return ret;
			break;
		case Type::type_u8:
			ret.curr_type = Type::type_u8;
			ret.types.u8 = (first.types.u8 - second.types.u8);
			return ret;
			break;
		default:
			std::cerr << "Invalid type. (Not implemented?)\n";
			return Object();
			break;
		}
	}
}

Object mul(Object &first, Object &second)
{
	if (first.curr_type != second.curr_type)
	{
		std::cout << "[VM] Error: Type casting is not yet supported. Type mismatch in MUL opcode.\n";
		std::cout << "(TypeID: " << first.curr_type << " != TypeID: " << second.curr_type << ")\n";
		return Object();
	}
	else
	{
		Object ret;
		switch (first.curr_type)
		{
		case Type::type_f64:
			ret.curr_type = Type::type_f64;
			ret.types.f64 = (first.types.f64 * second.types.f64);
			return ret;
			break;
		case Type::type_f32:
			ret.curr_type = Type::type_f32;
			ret.types.f32 = (first.types.f32 * second.types.f32);
			return ret;
			break;
		case Type::type_i64:
			ret.curr_type = Type::type_i64;
			ret.types.i64 = (first.types.i64 * second.types.i64);
			return ret;
			break;
		case Type::type_u64:
			ret.curr_type = Type::type_u64;
			ret.types.u64 = (first.types.u64 * second.types.u64);
			return ret;
			break;
		case Type::type_i32:
			ret.curr_type = Type::type_i32;
			ret.types.i32 = (first.types.i32 * second.types.i32);
			return ret;
			break;
		case Type::type_u32:
			ret.curr_type = Type::type_u32;
			ret.types.u32 = (first.types.u32 * second.types.u32);
			return ret;
			break;
		case Type::type_i16:
			ret.curr_type = Type::type_i16;
			ret.types.i16 = (first.types.i16 * second.types.i16);
			return ret;
			break;
		case Type::type_u16:
			ret.curr_type = Type::type_u16;
			ret.types.u16 = (first.types.u16 * second.types.u16);
			return ret;
			break;
		case Type::type_i8:
			ret.curr_type = Type::type_i8;
			ret.types.i8 = (first.types.i8 * second.types.i8);
			return ret;
			break;
		case Type::type_u8:
			ret.curr_type = Type::type_u8;
			ret.types.u8 = (first.types.u8 * second.types.u8);
			return ret;
			break;
		default:
			std::cerr << "Invalid type. (Not implemented?)\n";
			return Object();
			break;
		}
	}
}

Object div(Object &first, Object &second)
{
	if (first.curr_type != second.curr_type)
	{
		std::cout << "[VM] Error: Type casting is not yet supported. Type mismatch in DIV opcode.\n";
		std::cout << "(TypeID: " << first.curr_type << " != TypeID: " << second.curr_type << ")\n";
		return Object();
	}
	else
	{
		Object ret;
		switch (first.curr_type)
		{
		case Type::type_f64:
			ret.curr_type = Type::type_f64;
			ret.types.f64 = (first.types.f64 / second.types.f64);
			return ret;
			break;
		case Type::type_f32:
			ret.curr_type = Type::type_f32;
			ret.types.f32 = (first.types.f32 / second.types.f32);
			return ret;
			break;
		case Type::type_i64:
			ret.curr_type = Type::type_i64;
			ret.types.i64 = (first.types.i64 / second.types.i64);
			return ret;
			break;
		case Type::type_u64:
			ret.curr_type = Type::type_u64;
			ret.types.u64 = (first.types.u64 / second.types.u64);
			return ret;
			break;
		case Type::type_i32:
			ret.curr_type = Type::type_i32;
			ret.types.i32 = (first.types.i32 / second.types.i32);
			return ret;
			break;
		case Type::type_u32:
			ret.curr_type = Type::type_u32;
			ret.types.u32 = (first.types.u32 / second.types.u32);
			return ret;
			break;
		case Type::type_i16:
			ret.curr_type = Type::type_i16;
			ret.types.i16 = (first.types.i16 / second.types.i16);
			return ret;
			break;
		case Type::type_u16:
			ret.curr_type = Type::type_u16;
			ret.types.u16 = (first.types.u16 / second.types.u16);
			return ret;
			break;
		case Type::type_i8:
			ret.curr_type = Type::type_i8;
			ret.types.i8 = (first.types.i8 / second.types.i8);
			return ret;
			break;
		case Type::type_u8:
			ret.curr_type = Type::type_u8;
			ret.types.u8 = (first.types.u8 / second.types.u8);
			return ret;
			break;
		default:
			std::cerr << "Invalid type. (Not implemented?)\n";
			return Object();
			break;
		}
	}

}
