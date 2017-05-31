#pragma once

#include "Object.hpp"

#include "StackOverFlowException.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <map>
// Stack size is determined by 'slots'.
// Each slot is 64 bits wide [sizeof(Object)] which is one 'element' of the stack.
// Stack size is determined by a default, but if the --stack-size <number of elements for stack to attempt to hold>

enum state {
	HALTED = 0x00,
	RESTARTING = 0x10,
	RUNNING = 0x20,
};

class DVM
{
private:
	uint8_t state = RUNNING;
	//Index for stack. Can read up to element 2^16-1
	uint16_t stk_ptr = 0;
	// Stack is technically on the heap, but this is for dynamic stack sizes.
	Object* stack;
	// Current max size the stack is, if the stack allocates more than this, throw StackOverFlowError
	uint64_t max_size;

	// inline push functions, returns address that the variable was allocated on
	Object* pushi8(int8_t val);
	Object* pushu8(uint8_t val);
	Object* pushi16(int16_t val);
	Object* pushu16(uint16_t val);
	Object* pushi32(int32_t val);
	Object* pushu32(uint32_t val);
	Object* pushi64(int64_t val);
	Object* pushu64(uint64_t val);
	Object* pushf32(float val);
	Object* pushf64(double val);
	Object* pushstr(std::string val);
	Object* pushObj(Object val);


	// Actual ROM
	std::vector<unsigned char> ROM = {
		9, 255, 255, 255, 255, 0x00,
	};
	// List of ROM loaded functions, sorted by 4 byte values assigned at loadtime
	std::map<uint32_t, std::vector<unsigned char>> FUNCTIONS;
	
public:
	DVM();
	~DVM();

	Object& top()
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

	bool loadROM(const std::string filename);
	bool unloadROM() { state = HALTED; ROM.erase(ROM.begin(), ROM.end()); }
	void restart() { state = RESTARTING; }
	bool run();
};

