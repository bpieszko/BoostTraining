#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main () {
	typedef boost::tokenizer<
		boost::offset_separator
	> tokenizer;

	std::string s{"Boost C++ Libraries"};
	std::vector<int> v{5, 5, 9};
	boost::offset_separator sep(v.begin(), v.end());
	tokenizer tok{s, sep};

	for (const auto& i : tok) {
		std::cout << i << std::endl;
	}

	return 0;
}