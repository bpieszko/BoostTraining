#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main() {
	try {
		std::cout << current_path() << std::endl;
		current_path("/home/bpieszko/Desktop");
		std::cout << current_path() << std::endl;
	}
	catch (filesystem_error& e) {
		std::cerr << e.what() << std::endl;
	}
}