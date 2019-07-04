#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

int main () {
	std::string s = boost::lexical_cast<std::string>(123);
	std::cout << s << std::endl;

	double d = boost::lexical_cast<double>(s);
	std::cout << d << std::endl;
}