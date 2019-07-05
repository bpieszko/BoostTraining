#include <iostream>
#include <string>
#include <algorithm>
#include <boost/array.hpp>

int main () {
	boost::array<std::string, 3> a;

	a[0] = "cat";
	a.at(1) = "shark";
	*a.rbegin() = "spider";

	std::sort(a.begin(), a.end());

	for (const std::string& s : a) {
		std::cout << s << std::endl;
	}

	std::cout << a.size() << std::endl;
	std::cout << a.max_size() << std::endl;

	return 0;
}