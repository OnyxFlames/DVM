#include "DVM.hpp"


Object* DVM::pushi8(const int8_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.i8 = val;
	stack[SP].curr_type = Type::type_i8;
	return &stack[SP];
}
Object* DVM::pushu8(const uint8_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.u8 = val;
	stack[SP].curr_type = Type::type_u8;
	return &stack[SP];
}
Object* DVM::pushi16(const int16_t &val) {
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.i16 = val;
	stack[SP].curr_type = Type::type_i16;
	return &stack[SP];
}
Object* DVM::pushu16(const uint16_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.u16 = val;
	stack[SP].curr_type = Type::type_u16;
	return &stack[SP];
}
Object* DVM::pushi32(const int32_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	SP++;
	stack[SP].types.i32 = val;
	stack[SP].curr_type = Type::type_i32;
	return &stack[SP];
}
Object* DVM::pushu32(const uint32_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.u32 = val;
	stack[SP].curr_type = Type::type_u32;
	return &stack[SP];
}
Object* DVM::pushi64(const int64_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.i64 = val;
	stack[SP].curr_type = Type::type_i64;
	return &stack[SP];
}
Object* DVM::pushu64(const uint64_t &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.u64 = val;
	stack[SP].curr_type = Type::type_u64;
	return &stack[SP];
}
Object* DVM::pushf32(const float &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.f32 = val;
	stack[SP].curr_type = Type::type_f32;
	return &stack[SP];
}
Object* DVM::pushf64(const double &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP].types.f64 = val;
	stack[SP].curr_type = Type::type_f64;
	return &stack[SP];
}
Object* DVM::pushstr(const std::string &val)
{
	int i = 0;
	for (i = ++SP; i < (SP + val.length()); ++i)
	{
		stack[i].types.u8 = val[(i - SP)];
	}
	SP = i - 1;
	// In this case, return the start of the array.
	stack[SP].curr_type = Type::type_c_str;
	return &stack[SP - val.size() + 1];
}
Object* DVM::pushObj(const Object &val)
{
	//if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		//throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++SP] = val;
	//stack[SP].curr_type = Type::unknown;
	return &stack[SP];
}