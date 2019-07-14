#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main () {
	path p{"photo.jpg"};
	std::cout << p.stem() << std::endl;
	std::cout << p.extension() << std::endl;
}