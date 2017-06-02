#pragma once

#include "Object.hpp"

#include "StackOverFlowException.hpp"

#include "opcodes.hpp"

#include "Debug_Utils.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
// Stack size is determined by 'slots'.
// Each slot is 64 bits wide [sizeof(Object)] which is one 'element' of the stack.
// Stack size is determined by a default, but if the --stack-size <number of elements for stack to attempt to hold>

enum state {
	HALTED = 0x00,
	RESTARTING = 0x10,
	RUNNING = 0x20,
};

#define ALLOC_SIZE 2000u
static int ALLOC_SIZE_MODIFIED = ALLOC_SIZE;

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
	Object* pushi8(const int8_t &val);
	Object* pushu8(const uint8_t &val);
	Object* pushi16(const int16_t &val);
	Object* pushu16(const uint16_t &val);
	Object* pushi32(const int32_t &val);
	Object* pushu32(const uint32_t &val);
	Object* pushi64(const int64_t &val);
	Object* pushu64(const uint64_t &val);
	Object* pushf32(const float &val);
	Object* pushf64(const double &val);
	Object* pushstr(const std::string &val);
	Object* pushObj(const Object &val);


	// Actual ROM
	std::vector<unsigned char> ROM = {
		PUSHI32, 0, 0, 0, 5, PUSHI32, 0, 0, 0, 5, ADD, HALT,
	};
	// List of ROM loaded functions, sorted by 4 byte values assigned at loadtime
	std::map<uint32_t, std::vector<unsigned char>> FUNCTIONS;
	// For JMP opcodes. RET will return to PC to the last value + 2
	std::stack<uint16_t> jump_stack;
	
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
			std::cerr << "Stack overflowed to max value\n";
			std::exit(-1);
		}
	}

	bool loadROM(const std::string filename);
	bool unloadROM() { state = HALTED; ROM.erase(ROM.begin(), ROM.end()); }
	void restart() { state = RESTARTING; }
	bool run();
};

