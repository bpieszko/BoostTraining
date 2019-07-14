#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main () {
	path p1{"/home"};
	path p2{"/home/bpieszko/Desktop"};
	path p3{L"/home/bpieszko/Boost C++ \u5E93"};

	path p{"/"};
	std::cout << p.string() << std::endl;
	std::cout << p.generic_string() << std::endl;
}