#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

int main () {
	try {
		int i = boost::lexical_cast<int>("abc");
		std::cout << i << std::endl;
	} catch (const boost::bad_lexical_cast& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}