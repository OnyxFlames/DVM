#include "argument_handler.hpp"

#include <iostream>
#include <cstring>
#include <vector>
#include "DVM.hpp"

extern std::vector<DVM> instances;

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
		if (strcmp("-i", _argv[i]) == 0)
		{
			if (_argc == i)
			{
				std::cerr << "[Error] -i requires a ROM file argument to follow\n";
				std::exit(-1);
			}
			else 
			{
				DVM temp;
				temp.loadROM(_argv[++i]);
				instances.push_back(temp);
			}
		}
	}
}

void print_help(const char* prog_name)
{
	std::cout << "Usage: " << prog_name << " <args>\n";
}