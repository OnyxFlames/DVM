#include "DVM.hpp"

#include "StackOverFlowException.hpp"

#include "opcodes.hpp"

DVM::DVM()
{
	// Default 16 kilobytes
	//std::clog << "Allocating " << (sizeof(Object) * ALLOC_SIZE) / 8 << " bytes.\n";
	stack = new Object[ALLOC_SIZE];
	state = RUNNING;
}


DVM::~DVM()
{

	std::clog << "Deleting " << (sizeof(Object) * ALLOC_SIZE) / 8 << " bytes.\n";
	delete[] stack;
}

bool DVM::loadROM(const std::string filename)
{
	std::ifstream rom(filename);
	
	if (rom.is_open())
	{
		while (rom.good())
		{
			// TODO: Make ROM vector check size before loading, load if under certain limit, otherwise run from file
			ROM.push_back(rom.get());
		}
		return true;
	}
	else
		return false;
}

bool DVM::run()
{
	while (state != RESTARTING)
		for (auto it = ROM.cbegin(); it != ROM.cend(); it++)
		{
			if (state == HALTED)
			{
				//std::clog << "Deleting " << (sizeof(Object) * ALLOC_SIZE) / 8 << " bytes.\n"; 
				delete[] stack;
				std::exit(1);
			}
			// Break out of both loops
			if (state == RESTARTING)
				break;
			Object buff[2];
			Type type;

			std::cout << "Stack Top: ";
			if (stk_ptr < 1)
			{
				std::cout << "Empty\n";
			}
			else
				switch (stack[stk_ptr].curr_type)
				{
				case Type::type_c_str:
					std::cout << "\n\tType: C-String Value: " << stack[stk_ptr].types.c_str << "\n";
					break;
				case Type::type_i8:
					std::cout << "\n\tType: i8 Value: " << stack[stk_ptr].types.i8 << "\n";
					break;
				case Type::type_u8:
					std::cout << "\n\tType: u8 Value: " << stack[stk_ptr].types.i8 << "\n";
					break;
				case Type::type_i16:
					std::cout << "\n\tType: i16 Value: " << stack[stk_ptr].types.i16 << "\n";
					break;
				case Type::type_u16:
					std::cout << "\n\tType: u16 Value: " << stack[stk_ptr].types.u16 << "\n";
					break;
				case Type::type_i32:
					std::cout << "\n\tType: i32 Value: " << stack[stk_ptr].types.i32 << "\n";
					break;
				case Type::type_u32:
					std::cout << "\n\tType: u32 Value: " << stack[stk_ptr].types.u32 << "\n";
					break;
				case Type::type_i64:
					std::cout << "\n\tType: i64 Value: " << stack[stk_ptr].types.i64 << "\n";
					break;
				case Type::type_u64:
					std::cout << "\n\tType: u64 Value: " << stack[stk_ptr].types.u64 << "\n";
					break;
				case Type::type_f32:
					std::cout << "\n\tType: f32 Value: " << stack[stk_ptr].types.f32 << "\n";
					break;
				case Type::type_f64:
					std::cout << "\n\tType: f64 Value: " << stack[stk_ptr].types.f64 << "\n";
					break;
				default:
					std::cout << "Unknown type: Address: 0x" << &stack[stk_ptr].types.u64 << "\n";
					break;
				}
			switch (*it)
			{
			case HALT: state = HALTED; break;
			case RESTART: std::cerr << "[KERNEL] RESTARTING VM\n"; restart(); break;
			case PUSHI8: pushi8(0x00); break;
			case PUSHU8: pushu8(0x00); break;
			case PUSHI16: pushi16(0x00); break;
			case PUSHU16: pushu16(0x00); break;
			case PUSHI32:
				buff[0].types.i32 = *++it;
				buff[0].types.i32 <<= 8;
				buff[0].types.i32 += *++it;
				buff[0].types.i32 <<= 8;
				buff[0].types.i32 += *++it;
				buff[0].types.i32 <<= 8;
				buff[0].types.i32 += *++it;
				pushi32(buff[0].types.i32);
				//std::cout << top().types.i32 << "\n"; break;
			case PUSHU32: 
				buff[0].types.u32 = *++it;
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += *++it;
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += *++it;
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += *++it;
				pushu32(buff[0].types.u32);
				//std::cout << top().types.u32 << "\n"; break;
			case PUSHI64: pushi64(0x00); break;
			case PUSHU64: pushu64(0x00); break;
			// TODO: Move the modifiers (ADD, SUB, etc) into their own file.
			case ADD:
				type = stack[stk_ptr].curr_type;
				buff[0] = top();
				pop();
				buff[1] = top();
				pop();
				buff[0].types.i64 = buff[0].types.u64 + buff[1].types.u64;
				pushObj(buff[0]);
				top().curr_type = type;
			break;
			case SUB:
				type = stack[stk_ptr].curr_type;
				buff[0] = top();
				pop();
				buff[1] = top();
				pop();
				buff[0].types.u64 = buff[0].types.u64 - buff[1].types.u64;
				pushObj(buff[0]);
				top().curr_type = type;
				break;
			case MUL:
				type = stack[stk_ptr].curr_type;
				buff[0] = top();
				pop();
				buff[1] = top();
				pop();
				buff[0].types.u64 = buff[0].types.u64 * buff[1].types.u64;
				pushObj(buff[0]);
				top().curr_type = type;
				break;
			case DIV:
				type = stack[stk_ptr].curr_type;
				buff[0] = top();
				pop();
				buff[1] = top();
				pop();
				buff[0].types.u64 = buff[0].types.u64 + buff[1].types.u64;
				pushObj(buff[0]);
				top().curr_type = type;
				break;
			case PRINT:

				break;
			case PRINTC:

				break;
			}
		}
	if (state = RUNNING)
	{
		std::cerr << "[KERNEL] UNEXPECTED END UP ROM REACHED\n";
		std::exit(-1);
	}
	if (state == RESTARTING)
		run();
	return false;
}
