#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::vector<std::string> v{"Boost", "C++", "Libraries"};
	std::cout << join(v, " ") << std::endl;
}