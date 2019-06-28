#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"\t Boost C++ Libraries \t"};

	std::cout << "_" << trim_left_copy(s) << "_\n";
	std::cout << "_" << trim_right_copy(s) << "_\n";
	std::cout << "_" << trim_copy(s) << "_\n";
	
	return 0;
}