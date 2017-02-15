#include "argument_handler.hpp"

#include <iostream>
#include <cstring>



void handle_args(int _argc, char* _argv[] )
{
	if (_argc == 1)
	{
		print_help(_argv[0]);
		return;
	}
	for (int i = 0; i < _argc; i++)
	{
		if (strcmp("-help", _argv[i]) == 0)
		{
			print_help(_argv[0]);
		}
	}
}

void print_help(const char* prog_name)
{
	std::cout << "Usage: " << prog_name << " <args>\n";
}