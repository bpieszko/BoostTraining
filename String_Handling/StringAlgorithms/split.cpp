#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ Libraries"};

	std::vector<std::string> v;
	split(v, s, is_space());

	std::cout << v.size() << std::endl;
	for (const auto & i : v) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	return 0;
}