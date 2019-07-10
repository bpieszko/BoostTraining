#include <iostream>
#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>

using namespace boost::logic;

int main () {
	std::cout.setf(std::ios::boolalpha);

	tribool b1 = true;
	std::cout << (b1 || indeterminate) << std::endl;
	std::cout << (b1 && indeterminate) << std::endl;

	tribool b2 = false;
	std::cout << (b2 || indeterminate) << std::endl;
	std::cout << (b2 && indeterminate) << std::endl;

	tribool b3 = indeterminate;

	std::cout << (b3 || b3) << '\n';
	std::cout << (b3 && b3) << '\n';

	return 0;
}