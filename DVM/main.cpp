#include <iostream>
#include <fstream>
#include <array>

#include "argument_handler.hpp"

#include "Dvm.hpp"

using std::ios;

// List of instances of the DVM, the -i argument will add new instances to run in sequence(eventually parallel once threading is implemented)
std::vector<DVM> instances;
int main(int argc, char* argv[])
{
	handle_args(argc, argv);


	// Tests
	// Initial (testing) instance.
	instances.emplace_back(DVM());
	for (auto &inst : instances)
		inst.run();
	getchar();

	return 0;
}