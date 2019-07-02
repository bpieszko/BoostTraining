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
		qi::int_[([](int i){ std::cout << i << std::endl; })],
		ascii::space
	);

	std::cout << std::boolalpha << match << std::endl;

	return 0;
}