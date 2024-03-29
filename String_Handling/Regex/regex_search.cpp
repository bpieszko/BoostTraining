#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main ()  {
	std::string s{"Boost Libraries"};
	boost::regex expr{"(\\w+)\\s(\\w+)"};
	boost::smatch what;

	if (boost::regex_search(s, what, expr)) {
		std::cout << what[0] << std::endl;
		std::cout << what[1] << "_" << what[2] << std::endl;
	}

	return 0;
}