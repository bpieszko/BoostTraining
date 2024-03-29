#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main () {
	path p{"/home/bpieszko/Desktop"};
	
	std::cout << p.root_name() << std::endl;
	std::cout << p.root_directory() << std::endl;
	std::cout << p.root_path() << std::endl;
	std::cout << p.relative_path() << std::endl;
	std::cout << p.parent_path() << std::endl;
	std::cout << p.filename() << std::endl;

	return 0;
}