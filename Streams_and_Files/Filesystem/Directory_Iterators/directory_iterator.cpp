#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main() {
	path p = current_path();
	directory_iterator it{p};
	while (it != directory_iterator{})
		std::cout << *it++ << std::endl;

	return 0;
}