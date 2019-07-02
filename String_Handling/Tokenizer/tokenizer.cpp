#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main () {
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	std::string s{"Boost C++ Libraries"};
	tokenizer tok{s};
	for (auto & i : tok) {
		std::cout << i << std::endl;
	}
	return 0;
}