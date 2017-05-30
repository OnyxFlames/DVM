#pragma once

#include "Object.hpp"

#include "StackOverFlowException.hpp"

// Stack size is determined by 'slots'.
// Each slot is 64 bits wide [sizeof(Object)] which is one 'element' of the stack.
// Stack size is determined by a default, but if the --stack-size <number of elements for stack to attempt to hold>
class DVM
{
private:
	//Index for stack. Can read up to element 16^2-1
	uint16_t stk_ptr = 0;
	// Stack is technically on the heap, but this is for dynamic stack sizes.
	Object* stack;
	// Current max size the stack is, if the stack allocates more than this, throw StackOverFlowError
	uint64_t max_size;
public:
	DVM();
	~DVM();

	Object top()
	{
		return stack[stk_ptr];
	}

	void pop()
	{
		uint16_t current_stack_value = stk_ptr;
		stk_ptr--;
		if (current_stack_value < stk_ptr)
		{
			//throw StackOverFlowException("Stack underflowed to max value\n");
			std::cerr << "Stack overflowed to max value\n";
			std::exit(-1);
		}
	}
	// inline push functions, returns address that the variable was allocated on
	Object* pushi8(int8_t val);
	Object* pushu8(uint8_t val);
	Object* pushi16(int16_t val);
	Object* pushu16(uint16_t val);
	Object* pushi32(int32_t val);
	Object* pushu32(uint32_t val);
	Object* pushi64(int64_t val);
	Object* pushu64(uint64_t val);
	Object* pushstr(std::string val);
};
