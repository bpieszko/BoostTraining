#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>

using namespace boost::algorithm;

int main () {
	std::string s{"Boost C++ Libraries"};

	boost::iterator_range<std::string::iterator> r =
		find_regex(s, boost::regex{"\\w\\+\\+"});

	std::cout << r << std::endl;

	return 0;
}