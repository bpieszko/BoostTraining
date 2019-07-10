#include <iostream>
#include <boost/logic/tribool.hpp>

using namespace boost::logic;

int main () {
	tribool b;
	std::cout << std::boolalpha << b << std::endl;

	b = true;
	b = false;
	b = indeterminate;

	if (b)
		;
	else if (!b)
		;
	else
		std::cout << "indeterminate" << std::endl;


}