#include "DVM.hpp"

#include "StackOverFlowException.hpp"

#include "opcodes.hpp"

#define ALLOC_SIZE 2000u
static int ALLOC_SIZE_MODIFIED = ALLOC_SIZE;

DVM::DVM()
{
	// Default 16 kilobytes
	std::clog << "Allocating " << (sizeof(Object) * ALLOC_SIZE) / 8 << " bytes.\n";
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

				std::clog << "Deleting " << (sizeof(Object) * ALLOC_SIZE) / 8 << " bytes.\n"; 
				delete[] stack;
				std::exit(1);
			}
			// Break out of both loops
			if (state == RESTARTING)
				break;
			Object buff[2];
			Type type;
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
				std::cout << top().types.i32 << "\n"; break;
			case PUSHU32: 
				buff[0].types.u32 = *++it;
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += *++it;
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += *++it;
				buff[0].types.u32 <<= 8;
				buff[0].types.u32 += *++it;
				pushu32(buff[0].types.u32);
				std::cout << top().types.u32 << "\n"; break;
			case PUSHI64: pushi64(0x00); break;
			case PUSHU64: pushu64(0x00); break;
			// TODO: Move the modifiers (ADD, SUb, etc) into their own file.
			case ADD:
				//Object buff[2];
				//Type type;
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
				//Object buff[2];
				//Type type;
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
				//Object buff[2];
				//Type type;
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
				//Object buff[2];
				//Type type;
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

Object* DVM::pushi8(const int8_t &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i8 = val; 
	return &stack[stk_ptr]; 
}
Object* DVM::pushu8(const uint8_t &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u8 = val;
	return &stack[stk_ptr]; 
}
Object* DVM::pushi16(const int16_t &val) {
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i16 = val;
	return &stack[stk_ptr]; 
}
Object* DVM::pushu16(const uint16_t &val)
{ 
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u16 = val;
	return &stack[stk_ptr]; 
}
Object* DVM::pushi32(const int32_t &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i32 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushu32(const uint32_t &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u32 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushi64(const int64_t &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.i64 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushu64(const uint64_t &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.u64 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushf32(const float &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.f32 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushf64(const double &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr].types.f64 = val;
	return &stack[stk_ptr];
}
Object* DVM::pushstr(const std::string &val)
{
	int i = 0;
	for (i = ++stk_ptr; i < (stk_ptr + val.length()); ++i)
	{
		stack[i].types.u8 = val[(i - stk_ptr)];
	}
	stk_ptr = i-1;
	// In this case, return the start of the array.
	return &stack[stk_ptr - val.size() + 1];
}
Object* DVM::pushObj(const Object &val)
{
	if (stk_ptr + 1 > ALLOC_SIZE_MODIFIED)
		throw StackOverFlowException("Stack tried to allocate more space than available!\n");
	stack[++stk_ptr] = val;
	return &stack[stk_ptr];
}