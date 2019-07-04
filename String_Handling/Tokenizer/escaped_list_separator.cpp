#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

	
int main () {
	typedef boost::tokenizer <
		boost::escaped_list_separator<char>
	> tokenizer;

	std::string s{"Boost,\"C++ Libraries\""};
	tokenizer tok{s};
	for (const auto& i : tok) {
		std::cout << i << std::endl;
	}
	return 0;
}