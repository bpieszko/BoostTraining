#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

int main () {
	std::string s;
	std::getline(std::cin, s);

	auto it = s.begin();
	bool match = qi::phrase_parse(
		it,
		s.end(),
		qi::lexeme[ascii::digit >> ascii::digit],
		ascii::space
	);

	std::cout << std::boolalpha << match << std::endl;

	return 0;
}