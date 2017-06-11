#pragma once

#include <iostream>
#include <cstdint>

#include "Object.hpp"


#define DEBUG

namespace DebugUtils
{

	void list_stack_top(Object* _stack, uint16_t _stk_ptr);
	void debug_wait();
}