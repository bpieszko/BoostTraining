#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main () {
	path p{"/home/bpieszko/Desktop"};
	try {
		file_status s = status(p);
		std::cout << std::boolalpha << is_directory(s) << std::endl;
	}
	catch (filesystem_error& e) {
		std::cerr << e.what() << std::endl;
	}

}