#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

int main () {
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	int i;
	if (qi::phrase_parse(it, s.end(), qi::int_, ascii::space, i)) {
		std::cout << i << std::endl;
	}
	return 0;
}