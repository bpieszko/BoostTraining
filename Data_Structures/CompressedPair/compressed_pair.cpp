#include <iostream>
#include <utility>
#include <boost/compressed_pair.hpp>

struct empty {};

int main () {
	std::pair<int, empty> p;
	std::cout << sizeof(p) << std::endl;

	boost::compressed_pair<int, empty> cp;
	std::cout << sizeof(cp) << std::endl;
	
	return 0;
}