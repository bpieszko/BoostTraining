#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main () {
	std::string s{"Boost Libraries"};
	boost::regex expr{"\\w+\\s\\w+"};
	std::cout << std::boolalpha << boost::regex_match(s, expr) << std::endl;
	return 0;
}