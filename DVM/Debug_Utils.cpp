#include "Debug_Utils.hpp"

namespace DebugUtils 
{

	void list_stack_top(Object* _stack, uint16_t _stk_ptr)
	{
		std::cout << "Stack Top: ";
		if (_stk_ptr < 1)
		{
			std::cout << "Empty\n";
		}
		else
			switch (_stack[_stk_ptr].curr_type)
			{
			case Type::type_c_str:
				std::cout << "\n\tType: C-String Value: " << _stack[_stk_ptr].types.c_str << "\n";
				break;
			case Type::type_i8:
				std::cout << "\n\tType: i8 Value: " << _stack[_stk_ptr].types.i8 << "\n";
				break;
			case Type::type_u8:
				std::cout << "\n\tType: u8 Value: " << _stack[_stk_ptr].types.i8 << "\n";
				break;
			case Type::type_i16:
				std::cout << "\n\tType: i16 Value: " << _stack[_stk_ptr].types.i16 << "\n";
				break;
			case Type::type_u16:
				std::cout << "\n\tType: u16 Value: " << _stack[_stk_ptr].types.u16 << "\n";
				break;
			case Type::type_i32:
				std::cout << "\n\tType: i32 Value: " << _stack[_stk_ptr].types.i32 << "\n";
				break;
			case Type::type_u32:
				std::cout << "\n\tType: u32 Value: " << _stack[_stk_ptr].types.u32 << "\n";
				break;
			case Type::type_i64:
				std::cout << "\n\tType: i64 Value: " << _stack[_stk_ptr].types.i64 << "\n";
				break;
			case Type::type_u64:
				std::cout << "\n\tType: u64 Value: " << _stack[_stk_ptr].types.u64 << "\n";
				break;
			case Type::type_f32:
				std::cout << "\n\tType: f32 Value: " << _stack[_stk_ptr].types.f32 << "\n";
				break;
			case Type::type_f64:
				std::cout << "\n\tType: f64 Value: " << _stack[_stk_ptr].types.f64 << "\n";
				break;
			default:
				std::cout << "Unknown type: Address: 0x" << &_stack[_stk_ptr].types.u64 << "\n";
				break;
			}
	}
	void debug_wait()
	{
		std::cout << "Press any key to continue...\n";
		getchar();
	}
}