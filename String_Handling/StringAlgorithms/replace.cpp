#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ Libraries"};
	
	std::cout << replace_first_copy(s, "+", "-") << std::endl;
	std::cout << replace_last_copy(s, "+", "-") << std::endl;
	std::cout << replace_nth_copy(s, "+", 0, "-") << std::endl;
	std::cout << replace_all_copy(s, "+", "-") << std::endl;
	std::cout << replace_head_copy(s, 5, "BOOST") << std::endl;
	std::cout << replace_tail_copy(s, 9, "LIBRARIES") << std::endl;

	return 0;
}