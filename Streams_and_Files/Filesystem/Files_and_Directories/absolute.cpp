#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main() {
	try {
		std::cout << absolute("space.cpp") << std::endl;
	}
	catch (filesystem_error& e) {
		std::cerr << e.what() << std::endl;
	}
}