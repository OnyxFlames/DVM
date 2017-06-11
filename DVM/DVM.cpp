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
	if (allocated)
	{
		allocated = false;
		//std::clog << "Deallocating\n\n";
		delete[] stack;
	}
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
		for (; pc <= ROM.size(); pc++)
		{
			//std::clog << "PC: " << pc << " ROM SIZE: " << ROM.size() << "\n";
			if (state == HALTED)
			{
				//std::clog << "Deleting " << (sizeof(Object) * ALLOC_SIZE) / 8 << " bytes.\n"; 
				std::cout << "[HALTING]\n";
				DebugUtils::debug_wait();
				std::exit(1);
			}
			// Break out of both loops
			if (state == RESTARTING)
				break;
			Object buff[2];
			buff[0].types.u64 = 0x00;
			buff[1].types.u64 = 0x00;
			Type type;

			DebugUtils::list_stack_top(stack, stk_ptr);

			switch (ROM[pc])
			{
			case HALT: state = HALTED; break;
			case RESTART: std::cerr << "[KERNEL] RESTARTING VM\n"; restart(); break;
			case PUSHI8: pushi8(0x00); break;
			case PUSHU8: pushu8(0x00); break;
			case PUSHI16: pushi16(0x00); break;
			case PUSHU16: pushu16(0x00); break;
			case PUSHI32:
				buff[0].types.i32 = ROM[++pc];
				buff[0].types.i32 <<= 8;
				buff[0].types.i32 += ROM[++pc];
				buff[0].types.i32 <<= 8;
				buff[0].types.i32 += ROM[++pc];
				buff[0].types.i32 <<= 8;
				buff[0].types.i32 += ROM[++pc];
				pushi32(buff[0].types.i32);
				//std::cout << top().types.i32 << "\n"; break;
			case PUSHU32: 
				buff[0].types.u32 = ROM[++pc];
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += ROM[++pc];
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += ROM[++pc];
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += ROM[++pc];
				pushu32(buff[0].types.u32);
				//std::cout << top().types.u32 << "\n"; break;
			case PUSHI64: pushi64(0x01); break;
			case PUSHU64: pushu64(0x01); break;
			// TODO: Move the modifiers (ADD, SUB, etc) into their own file.
			case ADD:
				type = stack[stk_ptr].curr_type;
				buff[0] = top();
				pop();
				buff[1] = top();
				pop();
				buff[0].types.u64 = buff[0].types.u64 + buff[1].types.u64;
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
