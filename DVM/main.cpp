#include <iostream>
#include <fstream>
#include <array>

#include "argument_handler.hpp"

#include "Dvm.hpp"

using std::ios;

// List of instances of the DVM, the -i argument will add new instances to run in sequence(eventually parallel once threading is implemented)
unsigned char instance_count = 1;
std::vector<std::string> roms_to_load;
int main(int argc, char* argv[])
{
	handle_args(argc, argv);

	std::vector<DVM> instances;
	// Tests
	// Initial (testing) instance.
	
	instances.emplace_back(DVM());
	for (auto &inst : instances)
		inst.run();
	getchar();

	return 0;
}