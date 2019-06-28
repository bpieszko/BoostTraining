#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main () {
	std::string s{" Boost Libraries "};
	boost::regex expr("\\s");
	std::string fmt{"_"};
	std::cout << boost::regex_replace(s, expr, fmt) << std::endl;
}