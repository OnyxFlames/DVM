#pragma once

#include "Object.hpp"

//#include "StackOverFlowException.hpp"

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

// register index for the program counter.
#define prog_counter 0
#define stack_pointer 1
#define PC registers[prog_counter].types.u16
#define SP registers[stack_pointer].types.u16

class DVM
{
private:
	bool allocated = true;

	uint8_t state = RUNNING;
	//Index for stack. Can read up to element 2^16-1
	//uint16_t stk_ptr = 0;
	//Program Counter. Index of the ROM that the VM is currently at.
	//uint16_t pc = 0;
	// Stack is technically on the heap, but this is for dynamic stack sizes.
	Object* stack;
	// Current max size the stack is, if the stack allocates more than this, throw StackOverFlowError
	uint64_t max_size;
	// Work registers. Being on the stack allows for faster speeds, but only allows 8
	Object registers[8] = { };
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
		PUSHU32, 0, 0, 0, 5, PUSHU32, 0, 0, 0, 5, MUL, PRINT, HALT,
	};
	// List of ROM loaded functions, sorted by 4 byte values assigned at loadtime
	std::map<uint32_t, std::vector<unsigned char>> FUNCTIONS;
	// For JMP opcodes. RET will return to PC to the last value + 2
	std::stack<uint16_t> jump_stack;
	
public:
	DVM();
	//DVM(const std::string _rom);
	~DVM();

	Object& top()
	{
		//std::cout << "Topping TypeID: " << stack[SP].curr_type << "\n";
		return stack[SP];
	}

	Object& pop()
	{
		//std::cout << "Popping TypeID: " << stack[SP--].curr_type << "\n";
		SP--;
		uint16_t current_stack_value = SP;
		//std::cout << "Stack pointer: " << --SP << "\n";
		if (current_stack_value < SP)
		{
			std::cerr << "Stack overflowed to max value\n";
			std::exit(-1);
		}
		return stack[SP];
	}

	bool loadROM(const std::string filename);
	bool unloadROM() { state = HALTED; ROM.erase(ROM.begin(), ROM.end()); }
	void restart() { state = RESTARTING; }
	bool run();
};

// Arithmetic
Object add(Object &first, Object &second);
Object sub(Object &first, Object &second);
Object mul(Object &first, Object &second);
Object div(Object &first, Object &second);
void print_obj(const Object &obj);