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
		return 3;
	case Type::type_i16:
	case Type::type_u16:
		return 2;
	case Type::type_i8:
	case Type::type_u8:
		return 1;
	default:
		std::cerr << "Invalid type. (Not implemented?)\n";
		return 0;
		break;
	}
}

Object add(Object &first, Object &second)
{

}
Object add(int8_t &first, int8_t &second)
{

}

Object sub(Object &first, Object &second)
{

}
Object sub(int8_t &first, int8_t &second)
{

}

Object mul(Object &first, Object &second)
{

}
Object mul(int8_t &first, int8_t &second)
{

}

Object div(Object &first, Object &second)
{

}
Object div(int8_t &first, int8_t &second)
{

}
