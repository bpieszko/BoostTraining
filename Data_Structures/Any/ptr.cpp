#include <iostream>
#include <boost/any.hpp>

int main () {
	boost::any a = 1;
	int* i = boost::any_cast<int>(&a);
	std::cout << *i << std::endl;
	return 0;
}