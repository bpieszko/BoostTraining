#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"--Boost C++ Libraries--"};

	std::cout << trim_left_copy_if(s, is_any_of("-")) << std::endl;
	std::cout << trim_right_copy_if(s, is_any_of("-")) << std::endl;
	std::cout << trim_copy_if(s, is_any_of("-")) << std::endl;

	//is_digit
	//is_upper
	//is_lower

	return 0;
}