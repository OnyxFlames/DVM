#pragma once

#include <iostream>
#include <cstdint>
#include <map>
#include "Object.hpp"
#include "opcodes.hpp"

#define DEBUG

#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_SUFFIX "indev"

namespace DebugUtils
{

	void list_stack_top(Object* _stack, uint16_t _stk_ptr);
	void debug_wait();
	//std::map<unsigned char, std::string> opcode_strings;
}