#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ Libraries"};

	std::cout.setf(std::ios::boolalpha);

	std::cout << starts_with(s, "Boost") << std::endl;
	std::cout << ends_with(s, "libraries") << std::endl;
	std::cout << contains(s, "C++") << std::endl;
	std::cout << lexicographical_compare(s, "Boost") << std::endl;

	return 0;
}