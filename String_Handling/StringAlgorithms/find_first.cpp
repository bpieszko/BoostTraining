#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ Libraries"};

	boost::iterator_range<std::string::iterator> r = find_first(s, "C++");
	std::cout << r << std::endl;

	r = find_first(s, "xyz");
	std::cout << r << std::endl;

	if (r.empty()) {
		std::cout << "empty" << std::endl;
	}

	// find_last
	// find_head
	// find_tail
	// find_nth
	
	return 0;
}