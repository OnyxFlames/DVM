#include "DVM.hpp"


Object* DVM::pushi8(const int8_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i8 = val;
	stack[stk_ptr].curr_type = Type::type_i8;
	return &stack[stk_ptr];
}
Object* DVM::pushu8(const uint8_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u8 = val;
	stack[stk_ptr].curr_type = Type::type_u8;
	return &stack[stk_ptr];
}
Object* DVM::pushi16(const int16_t &val) {
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i16 = val;
	stack[stk_ptr].curr_type = Type::type_i16;
	return &stack[stk_ptr];
}
Object* DVM::pushu16(const uint16_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u16 = val;
	stack[stk_ptr].curr_type = Type::type_u16;
	return &stack[stk_ptr];
}
Object* DVM::pushi32(const int32_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i32 = val;
	stack[stk_ptr].curr_type = Type::type_i32;
	return &stack[stk_ptr];
}
Object* DVM::pushu32(const uint32_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u32 = val;
	stack[stk_ptr].curr_type = Type::type_u32;
	return &stack[stk_ptr];
}
Object* DVM::pushi64(const int64_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i64 = val;
	stack[stk_ptr].curr_type = Type::type_i64;
	return &stack[stk_ptr];
}
Object* DVM::pushu64(const uint64_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u64 = val;
	stack[stk_ptr].curr_type = Type::type_u64;
	return &stack[stk_ptr];
}
Object* DVM::pushf32(const float &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.f32 = val;
	stack[stk_ptr].curr_type = Type::type_f32;
	return &stack[stk_ptr];
}
Object* DVM::pushf64(const double &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.f64 = val;
	stack[stk_ptr].curr_type = Type::type_f64;
	return &stack[stk_ptr];
}
Object* DVM::pushstr(const std::string &val)
{
	int i = 0;
	for (i = ++stk_ptr; i < (stk_ptr + val.length()); ++i)
	{
		stack[i].types.u8 = val[(i - stk_ptr)];
	}
	stk_ptr = i - 1;
	// In this case, return the start of the array.
	stack[stk_ptr].curr_type = Type::type_c_str;
	return &stack[stk_ptr - val.size() + 1];
}
Object* DVM::pushObj(const Object &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr] = val;
	stack[stk_ptr].curr_type = Type::unknown;
	return &stack[stk_ptr];
}