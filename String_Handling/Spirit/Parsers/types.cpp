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
		qi::int_,
		ascii::space
	);

/*
	qi::float_
	qi::double_
	qi::bool_
	qi::eol
	qi::byte_
	qi::word
	qi::little_word
	qi::big_word
*/

	std::cout << std::boolalpha << match << std::endl;

	return 0;
}
