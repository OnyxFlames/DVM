#include <iostream>
#include <fstream>
#include <array>

#include "argument_handler.hpp"

#include "Dvm.hpp"

using std::ios;

int main(int argc, char* argv[])
{
	//handle_args(argc, argv);


	// Tests
	DVM dvm;

	std::cout << (char)dvm.pushstr("12345678910")->u8;
	
	getchar();

	return 0;
}