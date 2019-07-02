#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

int main () {
	std::string s;
	std::getline(std::cin, s);

	auto it = std::begin(s);
	bool match = qi::phrase_parse(
		it,
		std::end(s),
		ascii::digit >> ascii::digit,
		ascii::space
	);

	std::cout << std::boolalpha << match << std::endl;
	if (it != s.end()) {
		std::cout << std::string{it, s.end()};
	}

	return 0;
}