#include <iostream>
#include <boost/format.hpp>

int main () {
	std::cout << boost::format{"%1%.%2%.%3%"} % 12 % 5 % 2014 << std::endl;
	return 0;
}