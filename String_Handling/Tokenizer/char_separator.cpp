#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main () {
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	std::string s{"Boost C++ Libraries"};
	boost::char_separator<char> sep{" "};
	tokenizer tok{s, sep};

	for (auto & i : tok) {
		std::cout << i << std::endl;
	}

	return 0;
}