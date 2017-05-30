#include "DVM.hpp"

#include "StackOverFlowException.hpp"

#define ALLOC_SIZE 2000u
static int ALLOC_SIZE_MODIFIED = ALLOC_SIZE;

DVM::DVM()
{
	// Default 16 kilobytes
	stack = new Object[ALLOC_SIZE];
}


DVM::~DVM()
{
	delete[] stack;
}

Object* DVM::pushi8(int8_t val) 
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].i8 = val; 
	return &stack[stk_ptr]; 
}
Object* DVM::pushu8(uint8_t val) 
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].u8 = val; 
	return &stack[stk_ptr]; 
}
Object* DVM::pushi16(int16_t val) { 
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].i16 = val; 
	return &stack[stk_ptr]; 
}
Object* DVM::pushu16(uint16_t val) 
{ 
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].u16 = val; 
	return &stack[stk_ptr]; 
}
Object* DVM::pushi32(int32_t val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].i32 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushu32(uint32_t val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].u32 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushi64(int64_t val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].i64 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushu64(uint64_t val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].u64 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushf32(float val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].f32 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushf64(double val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].f64 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushstr(std::string val)
{
	int i = 0;
	for (i = ++stk_ptr; i < (stk_ptr + val.length()); ++i)
	{
		stack[i].u8 = val[(i - stk_ptr)];
	}
	stk_ptr = i-1;
	// In this case, return the start of the array.
	return &stack[stk_ptr - val.size() + 1];
}