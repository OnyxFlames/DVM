#include "argument_handler.hpp"

#include <iostream>
#include <cstring>
#include <vector>
#include "DVM.hpp"

extern unsigned char instance_count;
extern std::vector<std::string> roms_to_load;

void handle_args(int _argc, char* _argv[] )
{
	using std::strcmp;
	if (_argc == 1)
	{
#ifdef DEBUG
		// Debug mode
		return;
#elif
		print_help(_argv[0]);
		return;
#endif
	}
	for (int i = 0; i < _argc; i++)
	{
		if (strcmp("-h", _argv[i]) == 0 || strcmp("--help", _argv[i]) == 0)
		{
			print_help(_argv[0]);
			return;
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
				roms_to_load.push_back(_argv[++i]);
			}
		}
		if (strcmp("-v", _argv[i]) == 0 || strcmp("--version", _argv[i]) == 0)
		{
			std::cout << "Version:\t" << VERSION_MAJOR << "." << VERSION_MINOR << " " << VERSION_SUFFIX << "\n";
			std::cout << "Compiled:\t" << __DATE__ << " at " << __TIME__ << "\n";
			std::exit(0);
		}
	}
}

void print_help(const char* prog_name)
{
	std::cout << "Usage: " << prog_name << " <args>\n";
}