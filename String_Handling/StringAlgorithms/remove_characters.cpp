#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ Libraries"};

	std::cout << erase_first_copy(s, "s") << std::endl;
	std::cout << erase_nth_copy(s, "s", 1) << std::endl;
	std::cout << erase_last_copy(s, "r") << std::endl;
	std::cout << erase_last_copy(s, "s") << std::endl;
	std::cout << erase_head_copy(s, 5) << std::endl;
	std::cout << erase_tail_copy(s, 9) << std::endl;

	return 0;
}