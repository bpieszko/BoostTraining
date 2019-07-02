#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

int main () {
	std::string s;
	std::getline(std::cin, s);
	
	auto it = s.begin();
	bool match = qi::parse(it, s.end(), ascii::digit);

	std::cout << std::boolalpha << match << std::endl;

	if (it != s.end()) {
		std::cout << std::string{it, s.end()} << std::endl;
	}
	
	
	return 0;
}